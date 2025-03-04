/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   MO(1),   KC_HOME, KC_END,  KC_MUTE,  QK_MACRO_0,
	KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,  KC_NUM,  KC_PSLS, KC_PAST,  KC_PMNS,
	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP, KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
	KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,             KC_PGDN, KC_P4,   KC_P5,   KC_P6,
	KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                      KC_UP,   KC_P1,   KC_P2,   KC_P3,    KC_PENT,
	KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL,  KC_LEFT,            KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT
    ),

	[1] = LAYOUT(
	_______,          KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, RGB_HUD, _______, RGB_HUI,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMOD,
	MO(2),   _______, _______,                   _______,                            _______, _______, _______, _______,           _______, _______, RGB_TOG, RGB_M_P
    ),

	[2] = LAYOUT(
	EE_CLR,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
	_______, _______, _______,                   _______,                            _______, _______, _______, _______,          _______, _______, _______, _______
    ),

	[3] = LAYOUT(
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,          _______, _______, _______, _______
    )
};


#ifdef RGB_MATRIX_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
            if (host_keyboard_led_state().caps_lock && !host_keyboard_led_state().num_lock) {
                rgb_matrix_set_color_all(RGB_PURPLE);
            }
            else if (!host_keyboard_led_state().num_lock) {
                rgb_matrix_set_color_all(RGB_WHITE);
            }
            else if (host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color_all(RGB_BLUE);
            }
            else if (!rgb_matrix_get_flags()){
                rgb_matrix_set_color_all(0, 0, 0);
            }
        return true;
}
  #endif
