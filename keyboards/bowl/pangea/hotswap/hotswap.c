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

void keyboard_post_init_kb(void) {
    rgblight_setrgb(RGB_BLACK);
    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    if (host_keyboard_led_state().caps_lock){
        rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), 0);
        rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), 1);
    }
    else {
        rgblight_sethsv_at(RGB_BLACK, 0);
        rgblight_sethsv_at(RGB_BLACK, 1);
    }
    if (host_keyboard_led_state().num_lock) {
        rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), 2);
    }
    else {
        rgblight_sethsv_at(RGB_BLACK, 2);
    }
    housekeeping_task_user();
}
