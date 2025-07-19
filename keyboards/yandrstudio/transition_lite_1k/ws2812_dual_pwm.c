#include "ws2812.h"
#include "gpio.h"
#include "chibios_config.h"

// Configuration for Matrix LEDs (B13)
#ifndef WS2812_MATRIX_PWM_DRIVER
#    define WS2812_MATRIX_PWM_DRIVER PWMD1  // TIM1
#endif
#ifndef WS2812_MATRIX_PWM_CHANNEL
#    define WS2812_MATRIX_PWM_CHANNEL 1
#endif
#ifndef WS2812_MATRIX_PWM_PAL_MODE
#    define WS2812_MATRIX_PWM_PAL_MODE 2
#endif
#ifndef WS2812_MATRIX_PWM_DMA_STREAM
#    define WS2812_MATRIX_PWM_DMA_STREAM STM32_DMA1_STREAM2
#endif
#ifndef WS2812_MATRIX_PWM_DMA_CHANNEL
#    define WS2812_MATRIX_PWM_DMA_CHANNEL 2
#endif
#ifndef WS2812_MATRIX_DI_PIN
#    define WS2812_MATRIX_DI_PIN B13
#endif

// Configuration for Underglow LEDs (A2)
#ifndef WS2812_UNDERGLOW_PWM_DRIVER
#    define WS2812_UNDERGLOW_PWM_DRIVER PWMD2  // TIM2
#endif
#ifndef WS2812_UNDERGLOW_PWM_CHANNEL
#    define WS2812_UNDERGLOW_PWM_CHANNEL 3
#endif
#ifndef WS2812_UNDERGLOW_PWM_PAL_MODE
#    define WS2812_UNDERGLOW_PWM_PAL_MODE 2
#endif
#ifndef WS2812_UNDERGLOW_PWM_DMA_STREAM
#    define WS2812_UNDERGLOW_PWM_DMA_STREAM STM32_DMA1_STREAM1
#endif
#ifndef WS2812_UNDERGLOW_PWM_DMA_CHANNEL
#    define WS2812_UNDERGLOW_PWM_DMA_CHANNEL 3
#endif
#ifndef WS2812_UNDERGLOW_DI_PIN
#    define WS2812_UNDERGLOW_DI_PIN A2
#endif

// LED counts
#ifndef RGB_MATRIX_LED_COUNT
#    define RGB_MATRIX_LED_COUNT 61
#endif
#ifndef RGBLIGHT_LED_COUNT
#    define RGBLIGHT_LED_COUNT 6
#endif

#ifdef WS2812_RGBW
#    define WS2812_CHANNELS 4
#else
#    define WS2812_CHANNELS 3
#endif

// Default is 800kHz
#ifndef WS2812_PWM_FREQUENCY
#    define WS2812_PWM_FREQUENCY 800000
#endif

// Timing constants
#define WS2812_PWM_TICK_FREQUENCY (CPU_CLOCK / 2)
#define WS2812_PWM_PERIOD (WS2812_PWM_TICK_FREQUENCY / WS2812_PWM_FREQUENCY)

#define WS2812_COLOR_BITS (WS2812_CHANNELS * 8)
#define WS2812_RESET_BIT_N (1000 * WS2812_TRST_US / WS2812_TIMING)

#define WS2812_MATRIX_COLOR_BIT_N (RGB_MATRIX_LED_COUNT * WS2812_COLOR_BITS)
#define WS2812_MATRIX_BIT_N (WS2812_MATRIX_COLOR_BIT_N + WS2812_RESET_BIT_N)

#define WS2812_UNDERGLOW_COLOR_BIT_N (RGBLIGHT_LED_COUNT * WS2812_COLOR_BITS)
#define WS2812_UNDERGLOW_BIT_N (WS2812_UNDERGLOW_COLOR_BIT_N + WS2812_RESET_BIT_N)

