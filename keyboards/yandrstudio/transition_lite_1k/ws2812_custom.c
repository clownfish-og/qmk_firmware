// Custom WS2812 driver for dual RGB subsystems
// Matrix LEDs (RGB_MATRIX) on pin B13 using TIM1_CH1N, DMA1_STREAM5
// Underglow LEDs (RGBLIGHT) on pin A2 using TIM2_CH3, DMA1_STREAM2

#include "ws2812.h"
#include "rgblight/rgblight_drivers.h"
#include "gpio.h"
#include "chibios_config.h"
#include "hal.h"

// Configuration constants based on original WS2812 PWM driver
#define WS2812_CHANNELS 3                   // RGB (no RGBW)
#define WS2812_TIMING 1250                  // 1.25us period
#define WS2812_T1H 900                      // High time for '1' bit
#define WS2812_T0H 350                      // High time for '0' bit
#define WS2812_TRST_US 280                  // Reset time

// Matrix LED configuration (90 LEDs on TIM1)
#define MATRIX_LED_COUNT 90
#define MATRIX_COLOR_BITS (MATRIX_LED_COUNT * WS2812_CHANNELS * 8)
#define MATRIX_RESET_BITS (1000 * WS2812_TRST_US / WS2812_TIMING)
#define MATRIX_TOTAL_BITS (MATRIX_COLOR_BITS + MATRIX_RESET_BITS)

// Underglow LED configuration (26 LEDs on TIM2)
#define UNDERGLOW_LED_COUNT 26
#define UNDERGLOW_COLOR_BITS (UNDERGLOW_LED_COUNT * WS2812_CHANNELS * 8)
#define UNDERGLOW_RESET_BITS (1000 * WS2812_TRST_US / WS2812_TIMING)
#define UNDERGLOW_TOTAL_BITS (UNDERGLOW_COLOR_BITS + UNDERGLOW_RESET_BITS)

// PWM timing calculations (assuming 72MHz system clock)
#define WS2812_PWM_TICK_FREQUENCY (72000000 / 2)        // 36MHz
#define WS2812_PWM_PERIOD (WS2812_PWM_TICK_FREQUENCY / (1000000000 / WS2812_TIMING))  // Period for 800kHz
#define WS2812_DUTYCYCLE_0 (WS2812_PWM_TICK_FREQUENCY / (1000000000 / WS2812_T0H))   // Duty cycle for '0'
#define WS2812_DUTYCYCLE_1 (WS2812_PWM_TICK_FREQUENCY / (1000000000 / WS2812_T1H))   // Duty cycle for '1'

// Global LED buffer array (90 matrix + 26 underglow)
ws2812_led_t ws2812_leds[116];

// Frame buffers for PWM DMA
static uint16_t matrix_frame_buffer[MATRIX_TOTAL_BITS];
static uint16_t underglow_frame_buffer[UNDERGLOW_TOTAL_BITS];

// Matrix bit calculation macros (GRB order)
#define MATRIX_BIT(led, byte, bit) (WS2812_CHANNELS * 8 * (led) + 8 * (byte) + (7 - (bit)))
#define MATRIX_GREEN_BIT(led, bit) MATRIX_BIT((led), 0, (bit))
#define MATRIX_RED_BIT(led, bit)   MATRIX_BIT((led), 1, (bit))
#define MATRIX_BLUE_BIT(led, bit)  MATRIX_BIT((led), 2, (bit))

// Underglow bit calculation macros (GRB order)
#define UNDERGLOW_BIT(led, byte, bit) (WS2812_CHANNELS * 8 * (led) + 8 * (byte) + (7 - (bit)))
#define UNDERGLOW_GREEN_BIT(led, bit) UNDERGLOW_BIT((led), 0, (bit))
#define UNDERGLOW_RED_BIT(led, bit)   UNDERGLOW_BIT((led), 1, (bit))
#define UNDERGLOW_BLUE_BIT(led, bit)  UNDERGLOW_BIT((led), 2, (bit))

