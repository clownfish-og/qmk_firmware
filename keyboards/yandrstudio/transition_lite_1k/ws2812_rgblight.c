// Copyright 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

// RGBLIGHT WS2812 PWM driver for pin A2 (TIM2_CH3)
// DMA-based PWM implementation for dual RGB setup
// STM32F103 specific configuration

#include "rgblight/rgblight_drivers.h"
#include "hal.h"
#include "ws2812.h"
#include "chibios_config.h"
#include "gpio.h"

// Calculate PWM frequency, tick frequency and period
#define RGBLIGHT_PWM_FREQUENCY (1000000000 / WS2812_TIMING)
#define RGBLIGHT_PWM_TICK_FREQUENCY (CPU_CLOCK / 2)
#define RGBLIGHT_PWM_PERIOD (RGBLIGHT_PWM_TICK_FREQUENCY / RGBLIGHT_PWM_FREQUENCY)

// Calculate duty cycles for 0 and 1 bits (following standard driver pattern)
#define RGBLIGHT_DUTYCYCLE_0 (RGBLIGHT_PWM_TICK_FREQUENCY / (1000000000 / WS2812_T0H))
#if (RGBLIGHT_DUTYCYCLE_0 > 255)
#    error RGBLIGHT PWM driver: High period for a 0 is more than a byte
#endif

#define RGBLIGHT_DUTYCYCLE_1 (RGBLIGHT_PWM_TICK_FREQUENCY / (1000000000 / WS2812_T1H))
#if (RGBLIGHT_DUTYCYCLE_1 > 255)
#    error RGBLIGHT PWM driver: High period for a 1 is more than a byte
#endif

// Frame buffer calculations
#define RGBLIGHT_CHANNELS 3  // RGB only for this keyboard
#define RGBLIGHT_COLOR_BITS (RGBLIGHT_CHANNELS * 8)
#define RGBLIGHT_RESET_BIT_N (1000 * WS2812_TRST_US / WS2812_TIMING)
#define RGBLIGHT_COLOR_BIT_N (RGBLIGHT_LED_COUNT * RGBLIGHT_COLOR_BITS)
#define RGBLIGHT_BIT_N (RGBLIGHT_COLOR_BIT_N + RGBLIGHT_RESET_BIT_N)

// STM32F1xx DMA configuration (byte memory, hword peripheral)
#define RGBLIGHT_PWM_DMA_MEMORY_WIDTH STM32_DMA_CR_MSIZE_BYTE
#define RGBLIGHT_PWM_DMA_PERIPHERAL_WIDTH STM32_DMA_CR_PSIZE_HWORD
typedef uint8_t rgblight_buffer_t;

// DMA frame buffer - each bit becomes a PWM duty cycle value
static rgblight_buffer_t rgblight_frame_buffer[RGBLIGHT_BIT_N];
static uint8_t rgblight_led_buffer[RGBLIGHT_LED_COUNT * 3];  // RGB only

// PWM configuration for TIM2_CH3 (from config.h values)
static PWMConfig rgblight_pwm_config = {
    .frequency = RGBLIGHT_PWM_TICK_FREQUENCY,
    .period    = RGBLIGHT_PWM_PERIOD,
    .callback  = NULL,
    .channels  = {
        {PWM_OUTPUT_DISABLED, NULL},      // Channel 1
        {PWM_OUTPUT_DISABLED, NULL},      // Channel 2
        {PWM_OUTPUT_ACTIVE_HIGH, NULL},   // Channel 3 (A2/TIM2_CH3)
        {PWM_OUTPUT_DISABLED, NULL}       // Channel 4
    },
    .cr2 = 0,
    .dier = TIM_DIER_UDE,  // Enable DMA on update
};