// Duty cycles for 0 and 1 bits
#define WS2812_DUTYCYCLE_0 (WS2812_PWM_TICK_FREQUENCY / (1000000000 / WS2812_T0H))
#define WS2812_DUTYCYCLE_1 (WS2812_PWM_TICK_FREQUENCY / (1000000000 / WS2812_T1H))

// Bit index calculation macros
#define WS2812_BIT(led, byte, bit) (WS2812_COLOR_BITS * (led) + 8 * (byte) + (7 - (bit)))

#if (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_GRB)
#    define WS2812_RED_BIT(led, bit) WS2812_BIT((led), 1, (bit))
#    define WS2812_GREEN_BIT(led, bit) WS2812_BIT((led), 0, (bit))
#    define WS2812_BLUE_BIT(led, bit) WS2812_BIT((led), 2, (bit))
#elif (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_RGB)
#    define WS2812_RED_BIT(led, bit) WS2812_BIT((led), 0, (bit))
#    define WS2812_GREEN_BIT(led, bit) WS2812_BIT((led), 1, (bit))
#    define WS2812_BLUE_BIT(led, bit) WS2812_BIT((led), 2, (bit))
#elif (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_BGR)
#    define WS2812_RED_BIT(led, bit) WS2812_BIT((led), 2, (bit))
#    define WS2812_GREEN_BIT(led, bit) WS2812_BIT((led), 1, (bit))
#    define WS2812_BLUE_BIT(led, bit) WS2812_BIT((led), 0, (bit))
#endif

#ifdef WS2812_RGBW
#    define WS2812_WHITE_BIT(led, bit) WS2812_BIT((led), 3, (bit))
#endif

// Buffer type for STM32F103 (16-bit timers)
typedef uint16_t ws2812_buffer_t;

// Frame buffers for each chain
static ws2812_buffer_t ws2812_matrix_frame_buffer[WS2812_MATRIX_BIT_N + 1];
static ws2812_buffer_t ws2812_underglow_frame_buffer[WS2812_UNDERGLOW_BIT_N + 1];

// LED storage
static ws2812_led_t ws2812_matrix_leds[RGB_MATRIX_LED_COUNT];
static ws2812_led_t ws2812_underglow_leds[RGBLIGHT_LED_COUNT];

// PWM configurations
static const PWMConfig ws2812_matrix_pwm_config = {
    .frequency = WS2812_PWM_TICK_FREQUENCY,
    .period    = WS2812_PWM_PERIOD,
    .callback  = NULL,
    .channels = {
        [0 ... 3] = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
        [WS2812_MATRIX_PWM_CHANNEL - 1] = {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL},
    },
    .cr2  = 0,
    .dier = TIM_DIER_UDE,
};

static const PWMConfig ws2812_underglow_pwm_config = {
    .frequency = WS2812_PWM_TICK_FREQUENCY,
    .period    = WS2812_PWM_PERIOD,
    .callback  = NULL,
    .channels = {
        [0 ... 3] = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
        [WS2812_UNDERGLOW_PWM_CHANNEL - 1] = {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL},
    },
    .cr2  = 0,
    .dier = TIM_DIER_UDE,
};

static void ws2812_init_buffer(ws2812_buffer_t* buffer, uint32_t color_bits, uint32_t reset_bits) {
    uint32_t i;
    for (i = 0; i < color_bits; i++) {
        buffer[i] = WS2812_DUTYCYCLE_0;
    }
    for (i = 0; i < reset_bits; i++) {
        buffer[i + color_bits] = 0;
    }
}

