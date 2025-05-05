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

enum custom_keycodes {
    SIMPLGT = QK_KB_0,
    PROJECT,
    CHROME,
    SPAM,
    LFISH,
    BUP,
    LOVE,
    DRAGON,
    THIS,
    KEK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(KC_ENT,  C(KC_C), C(S(KC_V)),
               C(KC_X), C(KC_Z), KC_BSPC,
               TT(1),   C(KC_D), KC_ESC),

  [1] = LAYOUT(TO(3),   SIMPLGT, PROJECT,
               TO(2),   KC_BRID, KC_BRIU,
               _______, KC_VOLD, KC_VOLU),

  [2] = LAYOUT(TO(0),   THIS,    KEK,
               DRAGON,  LOVE,    LFISH,
               BUP,     SPAM,    KC_ENT),

  [3] = LAYOUT(TO(0),   UG_TOGG, UG_NEXT,
               UG_HUEU, UG_VALU, UG_SATU,
               UG_HUED, UG_VALD, UG_SATD),
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case SIMPLGT:
            if (record->event.pressed) {
                switch(rgb_matrix_get_mode()) {
                    case RGB_MATRIX_CYCLE_UP_DOWN:
                        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
                        rgb_matrix_sethsv(180, 255, 200);
                        break;
                    case RGB_MATRIX_SOLID_COLOR:
                        rgb_matrix_mode(RGB_MATRIX_BREATHING);
                        rgb_matrix_sethsv(180, 255, 200);
                        break;
                    case RGB_MATRIX_BREATHING:
                        rgb_matrix_mode(RGB_MATRIX_DUAL_BEACON);
                        rgb_matrix_sethsv(127, 255, 200);
                        break;
                    case RGB_MATRIX_DUAL_BEACON:
                        rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
                        rgb_matrix_sethsv(52, 255, 200);
                        break;
                    default:
                        rgb_matrix_mode(RGB_MATRIX_DUAL_BEACON);
                        rgb_matrix_sethsv(127, 255, 200);
                        break;
                    }
            }
            return false;
        case PROJECT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("P") SS_DELAY(400) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(200) SS_TAP(X_ENT) SS_DELAY(200) SS_TAP(X_ESC) );
            }
            return false;
        case CHROME:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(" ") SS_DELAY(150) ">chrome.exe" SS_DELAY(150) SS_TAP(X_ENT));
            }
            return false;
        case SPAM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvv"));
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
        case LFISH:
                if (record->event.pressed) {
                    if (host_keyboard_led_state().caps_lock) {
                        tap_code(KC_CAPS);
                    }
                    SEND_STRING("tacosa13Lubs wertyo2Clownfish tacosa13Lubs ");
                }
            return false;
        case BUP:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("bupBup ");
            }
            return false;
        case LOVE:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("bupLOVE ");
            }
            return false;
        case DRAGON:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("bupDragon ");
            }
            return false;
        case THIS:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("tinosThis ");
            }
            return false;
        case KEK:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                SEND_STRING("bupKekw ");
            }
            return false;
        default:
        return true; // Process all other keycodes normally
    }
}
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Determine the active layer
    uint8_t active_layer = get_highest_layer(layer_state);

    if (!rgb_matrix_get_flags()) {  // RGB is toggled off
        rgb_matrix_set_color_all(RGB_BLACK);
    }

    // Set indicator LEDs
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (active_layer) {
            case 1:
                rgb_matrix_set_color_all(RGB_WHITE);
                break;
            case 2:
                rgb_matrix_set_color_all(RGB_BLUE);
                break;
            default:
                break;
        }
    }
    return false;
}
