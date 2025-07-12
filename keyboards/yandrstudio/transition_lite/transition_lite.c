// Copyright 2024 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

uint8_t rgb_matrix_map_row_column_to_led_kb(uint8_t row, uint8_t column, uint8_t *led_i) {
    if ( row == 5 && column == 7) {
        led_i[0] = 83;
        led_i[1] = 84;
        led_i[2] = 86;
        led_i[3] = 87;
        return 4;
    }
    return 0;
}

#endif
