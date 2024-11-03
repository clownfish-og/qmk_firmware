// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xAA96
#define PRODUCT_ID      0xAA57
#define DEVICE_VER      0x0001
#define MANUFACTURER    "StudioX_Y&R"
#define PRODUCT         "countach800"

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

//                           0   1    2   3   4   5   6   7   8   9   10   11   12  13    14   15   16
#   define MATRIX_COL_PINS { A1, A2,  A3, A4, A5, A6, A7, B0, B1, B2, B10, B11, B12, B13, B14, B15, A8 }
#   define MATRIX_ROW_PINS { B3, A15, B6, B5, B4, B7}

#define TAP_CODE_DELAY 15

#ifdef RGBLIGHT_ENABLE

#    define WS2812_DI_PIN A9
#    define RGBLED_NUM 36
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_VAL_STEP 5
#    define RGBLIGHT_LIMIT_VAL 200
#    define RGBLIGHT_ANIMATIONS

#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#    define RGBLIGHT_LAYERS_RETAIN_VAL

#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD

#endif

/* RGN Matrix */
#ifdef RGB_MATRIX_ENABLE

#    define WS2812_DI_PIN A9

#    define RGB_MATRIX_LED_COUNT 36

#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_ANIMATIONS

// #   define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #   define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #   define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_BREATHING
// #   define ENABLE_RGB_MATRIX_BAND_SAT
// #   define ENABLE_RGB_MATRIX_BAND_VAL
// #   define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #   define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #   define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #   define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   define ENABLE_RGB_MATRIX_CYCLE_ALL
#   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #   define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #   define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #   define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #   define ENABLE_RGB_MATRIX_DUAL_BEACON
// #   define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #   define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #   define ENABLE_RGB_MATRIX_RAINDROPS
// #   define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #   define ENABLE_RGB_MATRIX_HUE_BREATHING
// #   define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #   define ENABLE_RGB_MATRIX_HUE_WAVE
// #   define ENABLE_RGB_MATRIX_PIXEL_RAIN
// #   define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #   define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
// #   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #   define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
// #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #   define ENABLE_RGB_MATRIX_SPLASH
// #   define ENABLE_RGB_MATRIX_MULTISPLASH
// #   define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #   define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#endif
