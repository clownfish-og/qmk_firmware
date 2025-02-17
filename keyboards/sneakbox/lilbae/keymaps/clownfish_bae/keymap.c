/*
Copyright 2022 Bryan Ong

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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    AP,
    AB,
    MN
};
enum custom_keycodes {
    AFTERNOON_PROJECT = SAFE_RANGE,
    AFTERNOON_BRIGHTNESS,
    MORNING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [AP] = LAYOUT_bae(AFTERNOON_PROJECT),

    [AB] = LAYOUT_bae(AFTERNOON_BRIGHTNESS),

    [MN] = LAYOUT_bae(MORNING),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AFTERNOON_PROJECT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("p") SS_DELAY(300) SS_TAP(X_PGUP) SS_DELAY(100) SS_TAP(X_ESC) );
            } else {
                layer_move(AB);
                set_single_persistent_default_layer(AB);
            }
            break;
        case AFTERNOON_BRIGHTNESS:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("a") SS_DELAY(300) SS_DOWN(X_RSFT) SS_TAP(X_TAB) SS_UP(X_RSFT) SS_DELAY(100) SS_TAP(X_HOME) SS_DELAY(100) SS_TAP(X_ESC));
            } else {
                layer_move(MN);
                set_single_persistent_default_layer(MN);
            }
            break;
        case MORNING:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("a") SS_DELAY(300) SS_DOWN(X_RSFT) SS_TAP(X_TAB) SS_UP(X_RSFT) SS_DELAY(100) SS_TAP(X_END) SS_DELAY(100) SS_TAP(X_ESC));
                SEND_STRING(SS_LGUI("p") SS_DELAY(300) SS_TAP(X_DOWN) SS_DELAY(50) SS_TAP(X_DOWN) SS_DELAY(50) SS_TAP(X_ENT) SS_DELAY(100) SS_TAP(X_ESC) );
            } else {
                layer_move(AP);
                set_single_persistent_default_layer(AP);
            }
            break;
    }
    return true;
}
