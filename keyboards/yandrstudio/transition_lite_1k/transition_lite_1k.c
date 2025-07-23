// Copyright 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

uint8_t rgb_matrix_map_row_column_to_led_kb(uint8_t row, uint8_t column, uint8_t *led_i) {
    if ( row == 5 && column == 5) {
        led_i[0] = 83;
        led_i[1] = 84;
        led_i[2] = 86;
        led_i[3] = 87;
        return 4;
    }
    return 0;
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(RGB_INDEX_CAPS, RGB_WHITE);
    }

    if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(RGB_INDEX_SCROLL, RGB_WHITE);
    }

    if (layer_state_is(1)) {
        rgb_matrix_set_color(RGB_INDEX_FN, RGB_WHITE);
    }

    return false;
}
