/* Copyright 2024 Clear <Clear@163.com>
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

#ifdef RGB_MATRIX_ENABLE
// rgb动画锁定颜色
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
#endif