// Initialization function for WS2812 driver
void ws2812_init(void) {
    // Initialize matrix frame buffer (TIM1)
    uint32_t i;
    for (i = 0; i < MATRIX_COLOR_BITS; i++)
        matrix_frame_buffer[i] = WS2812_DUTYCYCLE_0;    // All color bits start as '0'
    for (i = 0; i < MATRIX_RESET_BITS; i++)
        matrix_frame_buffer[i + MATRIX_COLOR_BITS] = 0; // Reset bits are zero

    // Initialize underglow frame buffer (TIM2)
    for (i = 0; i < UNDERGLOW_COLOR_BITS; i++)
        underglow_frame_buffer[i] = WS2812_DUTYCYCLE_0;    // All color bits start as '0'
    for (i = 0; i < UNDERGLOW_RESET_BITS; i++)
        underglow_frame_buffer[i + UNDERGLOW_COLOR_BITS] = 0; // Reset bits are zero

    // Configure pins for PWM alternate functions
    // B13 for TIM1_CH1N (complementary output) - RGB Matrix
    palSetPadMode(GPIOB, 13, PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    // A2 for TIM2_CH3 - RGBLIGHT
    palSetPadMode(GPIOA, 2, PAL_MODE_STM32_ALTERNATE_PUSHPULL);

    // PWM Configuration for Matrix LEDs (TIM1_CH1N on B13)
    static const PWMConfig matrix_pwm_config = {
        .frequency = WS2812_PWM_TICK_FREQUENCY,
        .period    = WS2812_PWM_PERIOD,
        .callback  = NULL,
        .channels = {
            [0] = {.mode = PWM_COMPLEMENTARY_OUTPUT_ACTIVE_HIGH, .callback = NULL}, // CH1N for B13
            [1] = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
            [2] = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
            [3] = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL}
        },
        .cr2  = 0,
        .dier = TIM_DIER_UDE, // DMA on update event
    };

    // PWM Configuration for Underglow LEDs (TIM2_CH3 on A2)
    static const PWMConfig underglow_pwm_config = {
        .frequency = WS2812_PWM_TICK_FREQUENCY,
        .period    = WS2812_PWM_PERIOD,
        .callback  = NULL,
        .channels = {
            [0] = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
            [1] = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
            [2] = {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL}, // CH3 for A2
            [3] = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL}
        },
        .cr2  = 0,
        .dier = TIM_DIER_UDE, // DMA on update event
    };

    // Start PWM drivers
    pwmStart(&PWMD1, &matrix_pwm_config);
    pwmStart(&PWMD2, &underglow_pwm_config);

    // TODO: Configure DMA streams (requires DMA driver to be enabled)
    // For now, use basic PWM without DMA to get the foundation working

    // Clear LED buffer
    for (int i = 0; i < 116; i++) {
        ws2812_leds[i].r = 0;
        ws2812_leds[i].g = 0;
        ws2812_leds[i].b = 0;
    }
}

// Set color for a specific LED
void ws2812_set_color(int index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= 0 && index < 116) {
        ws2812_leds[index].r = red;
        ws2812_leds[index].g = green;
        ws2812_leds[index].b = blue;
    }
}

// Set all LEDs to the same color
void ws2812_set_color_all(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < 116; i++) {
        ws2812_set_color(i, red, green, blue);
    }
}

// Helper function to write LED data to matrix frame buffer
static void write_matrix_led(uint16_t led_number, uint8_t r, uint8_t g, uint8_t b) {
    // Write color to matrix frame buffer (GRB order)
    for (uint8_t bit = 0; bit < 8; bit++) {
        matrix_frame_buffer[MATRIX_GREEN_BIT(led_number, bit)] = ((g >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        matrix_frame_buffer[MATRIX_RED_BIT(led_number, bit)]   = ((r >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        matrix_frame_buffer[MATRIX_BLUE_BIT(led_number, bit)]  = ((b >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
    }
}

// Helper function to write LED data to underglow frame buffer
static void write_underglow_led(uint16_t led_number, uint8_t r, uint8_t g, uint8_t b) {
    // Write color to underglow frame buffer (GRB order)
    for (uint8_t bit = 0; bit < 8; bit++) {
        underglow_frame_buffer[UNDERGLOW_GREEN_BIT(led_number, bit)] = ((g >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        underglow_frame_buffer[UNDERGLOW_RED_BIT(led_number, bit)]   = ((r >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
        underglow_frame_buffer[UNDERGLOW_BLUE_BIT(led_number, bit)]  = ((b >> bit) & 0x01) ? WS2812_DUTYCYCLE_1 : WS2812_DUTYCYCLE_0;
    }
}

// Flush LED data to both chains
void ws2812_flush(void) {
    // Process matrix LEDs (indices 0-89) -> pin B13 via TIM1_CH1N
    for (int i = 0; i < MATRIX_LED_COUNT && i < 116; i++) {
        write_matrix_led(i, ws2812_leds[i].r, ws2812_leds[i].g, ws2812_leds[i].b);
    }

    // Process underglow LEDs (indices 90-115) -> pin A2 via TIM2_CH3
    for (int i = 0; i < UNDERGLOW_LED_COUNT && (i + MATRIX_LED_COUNT) < 116; i++) {
        int led_index = i + MATRIX_LED_COUNT;  // Offset by matrix LED count (90)
        write_underglow_led(i, ws2812_leds[led_index].r, ws2812_leds[led_index].g, ws2812_leds[led_index].b);
    }

    // Manual PWM transmission for matrix LEDs (TIM1_CH1N on B13)
    for (uint32_t bit = 0; bit < MATRIX_COLOR_BITS; bit++) {
        pwmEnableChannel(&PWMD1, 0, matrix_frame_buffer[bit]);
        // Small delay for bit timing - this is simplified, real implementation would use DMA
        chThdSleepMicroseconds(1); // Approximate WS2812 bit time
    }
    pwmDisableChannel(&PWMD1, 0); // End transmission

    // Manual PWM transmission for underglow LEDs (TIM2_CH3 on A2)
    for (uint32_t bit = 0; bit < UNDERGLOW_COLOR_BITS; bit++) {
        pwmEnableChannel(&PWMD2, 2, underglow_frame_buffer[bit]);
        // Small delay for bit timing - this is simplified, real implementation would use DMA
        chThdSleepMicroseconds(1); // Approximate WS2812 bit time
    }
    pwmDisableChannel(&PWMD2, 2); // End transmission

    // WS2812 reset time
    chThdSleepMicroseconds(WS2812_TRST_US);
}

// RGB light driver structure for RGBLIGHT subsystem
const rgblight_driver_t rgblight_driver = {
    .init          = ws2812_init,
    .set_color     = ws2812_set_color,
    .set_color_all = ws2812_set_color_all,
    .flush         = ws2812_flush,
};
