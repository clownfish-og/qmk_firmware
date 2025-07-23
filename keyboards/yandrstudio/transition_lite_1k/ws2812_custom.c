// Copyright 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

// Custom dual-pin WS2812 driver for transition_lite_1k
// Uses QMK's standard bitbang driver for both pins with proper timing
// Much safer than manual implementations

// RGB Matrix driver - standard implementation for pin B13
#undef WS2812_DI_PIN
#define WS2812_DI_PIN B13
#include "ws2812_bitbang.c"

#ifdef RGBLIGHT_ENABLE
#include "rgblight/rgblight_drivers.h"

// RGBLIGHT driver - use standard implementation for pin A2
// Clear previous definitions to avoid conflicts
#undef WS2812_DI_PIN
#undef sendByte
#undef ws2812_init
#undef ws2812_set_color
#undef ws2812_set_color_all
#undef ws2812_flush
#undef ws2812_leds

#define WS2812_DI_PIN A2

// Rename functions for RGBLIGHT to avoid conflicts
#define sendByte sendByte_rgblight
#define ws2812_init ws2812_rgblight_init
#define ws2812_set_color ws2812_rgblight_set_color
#define ws2812_set_color_all ws2812_rgblight_set_color_all
#define ws2812_flush ws2812_rgblight_flush
#define ws2812_leds rgblight_leds

// Include the standard driver again with renamed functions
#include "ws2812_bitbang.c"

// Export the RGBLIGHT driver
const rgblight_driver_t rgblight_driver = {
    .init          = ws2812_rgblight_init,
    .set_color     = ws2812_rgblight_set_color,
    .set_color_all = ws2812_rgblight_set_color_all,
    .flush         = ws2812_rgblight_flush,
};

#endif
