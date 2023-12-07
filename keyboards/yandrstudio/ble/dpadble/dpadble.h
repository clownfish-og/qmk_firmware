// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define LAYOUT( \
    K000, K001, K002, K003, \
    K100, K101, K102, K103, \
    K200, K201, K202        \
) { \
    { K000,  K001,  K002,  K003 }, \
    { K100,  K101,  K102,  K103 }, \
    { K200,  K201,  K202,  KC_NO } \
}

enum keyboard_keycodes {
    LOCK_GUI = QK_KB,
    TOG_MACOS_KEYMAP_MAC,
    KC_MISSION_CONTROL_MAC,
    KC_LAUNCHPAD_MAC,
    TOP_RGB_TOG
};

typedef struct {
    uint8_t  top_rgb_sw: 8;
} kb_cstm_config_t;


void rgb_matrix_adv_unblink_all_batlayer_but_one_layer(uint8_t l);