void ws2812_init(void) {
    // Initialize frame buffers
    ws2812_init_buffer(ws2812_matrix_frame_buffer, WS2812_MATRIX_COLOR_BIT_N, WS2812_RESET_BIT_N);
    ws2812_init_buffer(ws2812_underglow_frame_buffer, WS2812_UNDERGLOW_COLOR_BIT_N, WS2812_RESET_BIT_N);

    // Configure pins
    palSetLineMode(WS2812_MATRIX_DI_PIN, PAL_MODE_ALTERNATE_PUSHPULL);
    palSetLineMode(WS2812_UNDERGLOW_DI_PIN, PAL_MODE_ALTERNATE_PUSHPULL);

    // Configure DMA for matrix LEDs
    dmaStreamAlloc(WS2812_MATRIX_PWM_DMA_STREAM - STM32_DMA_STREAM(0), 10, NULL, NULL);
    dmaStreamSetPeripheral(WS2812_MATRIX_PWM_DMA_STREAM, &(WS2812_MATRIX_PWM_DRIVER.tim->CCR[WS2812_MATRIX_PWM_CHANNEL - 1]));
    dmaStreamSetMemory0(WS2812_MATRIX_PWM_DMA_STREAM, ws2812_matrix_frame_buffer);
    dmaStreamSetMode(WS2812_MATRIX_PWM_DMA_STREAM,
        STM32_DMA_CR_CHSEL(WS2812_MATRIX_PWM_DMA_CHANNEL) |
        STM32_DMA_CR_DIR_M2P |
        STM32_DMA_CR_PSIZE_HWORD |
        STM32_DMA_CR_MSIZE_HWORD |
        STM32_DMA_CR_MINC |
        STM32_DMA_CR_CIRC |
        STM32_DMA_CR_PL(3));
    dmaStreamSetTransactionSize(WS2812_MATRIX_PWM_DMA_STREAM, WS2812_MATRIX_BIT_N);

    // Configure DMA for underglow LEDs
    dmaStreamAlloc(WS2812_UNDERGLOW_PWM_DMA_STREAM - STM32_DMA_STREAM(0), 10, NULL, NULL);
    dmaStreamSetPeripheral(WS2812_UNDERGLOW_PWM_DMA_STREAM, &(WS2812_UNDERGLOW_PWM_DRIVER.tim->CCR[WS2812_UNDERGLOW_PWM_CHANNEL - 1]));
    dmaStreamSetMemory0(WS2812_UNDERGLOW_PWM_DMA_STREAM, ws2812_underglow_frame_buffer);
    dmaStreamSetMode(WS2812_UNDERGLOW_PWM_DMA_STREAM,
        STM32_DMA_CR_CHSEL(WS2812_UNDERGLOW_PWM_DMA_CHANNEL) |
        STM32_DMA_CR_DIR_M2P |
        STM32_DMA_CR_PSIZE_HWORD |
        STM32_DMA_CR_MSIZE_HWORD |
        STM32_DMA_CR_MINC |
        STM32_DMA_CR_CIRC |
        STM32_DMA_CR_PL(3));
    dmaStreamSetTransactionSize(WS2812_UNDERGLOW_PWM_DMA_STREAM, WS2812_UNDERGLOW_BIT_N);

    // Start DMA streams
    dmaStreamEnable(WS2812_MATRIX_PWM_DMA_STREAM);
    dmaStreamEnable(WS2812_UNDERGLOW_PWM_DMA_STREAM);

    // Start PWM drivers
    pwmStart(&WS2812_MATRIX_PWM_DRIVER, &ws2812_matrix_pwm_config);
    pwmEnableChannel(&WS2812_MATRIX_PWM_DRIVER, WS2812_MATRIX_PWM_CHANNEL - 1, 0);

    pwmStart(&WS2812_UNDERGLOW_PWM_DRIVER, &ws2812_underglow_pwm_config);
    pwmEnableChannel(&WS2812_UNDERGLOW_PWM_DRIVER, WS2812_UNDERGLOW_PWM_CHANNEL - 1, 0);
}

