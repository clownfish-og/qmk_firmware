/* Copyright 2024 ClownFish (@clownfish-og)
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
#include "buppad_common.h"

enum custom_keycodes {
    TEST = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(!process_record_bup(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case TEST:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT("test"));
            }
            return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1),    CHEESE,   EYE,      GLUTES,   DUCKDANCE,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, TEST
    ),
    [1] = LAYOUT(
        TO(0),    TO(5),    TO(2),    TO(3),    TO(4),
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        TO(0),    TO(1),    TO(5),    TO(3),    TO(4),
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        TO(0),    TO(1),    TO(2),    TO(5),    TO(4),
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [4] = LAYOUT(
        TO(0),    TO(1),    TO(2),    TO(3),    TO(5),
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [5] = LAYOUT(
        TO(0),    TO(1),    TO(2),    TO(3),    TO(4),
        RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,
        RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_TOG
    ),
};
