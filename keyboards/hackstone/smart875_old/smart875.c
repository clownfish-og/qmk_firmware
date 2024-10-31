/* Copyright (C) 2023 Westberry Technology Corp., Ltd
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

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE

// clang-format off

#undef ___
#define ___ NO_LED

led_config_t g_led_config = {
    {
        {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15},
        {31,  30,  29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16},
        {32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47},
        {63,  62,  61, 60,  59,  58,  57,  56,  55,  54,  53,  52,   NO_LED,  51,   NO_LED,   NO_LED},
        {64,   NO_LED,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,   NO_LED,  75,  76,   NO_LED},
        {89,  88,  87,   NO_LED,  86,   NO_LED,  85,  84,   NO_LED,  83,  82,  81,  80,  79,  78,  77},
    }, {
        {0,0},{15,0},{30,0},{45,0},{60,0},{75,0},{90,0},{105,0},{119,0},{134,0},{149,0},{164,0},{179,0},{194,0},{209,0},{224,0},
        {224,13},{209,13},{194,13},{179,13},{164,13},{149,13},{134,13},{119,13},{105,13},{90,13},{75,13},{60,13},{45,13},{30,13},{15,13},{0,13},
        {0,26},{15,26},{30,26},{45,26},{60,26},{75,26},{90,26},{105,26},{119,26},{134,26},{149,26},{164,26},{179,26},{194,26},{209,26},{224,26},
        {224,38}, {222,38}, {220,38},    {194,38},       {164,38},{149,38},{134,38},{119,38},{105,38},{90,38},{75,38},{60,38},{45,38},{30,38},{15,38},{0,38},
        {0,51},       {30,51},{45,51},{60,51},{75,51},{90,51},{105,51},{119,51},{134,51},{149,51},{164,51},       {194,51},{209,51},
        {224,64},{209,64},{194,64},{179,64},{164,64},{149,64},{134,64},       {105,64},{90,64},       {60,64},       {30,64},{15,64},{0,64}
}, {
    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,

    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,

    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4
}};

// clang-format on
#endif
