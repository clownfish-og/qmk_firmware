/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_LAYERS
#   define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#   define RGBLIGHT_LAYERS_RETAIN_VAL
#   define RGBLIGHT_DEFAULT_MODE       RGBLIGHT_MODE_RAINBOW_SWIRL
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES
#   define RGB_MATRIX_DISABLE_SHARED_KEYCODES

#   define RGB_INDEX_CAPS                  62  /** Caps 指示灯索引 **/
#   define RGB_INDEX_SCROLL                14  /** Scorll 指示灯索引 **/
#   define RGB_INDEX_FN                    80  /** FN   指示灯索引 **/
#endif

