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
 */

#include "quantum.h"
#include "hotswap.h"

// Track which LED to use for caps lock (false = LED 0, true = LED 1)
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

    // Handle caps lock indication on LED 0 or 1 based on toggle state
    uint8_t caps_led = caps_led_toggle ? 1 : 0;
    uint8_t other_led = caps_led_toggle ? 0 : 1;

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(caps_led, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(other_led, RGB_BLACK);
    } else {
        rgb_matrix_set_color(0, RGB_BLACK);
        rgb_matrix_set_color(1, RGB_BLACK);
    }

    // Handle num lock indication on LED 2
    if (host_keyboard_led_state().num_lock) {
        rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
    } else {
        rgb_matrix_set_color(2, RGB_BLACK);
    }

    return true;
}
