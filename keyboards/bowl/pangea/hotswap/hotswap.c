/* Copyright 2024 Gondolindrim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *//* Copyright 2024 Gondolindrim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "hotswap.h"

// Boolean to track which LED to use for caps lock (false (stepped) = LED 0, true (full) = LED 1)
static bool caps_led_toggle = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case CAPS_LT:
            if (record->event.pressed) {
                caps_led_toggle = !caps_led_toggle;
            }
            return false;
            break;
    }
    return true;
}

void keyboard_post_init_kb(void) {
    rgb_matrix_set_color_all(RGB_BLACK);
    keyboard_post_init_user();
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    hsv_t hsv = {rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val()};
    rgb_t rgb = hsv_to_rgb(hsv);

    if (host_keyboard_led_state().caps_lock){
        // Use the boolean to determine which LED to illuminate for caps lock
        if (caps_led_toggle) {
            // LED 1 for caps lock, turn off LED 0
            rgb_matrix_set_color(0, RGB_BLACK);
            rgb_matrix_set_color(1,rgb.r, rgb.g, rgb.b);
        } else {
            // LED 0 for caps lock, turn off LED 1
            rgb_matrix_set_color(1, RGB_BLACK);
            rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
        }
    }
    else {
        rgb_matrix_set_color(0, RGB_BLACK);
        rgb_matrix_set_color(1, RGB_BLACK);
    }
    if (host_keyboard_led_state().num_lock) {
        rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
    }
    else {
        rgb_matrix_set_color(2, RGB_BLACK);
    }
    return true;
}
