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

#include QMK_KEYBOARD_H

/*
 * Example keymap showing independent RGB Matrix and RGBLIGHT control
 *
 * This demonstrates how to use the separate keycodes:
 * - RM_XXXX keycodes control RGB Matrix (key backlighting on pin B13)
 * - UG_XXXX keycodes control RGBLIGHT (underglow on pin A2)
 *
 * Place these keycodes in your keymap to control each LED system independently.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_tkl_ansi(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_MENU, KC_RCTL,             KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Function layer with RGB controls
    [1] = LAYOUT_tkl_ansi(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             RM_VALU,
        _______, _______, _______,                            _______,                            _______, _______, _______,             UG_PREV, RM_VALD, UG_NEXT
    )
};

/*
 * Available RGB Matrix keycodes (for key backlighting):
 * RM_TOGG - Toggle RGB Matrix on/off
 * RM_NEXT - Next RGB Matrix mode
 * RM_PREV - Previous RGB Matrix mode
 * RM_HUEI - Increase RGB Matrix hue
 * RM_HUED - Decrease RGB Matrix hue
 * RM_SATI - Increase RGB Matrix saturation
 * RM_SATD - Decrease RGB Matrix saturation
 * RM_VALU - Increase RGB Matrix brightness
 * RM_VALD - Decrease RGB Matrix brightness
 * RM_SPDI - Increase RGB Matrix speed
 * RM_SPDD - Decrease RGB Matrix speed
 *
 * Available RGBLIGHT keycodes (for underglow):
 * UG_TOGG - Toggle RGBLIGHT on/off
 * UG_NEXT - Next RGBLIGHT mode
 * UG_PREV - Previous RGBLIGHT mode
 * UG_HUEI - Increase RGBLIGHT hue
 * UG_HUED - Decrease RGBLIGHT hue
 * UG_SATI - Increase RGBLIGHT saturation
 * UG_SATD - Decrease RGBLIGHT saturation
 * UG_VALU - Increase RGBLIGHT brightness
 * UG_VALD - Decrease RGBLIGHT brightness
 * UG_SPDI - Increase RGBLIGHT speed
 * UG_SPDD - Decrease RGBLIGHT speed
 */