static void ws2812_write_led_to_buffer(ws2812_buffer_t* buffer, uint16_t led_number, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t bit = 0; bit < 8; bit++) {
        buffer[WS2812_RED_BIT(led_number, bit)]   = ((r >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        buffer[WS2812_GREEN_BIT(led_number, bit)] = ((g >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        buffer[WS2812_BLUE_BIT(led_number, bit)]  = ((b >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
    }
}

#ifdef WS2812_RGBW
static void ws2812_write_led_rgbw_to_buffer(ws2812_buffer_t* buffer, uint16_t led_number, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    for (uint8_t bit = 0; bit < 8; bit++) {
        buffer[WS2812_RED_BIT(led_number, bit)]   = ((r >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        buffer[WS2812_GREEN_BIT(led_number, bit)] = ((g >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        buffer[WS2812_BLUE_BIT(led_number, bit)]  = ((b >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        buffer[WS2812_WHITE_BIT(led_number, bit)] = ((w >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
    }
}
#endif

// Matrix LED functions
void ws2812_set_color(int index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index < RGB_MATRIX_LED_COUNT) {
        ws2812_matrix_leds[index].r = red;
        ws2812_matrix_leds[index].g = green;
        ws2812_matrix_leds[index].b = blue;
#if defined(WS2812_RGBW)
        ws2812_rgb_to_rgbw(&ws2812_matrix_leds[index]);
#endif
    }
}

void ws2812_set_color_all(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        ws2812_set_color(i, red, green, blue);
    }
}

// Underglow LED functions
void ws2812_underglow_set_color(int index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index < RGBLIGHT_LED_COUNT) {
        ws2812_underglow_leds[index].r = red;
        ws2812_underglow_leds[index].g = green;
        ws2812_underglow_leds[index].b = blue;
#if defined(WS2812_RGBW)
        ws2812_rgb_to_rgbw(&ws2812_underglow_leds[index]);
#endif
    }
}

void ws2812_underglow_set_color_all(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < RGBLIGHT_LED_COUNT; i++) {
        ws2812_underglow_set_color(i, red, green, blue);
    }
}

void ws2812_flush(void) {
    // Update matrix LEDs
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
#if defined(WS2812_RGBW)
        ws2812_write_led_rgbw_to_buffer(ws2812_matrix_frame_buffer, i,
            ws2812_matrix_leds[i].r, ws2812_matrix_leds[i].g,
            ws2812_matrix_leds[i].b, ws2812_matrix_leds[i].w);
#else
        ws2812_write_led_to_buffer(ws2812_matrix_frame_buffer, i,
            ws2812_matrix_leds[i].r, ws2812_matrix_leds[i].g, ws2812_matrix_leds[i].b);
#endif
    }

    // Update underglow LEDs
    for (int i = 0; i < RGBLIGHT_LED_COUNT; i++) {
#if defined(WS2812_RGBW)
        ws2812_write_led_rgbw_to_buffer(ws2812_underglow_frame_buffer, i,
            ws2812_underglow_leds[i].r, ws2812_underglow_leds[i].g,
            ws2812_underglow_leds[i].b, ws2812_underglow_leds[i].w);
#else
        ws2812_write_led_to_buffer(ws2812_underglow_frame_buffer, i,
            ws2812_underglow_leds[i].r, ws2812_underglow_leds[i].g, ws2812_underglow_leds[i].b);
#endif
    }
}

// Legacy compatibility functions
void ws2812_write_led(uint16_t led_number, uint8_t r, uint8_t g, uint8_t b) {
    ws2812_write_led_to_buffer(ws2812_matrix_frame_buffer, led_number, r, g, b);
}

void ws2812_write_led_rgbw(uint16_t led_number, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
#ifdef WS2812_RGBW
    ws2812_write_led_rgbw_to_buffer(ws2812_matrix_frame_buffer, led_number, r, g, b, w);
#else
    ws2812_write_led_to_buffer(ws2812_matrix_frame_buffer, led_number, r, g, b);
#endif
}

// Global LED array for compatibility
ws2812_led_t ws2812_leds[RGB_MATRIX_LED_COUNT];
