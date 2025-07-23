// Copyright 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

// Custom WS2812 driver for dual-pin LED control
// RGB Matrix: 90 LEDs on pin B13 (TIM1_CH1N)
// RGBLIGHT: 26 LEDs on pin A2 (TIM2_CH3)

#include "ws2812.h"
#include "rgblight/rgblight_drivers.h"
#include "quantum.h"
#include <string.h>
#include <stdbool.h>

// Use QMK's global WS2812 LED array for RGB matrix
// Declare it ourselves since the platform driver isn't included
ws2812_led_t ws2812_leds[WS2812_LED_COUNT];

// LED counts
#define MATRIX_LED_COUNT 91      // RGB matrix LEDs on B13
#define UNDERGLOW_LED_COUNT 26   // RGBLIGHT LEDs on A2

// LED buffers for both chains
static ws2812_led_t matrix_leds[MATRIX_LED_COUNT];
static ws2812_led_t underglow_leds[UNDERGLOW_LED_COUNT];

// Simple state tracking
static bool initialized = false;
static bool matrix_needs_update = false;
static bool underglow_needs_update = false;

// Simple WS2812 bit-bang implementation
static void send_ws2812_bit(pin_t pin, bool bit_value) {
    if (bit_value) {
        // Send '1' bit: ~800ns high, ~450ns low
        writePinHigh(pin);
        wait_us(1);  // ~1us high (close to 800ns)
        writePinLow(pin);
        // No delay for 450ns - the next instruction provides enough delay
    } else {
        // Send '0' bit: ~400ns high, ~850ns low
        writePinHigh(pin);
        // Minimal delay for ~400ns
        writePinLow(pin);
        wait_us(1);   // ~1us low (close to 850ns)
    }
}

static void send_ws2812_byte(pin_t pin, uint8_t byte) {
    // Send bits MSB first
    for (int i = 7; i >= 0; i--) {
        send_ws2812_bit(pin, (byte >> i) & 1);
    }
}

static void send_ws2812_led(pin_t pin, uint8_t r, uint8_t g, uint8_t b) {
    // WS2812 expects GRB order
    send_ws2812_byte(pin, g);
    send_ws2812_byte(pin, r);
    send_ws2812_byte(pin, b);
}

static void send_ws2812_reset(pin_t pin) {
    // Send reset signal: >280us low
    writePinLow(pin);
    wait_us(300);
}

// Initialize WS2812 driver - called by both RGB matrix and RGBLIGHT
void ws2812_init(void) {
    if (initialized) return;

    // Clear LED buffers
    memset(matrix_leds, 0, sizeof(matrix_leds));
    memset(underglow_leds, 0, sizeof(underglow_leds));
    memset(ws2812_leds, 0, sizeof(ws2812_leds));

    // Configure pins as outputs
    setPinOutput(B13);
    setPinOutput(A2);

    // Send initial reset
    send_ws2812_reset(B13);
    send_ws2812_reset(A2);

    initialized = true;
}

// Set color for a single LED - used by RGB matrix
void ws2812_set_color(int index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= 0 && index < MATRIX_LED_COUNT) {
        matrix_leds[index].r = red;
        matrix_leds[index].g = green;
        matrix_leds[index].b = blue;
        matrix_needs_update = true;

        // Also update the global QMK WS2812 array used by the platform driver
        if (index < WS2812_LED_COUNT) {
            ws2812_leds[index].r = red;
            ws2812_leds[index].g = green;
            ws2812_leds[index].b = blue;
        }
    }
}

// Set all LEDs to same color - used by RGB matrix
void ws2812_set_color_all(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < MATRIX_LED_COUNT; i++) {
        matrix_leds[i].r = red;
        matrix_leds[i].g = green;
        matrix_leds[i].b = blue;

        // Also update the global QMK WS2812 array
        if (i < WS2812_LED_COUNT) {
            ws2812_leds[i].r = red;
            ws2812_leds[i].g = green;
            ws2812_leds[i].b = blue;
        }
    }
    matrix_needs_update = true;
}

// Flush RGB matrix LEDs to hardware - used by RGB matrix
void ws2812_flush(void) {
    if (!matrix_needs_update) return;

    // Send all matrix LEDs via proper WS2812 protocol on pin B13
    // Disable interrupts for precise timing
    __disable_irq();
    for (int i = 0; i < MATRIX_LED_COUNT; i++) {
        send_ws2812_led(B13, matrix_leds[i].r, matrix_leds[i].g, matrix_leds[i].b);
    }
    send_ws2812_reset(B13); // Send reset to latch the data
    __enable_irq(); // Re-enable interrupts

    matrix_needs_update = false;
}

// RGBLIGHT driver functions

// Initialize custom RGBLIGHT driver
static void init_custom(void) {
    ws2812_init(); // Ensure WS2812 is initialized
}

// Set individual RGBLIGHT LED color
static void set_color_custom(int index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= 0 && index < UNDERGLOW_LED_COUNT) {
        underglow_leds[index].r = red;
        underglow_leds[index].g = green;
        underglow_leds[index].b = blue;
        underglow_needs_update = true;
    }
}

// Set all RGBLIGHT LEDs to same color
static void set_color_all_custom(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < UNDERGLOW_LED_COUNT; i++) {
        underglow_leds[i].r = red;
        underglow_leds[i].g = green;
        underglow_leds[i].b = blue;
    }
    underglow_needs_update = true;
}

// Flush RGBLIGHT LEDs to hardware
static void flush_custom(void) {
    if (!underglow_needs_update) return;

    // Send all underglow LEDs via proper WS2812 protocol on pin A2
    // Disable interrupts for precise timing
    __disable_irq();
    for (int i = 0; i < UNDERGLOW_LED_COUNT; i++) {
        send_ws2812_led(A2, underglow_leds[i].r, underglow_leds[i].g, underglow_leds[i].b);
    }
    send_ws2812_reset(A2); // Send reset to latch the data
    __enable_irq(); // Re-enable interrupts

    underglow_needs_update = false;
}

// RGBLIGHT driver structure for underglow LEDs
const rgblight_driver_t rgblight_driver = {
    .init          = init_custom,
    .set_color     = set_color_custom,
    .set_color_all = set_color_all_custom,
    .flush         = flush_custom,
};
