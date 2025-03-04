/* Copyright 2021 JasonRen(biu)
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

enum custom_keycodes {
    QUIT = SAFE_RANGE,
    WIPE,
    WIRE,
    ERASE,
    EXPLD,
    RECT,
    ROTATE,
    REGEN,
    TRIM,
    UNGRUP,
    INSERT,
    OFFSET,
    PLINE,
    PLOT,
    PURGE,
    BEDIT,

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        // 0     1       2        3       4      5         6              7       8        9        10       11       12
	LAYOUT(
		KC_ESC,  KC_Q,   KC_W,    KC_E,   KC_R,  KC_T,     KC_Y,          KC_U,   KC_I,    KC_O,    KC_P,    KC_EQL,  KC_BSPC,
		KC_TAB, KC_A,   KC_S,    KC_D,   KC_F,  KC_G,     KC_H,          KC_J,   KC_K,    KC_L,    MO(1),   KC_DEL,
		KC_LSFT, KC_Z,   KC_X,    KC_C,   KC_V,  KC_B,     KC_N,          KC_M,   KC_DOT,  KC_RSFT, KC_UP,   KC_HOME,
		KC_LCTL, KC_LGUI,KC_LALT, KC_SPC,                  LT(1, KC_SPC),         MO(2),   KC_LEFT, KC_DOWN, KC_RGHT),
	LAYOUT(
		KC_GRV,  KC_1,   KC_2,    KC_3,   KC_4,   KC_5,    KC_6,          KC_7,   KC_8,    KC_9,    KC_0,    KC_PGDN, KC_DEL,
		KC_CAPS,  KC_BSLS,KC_QUOT, KC_GRV, KC_LABK,KC_RABK, KC_MINS,       KC_EQL, KC_LBRC, KC_RBRC, _______, _______,
		_______, _______,_______, _______,_______,_______, _______,       _______,KC_COMM, _______, _______, _______,
		_______, _______,_______, _______,                 _______,               _______, _______, _______, _______),
	LAYOUT(
		KC_GRV,  KC_F1,  KC_F2,   KC_F3,  KC_F4,  KC_F5,   KC_F6,         KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
		_______, _______,_______, _______,_______,_______, _______,       _______,_______, _______, KC_ENT,  _______,
		_______, _______,_______, _______,_______,_______, _______,       _______,_______, _______, _______, _______,
		_______, _______,_______, _______,                 _______,               _______, _______, _______, _______),
	LAYOUT(
		KC_ESC,  QUIT,   WIPE,    EXPLD,  RECT,  TRIM,     KC_Y,          UNGRUP, INSERT,  OFFSET,  PLINE,    BEDIT,  KC_BSPC,
		KC_TAB,  KC_A,   KC_S,    KC_D,   KC_F,  KC_G,     KC_H,          KC_J,   KC_K,    KC_L,    MO(4),    KC_INS,
		KC_LSFT, KC_Z,   KC_X,    KC_C,   KC_V,  KC_B,     KC_N,          KC_M,   KC_COMM, KC_RSFT, KC_UP,   KC_DEL,
		KC_LCTL, KC_LGUI,KC_LALT, KC_SPC,                  LT(4, KC_SPC),         MO(5),   KC_LEFT, KC_DOWN, KC_RGHT),
	LAYOUT(
		KC_ESC,  _______,WIRE,    ERASE,  ROTATE, _______, _______,       _______,_______, _______, PLOT,    _______, KC_BSPC,
		_______, _______,_______, _______,_______,_______, _______,       _______,_______, _______, _______, _______,
		_______, _______,_______, _______,_______,_______, _______,       _______,_______, _______, _______, _______,
		_______, _______,_______, _______,                 _______,               _______, _______, _______, _______),
	LAYOUT(
		KC_ESC,  _______,_______, _______,REGEN,  _______, _______,       _______,_______, _______, PURGE,   _______, KC_BSPC,
		_______, _______,_______, _______,_______,_______, _______,       _______,_______, _______, _______, _______,
		_______, _______,_______, _______,_______,_______, _______,       _______,_______, _______, _______, _______,
		_______, _______,_______, _______,                 _______,               _______, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PLINE:
            if (record->event.pressed) {
                tap_code_delay(KC_MS_BTN1, 50);
                tap_code_delay(KC_MS_BTN1, 50);
            }
            break;
        case PLOT:
            if (record->event.pressed) {
                SEND_STRING("Hello, World!");
            }
            break;
        case REGEN:
            if (record->event.pressed) {
                tap_code_delay(KC_F, 50);
                tap_code_delay(KC_O, 50);
                tap_code_delay(KC_O, 50);
            }
            break;
        case RECT:
            if (record->event.pressed) {
                tap_code_delay(KC_B, 50);
                tap_code_delay(KC_A, 50);
                tap_code_delay(KC_R, 50);
            break;
            }
        }
        return true;
}
