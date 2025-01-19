/*
Copyright 2023
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


#include QMK_KEYBOARD_H
#include "buppad_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        ZEJIBO,      CATDANCE,    PATBANG,
        BITS,     LT(1, GLUTES),  DYE,
        BUP,         CAPGEN5,     KC_ENT
    ),
    [1] = LAYOUT(
        TO(2),       SLAY,        FREAKOUT,
        BACKDOOR,    _______,     DONUT,
        MOOSE,       LOVE,        THANKS
    ),
    [2] = LAYOUT(
        TO(0),       KC_KP_8,    TO(5),
        KC_KP_4,     KC_KP_5,    KC_KP_6,
        KC_KP_1,     KC_KP_2,    KC_KP_3
    ),
    [3] = LAYOUT(
        TO(0),       KC_KP_8,    KC_KP_9,
        KC_KP_4,     KC_KP_5,    KC_KP_6,
        KC_KP_1,     KC_KP_2,    KC_KP_3
    ),
    [4] = LAYOUT(
        TO(0),       KC_KP_8,    KC_KP_9,
        KC_KP_4,     KC_KP_5,    KC_KP_6,
        KC_KP_1,     KC_KP_2,    KC_KP_3
    ),
    [5] = LAYOUT(
        TO(0),       RGB_VAI,    RGB_MOD,
        RGB_HUI,     RGB_SAI,    RGB_SPI,
        RGB_HUD,     KC_SHFT,    RGB_TOG
    ),
};
