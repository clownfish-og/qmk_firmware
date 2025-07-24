// Copyright 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
// valid config.
// A1 TIM2_CH2
// #define WS2812_PWM_COMPLEMENTARY_OUTPUT                // TIMx_CHyN
#define WS2812_PWM_DRIVER           PWMD2               // TIMx
#define WS2812_PWM_CHANNEL          2                   // TIMx_CHy
#define WS2812_PWM_PAL_MODE         2
#define WS2812_DMA_STREAM           STM32_DMA1_STREAM2  // TIMx_UP
#define WS2812_DMA_CHANNEL          2                   // STM32_DMAx_STREAMy

// A2 TIM2_CH3
// #define WS2812_PWM_COMPLEMENTARY_OUTPUT                // TIMx_CHy
#define WS2812_PWM_DRIVER           PWMD2               // TIMx
#define WS2812_PWM_CHANNEL          3                   // TIMx_CHy
#define WS2812_PWM_PAL_MODE         2
#define WS2812_DMA_STREAM           STM32_DMA1_STREAM2  // TIMx_UP
#define WS2812_DMA_CHANNEL          2                   // STM32_DMAx_STREAMy
*/

// PWM and DMA configuration for TIM2_CH3 (A2)
#define RGBLIGHT_DI_PIN             A2
#define RGBLIGHT_PWM_PAL_MODE       2
#define RGBLIGHT_PWM_DRIVER         PWMD2
#define RGBLIGHT_PWM_CHANNEL        3
#define RGBLIGHT_DMA_STREAM         STM32_DMA1_STREAM2
#define RGBLIGHT_DMA_CHANNEL        2

#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_LED_COUNT 26
#   define RGBLIGHT_LAYERS
#   define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#   define RGBLIGHT_LAYERS_RETAIN_VAL
#   define RGBLIGHT_DEFAULT_MODE       RGBLIGHT_MODE_RAINBOW_SWIRL
#endif

// /** RGB MATRIX CONFIGS ----- B13 TIM1_CH1N */
#define WS2812_PWM_COMPLEMENTARY_OUTPUT                 // TIMx_CHyN
#define WS2812_PWM_DRIVER           PWMD1               // TIMx
#define WS2812_PWM_CHANNEL          1                   // TIMx_CHy
#define WS2812_PWM_PAL_MODE         2
#define WS2812_PWM_DMA_STREAM       STM32_DMA1_STREAM5  // TIMx_UP
#define WS2812_PWM_DMA_CHANNEL      5                   // STM32_DMAx_STREAMy

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES
#   define RGB_MATRIX_DISABLE_SHARED_KEYCODES

#   define RGB_INDEX_CAPS   62
#   define RGB_INDEX_SCROLL 14
#   define RGB_INDEX_FN     80
#endif
