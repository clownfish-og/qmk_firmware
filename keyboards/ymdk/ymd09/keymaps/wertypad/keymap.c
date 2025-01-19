// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    CAPGEN5 = QK_KB_0,
    APPROVE,
    BONGO,
    DANCE,
    FIRE,
    GIFT,
    GLUTES,
    GRIN,
    HEART,
    HEARTBEAT,
    HUG,
    JAMMIN,
    TUNE,
    WAVE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CAPGEN5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvv"));
            }
            return false;
        case APPROVE:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Approve ");
            }
            return false;
        case BONGO:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Bongo ");
            }
            return false;
        case DANCE:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Dance ");
            }
            return false;
        case FIRE:
            if (record->event.pressed) {
                SEND_STRING("wertyo2FireSauce ");
            }
            return false;
        case GIFT:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Gift ");
            }
            return false;
        case GLUTES:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Glutes ");
            }
            return false;
        case GRIN:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Grin ");
            }
            return false;
        case HEART:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Heart ");
            }
            return false;
        case HEARTBEAT:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Heartbeat ");
            }
            return false;
        case HUG:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Hug ");
            }
            return false;
        case JAMMIN:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Jammin ");
            }
            return false;
        case TUNE:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Tune ");
            }
            return false;
        case WAVE:
            if (record->event.pressed) {
                SEND_STRING("wertyo2Wave ");
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(GLUTES,    DANCE,    BONGO,
               HUG,       MO(1),    WAVE,
               HEARTBEAT, CAPGEN5,  KC_ENT),

  [1] = LAYOUT(TO(2),     JAMMIN,   GRIN,
               GIFT,      _______,  APPROVE,
               HEART,     FIRE,     TUNE),

  [2] = LAYOUT(TO(0),     RGB_M_P,  RGB_MOD,
               RGB_VAI,   RGB_SAI,  RGB_SPI,
               RGB_HUI,   KC_RSFT,  RGB_TOG),

};