static void rgblight_build_frame_buffer(void) {
    uint32_t bit_index = 0;

    // Convert LED color data to PWM duty cycles
    for (int led = 0; led < RGBLIGHT_LED_COUNT; led++) {
        int led_offset = led * 3;
        uint8_t r = rgblight_led_buffer[led_offset];
        uint8_t g = rgblight_led_buffer[led_offset + 1];
        uint8_t b = rgblight_led_buffer[led_offset + 2];

        // WS2812 expects GRB order
        uint8_t colors[3] = {g, r, b};

        // Convert each color byte to 8 PWM duty cycle values
        for (int color = 0; color < 3; color++) {
            for (int bit = 7; bit >= 0; bit--) {
                if (bit_index < RGBLIGHT_BIT_N) {
                    rgblight_frame_buffer[bit_index++] =
                        (colors[color] & (1 << bit)) ? RGBLIGHT_DUTYCYCLE_1 : RGBLIGHT_DUTYCYCLE_0;
                }
            }
        }
    }

    // Add reset period (all zeros) for proper WS2812 reset timing
    while (bit_index < RGBLIGHT_BIT_N) {
        rgblight_frame_buffer[bit_index++] = 0;
    }
}

void ws2812_rgblight_init(void) {
    // Initialize LED buffer to all off
    for (int i = 0; i < RGBLIGHT_LED_COUNT * 3; i++) {
        rgblight_led_buffer[i] = 0;
    }

    // Build initial frame buffer (all LEDs off)
    rgblight_build_frame_buffer();

    // Configure pin A2 for TIM2_CH3 alternate function
    palSetLineMode(RGBLIGHT_DI_PIN, RGBLIGHT_OUTPUT_MODE);

    // Configure DMA using config.h values
    dmaStreamAlloc(RGBLIGHT_DMA_STREAM - STM32_DMA_STREAM(0), 10, NULL, NULL);
    dmaStreamSetPeripheral(RGBLIGHT_DMA_STREAM, &(RGBLIGHT_PWM_DRIVER.tim->CCR[RGBLIGHT_PWM_CHANNEL - 1]));
    dmaStreamSetMemory0(RGBLIGHT_DMA_STREAM, rgblight_frame_buffer);
    dmaStreamSetMode(RGBLIGHT_DMA_STREAM,
        STM32_DMA_CR_CHSEL(RGBLIGHT_DMA_CHANNEL) |
        STM32_DMA_CR_DIR_M2P |
        RGBLIGHT_PWM_DMA_PERIPHERAL_WIDTH |
        RGBLIGHT_PWM_DMA_MEMORY_WIDTH |
        STM32_DMA_CR_MINC |         // Memory increment
        STM32_DMA_CR_CIRC |         // Circular mode
        STM32_DMA_CR_PL(3));        // High priority

    dmaStreamSetTransactionSize(RGBLIGHT_DMA_STREAM, RGBLIGHT_BIT_N);

    // Start DMA before PWM (as per standard driver)
    dmaStreamEnable(RGBLIGHT_DMA_STREAM);

    // Configure and start PWM
    pwmStart(&RGBLIGHT_PWM_DRIVER, &rgblight_pwm_config);

    // Enable PWM channel with initial duty cycle 0
    pwmEnableChannel(&RGBLIGHT_PWM_DRIVER, RGBLIGHT_PWM_CHANNEL - 1, 0);
}

void ws2812_rgblight_set_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index >= RGBLIGHT_LED_COUNT) return;

    int buf_index = index * 3;
    rgblight_led_buffer[buf_index] = r;
    rgblight_led_buffer[buf_index + 1] = g;
    rgblight_led_buffer[buf_index + 2] = b;
}

void ws2812_rgblight_set_color_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < RGBLIGHT_LED_COUNT; i++) {
        ws2812_rgblight_set_color(i, r, g, b);
    }
}

void ws2812_rgblight_flush(void) {
    // Update frame buffer with current LED data
    rgblight_build_frame_buffer();
    // DMA circular mode will pick up changes automatically
}

// Export the RGBLIGHT driver
const rgblight_driver_t rgblight_driver = {
    .init          = ws2812_rgblight_init,
    .set_color     = ws2812_rgblight_set_color,
    .set_color_all = ws2812_rgblight_set_color_all,
    .flush         = ws2812_rgblight_flush,
};
