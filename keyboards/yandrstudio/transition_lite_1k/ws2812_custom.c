// Copyright 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

// Custom dual-pin WS2812 driver for transition_lite_1k
// RGB Matrix: Uses standard driver on pin B13 (91 LEDs)
// RGBLIGHT: Uses custom driver on pin A2 (26 LEDs)

#include "ws2812.h"
#include "gpio.h"
#include "wait.h"

#ifdef RGBLIGHT_ENABLE
#include "ws2812_bitbang.c"
#include "rgblight/rgblight_drivers.h"

// RGBLIGHT-specific LED array for pin A2
static ws2812_led_t rgblight_leds[RGBLIGHT_LED_COUNT];

// Simple bit-bang functions for RGBLIGHT on pin A2
static void sendByte_A2(uint8_t byte) {
    for (unsigned char bit = 0; bit < 8; bit++) {
        bool is_one = byte & (1 << (7 - bit));
        if (is_one) {
            gpio_write_pin_high(A2);
            wait_us(1);  // T1H
            gpio_write_pin_low(A2);
            wait_us(1);  // T1L
        } else {
            gpio_write_pin_high(A2);
            wait_us(0);  // T0H (minimal delay)
            gpio_write_pin_low(A2);
            wait_us(1);  // T0L
        }
    }
}

static void ws2812_rgblight_init(void) {
    gpio_set_pin_output(A2);
}

static void ws2812_rgblight_set_color(int index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= 0 && index < RGBLIGHT_LED_COUNT) {
        rgblight_leds[index].r = red;
        rgblight_leds[index].g = green;
        rgblight_leds[index].b = blue;
    }
}

static void ws2812_rgblight_set_color_all(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < RGBLIGHT_LED_COUNT; i++) {
        rgblight_leds[i].r = red;
        rgblight_leds[i].g = green;
        rgblight_leds[i].b = blue;
    }
}

static void ws2812_rgblight_flush(void) {
    // Disable interrupts for precise timing
    __disable_irq();

    for (int i = 0; i < RGBLIGHT_LED_COUNT; i++) {
        // WS2812 expects GRB order
        sendByte_A2(rgblight_leds[i].g);
        sendByte_A2(rgblight_leds[i].r);
        sendByte_A2(rgblight_leds[i].b);
    }

    // Reset signal: >280us low
    gpio_write_pin_low(A2);
    wait_us(300);

    __enable_irq();
}

// Export the RGBLIGHT driver
const rgblight_driver_t rgblight_driver = {
    .init          = ws2812_rgblight_init,
    .set_color     = ws2812_rgblight_set_color,
    .set_color_all = ws2812_rgblight_set_color_all,
    .flush         = ws2812_rgblight_flush,
};

#endif
