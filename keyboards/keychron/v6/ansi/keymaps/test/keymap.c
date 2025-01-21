/* Copyright 2023 @ Keychron (https://www.keychron.com)

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


#include "keycode.h"
#include "quantum.h"
#include QMK_KEYBOARD_H


enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

# if defined CAPS_LOCK_LED_INDEX
# undef CAPS_LOCK_LED_INDEX
# endif
# if defined SCROLL_LOCK_LED_INDEX
# undef SCROLL_LOCK_LED_INDEX
# endif
# if defined NUM_LOCK_LED_INDEX
# undef NUM_LOCK_LED_INDEX
# endif
#define CAPS_LOCK_LED_INDEX 16
#define CAPS_LOCK_LED_INDEX2 17
#define NUM_LOCK_LED_INDEX 18
#define NUM_LOCK_LED_INDEX2 19
#define SCROLL_LOCK_LED_INDEX 14

#if defined(RGB_MATRIX_ENABLE) && (defined(CAPS_LOCK_LED_INDEX) || defined(NUM_LOCK_LED_INDEX) || defined(SCROLL_LOCK_LED_INDEX))
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);
#    if defined(CAPS_LOCK_LED_INDEX)
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX2, 0, 0, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX2, 0, 0, 0);
        }
    }
#    endif // CAPS_LOCK_LED_INDEX
#    if defined(NUM_LOCK_LED_INDEX)
    if (!host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX2, 0, 0, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX2, 0, 0, 0);
        }
    }
#    endif // NUM_LOCK_LED_INDEX
#    if defined(SCROLL_LOCK_LED_INDEX)
    if (host_keyboard_led_state().scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(SCROLL_LOCK_LED_INDEX, 0, 0, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(SCROLL_LOCK_LED_INDEX, 0, 0, 0);
        }
    }
#    endif // NUM_LOCK_LED_INDEX
    return true;
}
#endif // RGB_MATRIX_ENABLE...

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

enum custom_keycodes {
    CHROME = SAFE_RANGE,
    CAPGEN,
    RMP
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CHROME:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(" ") SS_DELAY(150) ">chrome.exe" SS_DELAY(150) SS_TAP(X_ENT));
            }
            return false;
        case CAPGEN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvv"));
            }
            return false;
        case RMP:
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled())
                    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
        case UG_TOGG:
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
        default:
        return true; // Process all other keycodes normally
    }
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_108(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUSE, CHROME,   KC_MUTE,  G(KC_D),  KC_EQL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_108(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  UG_VALD,  UG_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  UG_TOGG,  _______,  _______,  _______,  CAPGEN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        UG_TOGG,  UG_NEXT,  UG_VALU,  UG_HUEU,  UG_SATU,  UG_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  UG_SATU,  UG_VALU,  UG_SPDU,
        _______,  UG_PREV,  UG_VALD,  UG_HUED,  UG_SATD,  UG_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                UG_HUED,  _______,  UG_HUEU,  UG_NEXT,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            UG_SATD,  UG_VALD,  UG_SPDD,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  UG_TOGG,            RMP,      UG_PREV),
    [WIN_BASE] = LAYOUT_ansi_108(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUSE, CHROME,   KC_MUTE,  G(KC_D),  KC_EQL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_108(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  UG_VALD,  UG_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  UG_TOGG,  _______,  _______,  _______,  CAPGEN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        UG_TOGG,  UG_NEXT,  UG_VALU,  UG_HUEU,  UG_SATU,  UG_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  UG_SATU,  UG_VALU,  UG_SPDU,
        _______,  UG_PREV,  UG_VALD,  UG_HUED,  UG_SATD,  UG_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                UG_HUED,  _______,  UG_HUEU,  UG_NEXT,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            UG_SATD,  UG_VALD,  UG_SPDD,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  UG_TOGG,            RMP,      UG_PREV),
};

#ifdef RGB_MATRIX_ENABLE

#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case AC_TOGG:
                autocorrect_toggle();
                return false; // Skip further processing for this key
            case AC_ON:
                autocorrect_enable();
                return false;
            case AC_OFF:
                autocorrect_disable();
                return false;
        }
    }
    return true; // Process other keycodes as usual
}



bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // if (get_rgb_nightmode()) rgb_matrix_set_color_all(RGB_OFF);

    led_t led_state = host_keyboard_led_state();

    // Scroll Lock RGB setup
    if (led_state.scroll_lock) {
        rgb_matrix_set_color(LED_L3, RGB_RED);
        rgb_matrix_set_color(LED_L4, RGB_RED);
        rgb_matrix_set_color(LED_TAB, RGB_RED);
        rgb_matrix_set_color(LED_F12, RGB_RED);
    }

    // CapsLock RGB setup
    if (led_state.caps_lock) {
        hsv_t hsv = user_config.caps_lock_hs;
        hsv.v = rgb_matrix_get_val();
        rgb_t rgb = hsv_to_rgb(hsv);

        for (uint8_t i = 0; i < ARRAY_SIZE(LED_LIST_LETTERS); i++) {
            rgb_matrix_set_color(LED_LIST_LETTERS[i], rgb.r, rgb.g, rgb.b);
        }
        rgb_matrix_set_color(LED_L1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L8, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_LSFT, rgb.r, rgb.g, rgb.b);
    }

    // Winkey disabled (gaming) mode RGB setup
    if (keymap_config.no_gui) {
        rgb_matrix_set_color(LED_LWIN, RGB_RED); //light up Winkey red when disabled
        rgb_matrix_set_color(LED_W, RGB_CHARTREUSE); //light up gaming keys with WSAD highlighted
        rgb_matrix_set_color(LED_S, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_A, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_D, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_Q, RGB_ORANGE2);
        rgb_matrix_set_color(LED_E, RGB_ORANGE2);
        rgb_matrix_set_color(LED_R, RGB_ORANGE2);
        rgb_matrix_set_color(LED_TAB, RGB_ORANGE2);
        rgb_matrix_set_color(LED_F, RGB_ORANGE2);
        rgb_matrix_set_color(LED_Z, RGB_ORANGE2);
        rgb_matrix_set_color(LED_X, RGB_ORANGE2);
        rgb_matrix_set_color(LED_C, RGB_ORANGE2);
        rgb_matrix_set_color(LED_V, RGB_ORANGE2);
        rgb_matrix_set_color(LED_SPC, RGB_ORANGE2);
        rgb_matrix_set_color(LED_LCTL, RGB_ORANGE2);
        rgb_matrix_set_color(LED_LSFT, RGB_ORANGE2);
    }

    if (IS_LAYER_ON(1)) {
        hsv_t hsv = user_config.layer1_hs;
        hsv.v = rgb_matrix_get_val();
        rgb_t rgb = hsv_to_rgb(hsv);

        for (uint8_t j = 0; j < ARRAY_SIZE(LED_LIST_FUNCROW); j++) {
            rgb_matrix_set_color(LED_LIST_FUNCROW[j], rgb.r, rgb.g, rgb.b);
        }

        rgb_matrix_set_color(LED_FN, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_BSLS, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L8, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_W, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_S, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_E, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_D, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_F, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_N, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_DOWN, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_LEFT, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_RIGHT, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R8, rgb.r, rgb.g, rgb.b);
    }

    if (IS_LAYER_ON(2)) {
        hsv_t hsv = user_config.layer2_hs;
        hsv.v = rgb_matrix_get_val();
        rgb_t rgb = hsv_to_rgb(hsv);

        for (uint8_t i = 0; i < ARRAY_SIZE(LED_LIST_NUMPAD); i++) {
            rgb_matrix_set_color(LED_LIST_NUMPAD[i], rgb.r, rgb.g, rgb.b);
        }
        rgb_matrix_set_color(LED_L1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L8, rgb.r, rgb.g, rgb.b);
    }
    return false;
}

#endif // RGB_MATRIX_ENABLE
