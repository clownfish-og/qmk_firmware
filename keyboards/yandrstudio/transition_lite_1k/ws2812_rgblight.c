// Copyright 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

// RGBLIGHT WS2812 driver for pin A2

#include "rgblight/rgblight_drivers.h"

// RGBLIGHT uses pin A2
#undef WS2812_DI_PIN
#define WS2812_DI_PIN A2

// Rename functions to avoid conflicts with RGB matrix
#define ws2812_init ws2812_rgblight_init
#define ws2812_set_color ws2812_rgblight_set_color
#define ws2812_set_color_all ws2812_rgblight_set_color_all
#define ws2812_flush ws2812_rgblight_flush
#define ws2812_leds rgblight_leds
#define sendByte sendByte_rgblight

// Include the standard bitbang implementation with renamed functions
#include "ws2812_bitbang.c"

// Export the RGBLIGHT driver
const rgblight_driver_t rgblight_driver = {
    .init          = ws2812_rgblight_init,
    .set_color     = ws2812_rgblight_set_color,
    .set_color_all = ws2812_rgblight_set_color_all,
    .flush         = ws2812_rgblight_flush,
};
