// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "swk80.h"

#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix_layer.h"

extern rgb_task_states rgb_task_state;

led_config_t g_led_config = {
    {
        {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,   NO_LED,  13,  14,  15},
        {32,  31,  30,  29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16},
        {33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49},
        {62,  61,  60,  59,  58,  57,  56,  55,  54,  53,  52,  51,   NO_LED,  50,   NO_LED,   NO_LED,   NO_LED},
        {63,   NO_LED,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,   NO_LED,   NO_LED,  75,   NO_LED},
        {90,  89,  88,   NO_LED,   NO_LED,  NO_LED,  NO_LED,  85,  NO_LED,  NO_LED,  82,  81,  80,  79,  78,  77,  76}
    },
    {
        // LED Index to Physical Position
        {0,0},{14,0},{28,0},{42,0},{56,0},{70,0},{84,0},{98,0},{112,0},{126,0},{140,0},{154,0},{168,0},       {196,0},{210,0},{224,0},
        {224,13},{210,13},{196,13},{182,13},{168,13},{154,13},{140,13},{126,13},{112,13},{98,13},{84,13},{70,13},{56,13},{42,13},{28,13},{14,13},{0,13},
        {0,26},{14,26},{28,26},{42,26},{56,26},{70,26},{84,26},{98,26},{112,26},{126,26},{140,26},{154,26},{168,26},{182,26},{196,26},{210,26},{224,26},
                            {182,38},       {154,38},{140,38},{126,38},{112,38},{98,38},{84,38},{70,38},{56,38},{42,38},{28,38},{14,38},{0,38},
        {0,51},       {28,51},{42,51},{56,51},{70,51},{84,51},{98,51},{112,51},{126,51},{140,51},{154,51},{168,51},              {210,51},
        {224,64},{210,64},{196,64},{182,64},{168,64},{154,64},{140,64},{126,64},{112,64},{98,64},{84,64},{70,64},              {28,64},{14,64},{0,64},
        {0,64},{19,64},{37,64},{56,64},{75,64},{93,64},{112,64},{131,64},{149,64},{168,64},{187,64},{205,64},{224,64},
        {224,0},{205,0},{187,0},{168,0},{149,0},{131,0},{112,0},{93,0},{75,0},{56,0},{37,0},{19,0},{0,0}
    },
    {
      // LED Index to Flag
      4,4,4,4,4, 4,4,4,4,4, // 0
      4,4,4,4,4, 4,4,4,4,4, // 1
      4,4,4,4,4, 4,4,4,4,4, // 2
      4,4,4,4,4, 4,4,4,4,4, // 3
      4,4,4,4,4, 4,4,4,4,4, // 4
      4,4,4,4,4, 4,4,4,4,4, // 5
      4,4,4,4,4, 4,4,4,4,4, // 6
      4,4,4,4,4, 4,4,4,4,4, // 7
      4,4,4,4,4, 4,4,4,4,4, // 8
      4,
      8,8,8,8,8, 8,8,8,8,8,
      8,8,8,8,8, 8,8,8,8,8,
      8,8,8,8,8, 8

    }
};



const rgb_matrix_adv_layer_segment_t PROGMEM my_capslock_layer[] = RGB_MATRIX_LAYER_SEGMENTS(
    {62, 1, HSV_RED}
);

const rgb_matrix_adv_layer_segment_t* const PROGMEM my_rgb_matrix_layers[] = RGB_MATRIX_LAYERS_LIST(
    my_capslock_layer
);

extern LED_TYPE rgb_matrix_ws2812_array[RGB_MATRIX_LED_COUNT];

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    rgb_matrix_adv_blink_layer_repeat_helper();
    rgb_matrix_adv_set_layer_state(0, host_keyboard_led_state().caps_lock);

    // If not enabled, then nothing else will actually set the LEDs...
    if (!rgb_matrix_is_enabled()) {
        rgb_task_state = FLUSHING;
    }
    uint8_t cent_num = 85;
    rgb_matrix_ws2812_array[cent_num-1].r = rgb_matrix_ws2812_array[cent_num].r;
    rgb_matrix_ws2812_array[cent_num-1].g = rgb_matrix_ws2812_array[cent_num].g;
    rgb_matrix_ws2812_array[cent_num-1].b = rgb_matrix_ws2812_array[cent_num].b;
    rgb_matrix_ws2812_array[cent_num-2].r = rgb_matrix_ws2812_array[cent_num].r;
    rgb_matrix_ws2812_array[cent_num-2].g = rgb_matrix_ws2812_array[cent_num].g;
    rgb_matrix_ws2812_array[cent_num-2].b = rgb_matrix_ws2812_array[cent_num].b;
    rgb_matrix_ws2812_array[cent_num+1].r = rgb_matrix_ws2812_array[cent_num].r;
    rgb_matrix_ws2812_array[cent_num+1].g = rgb_matrix_ws2812_array[cent_num].g;
    rgb_matrix_ws2812_array[cent_num+1].b = rgb_matrix_ws2812_array[cent_num].b;
    rgb_matrix_ws2812_array[cent_num+2].r = rgb_matrix_ws2812_array[cent_num].r;
    rgb_matrix_ws2812_array[cent_num+2].g = rgb_matrix_ws2812_array[cent_num].g;
    rgb_matrix_ws2812_array[cent_num+2].b = rgb_matrix_ws2812_array[cent_num].b;
    return true;
}


void keyboard_post_init_kb(void) {
    rgb_matrix_reload_from_eeprom();
    rgb_matrix_layers = my_rgb_matrix_layers;
}

#endif
