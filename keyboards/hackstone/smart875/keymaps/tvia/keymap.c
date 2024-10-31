// Copyright 2023 JoyLee (@itarze)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "logo_rgbm.h"

#include "raw_hid.h"
bool yr_factory_test = false;
uint32_t rgb_t_itv = 1000;
uint32_t rgb_t_timer = 0;
uint8_t rgb_t_pos = 0;
uint8_t rgb_t_v = 10;

#include "eeprom.h"

bool stop_out_put =false;

enum layers{
    WIN_BASE = 0,
    WIN_FN,
    MAC_BASE1,
    MAC_FN1,
    MAC_BASE2,
    MAC_FN2
};

/*
enum im_keys {
    IM_BT1 = QK_KB_0,
    IM_BT2,
    IM_BT3,
    IM_2G4,
    IM_USB,
    IM_BATQ,
    IM_USER, // 暴露给终端用户使用
    IM_BT4 = QK_KB_0+20,
    IM_BT5,
    RL_TOG,
    RL_MOD,
    RL_RMOD,
    RL_VAI,
    RL_VAD,
    RL_HUI,
    RL_HUD,
    RL_SAI,
    RL_SAD,
    IM_TUON,
    IM_TUOF,
    IM_TUTG,
    IM_USER2, // 暴露给终端用户使用
};
*/

enum im_keys_user {
    LRGB_TOG = IM_USER,// 暴露给终端用户使用
    KRGB_TOG, // 暴露给终端用户使用
    KC_MAC,
    KC_WDS,
    KC_RGBT,
    SW_WASD
};

extern bool im_bat_req_flag;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_BASE] = LAYOUT( /* Base */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_MUTE,   KC_HOME, KC_PSCR,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_INS,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_DEL,  KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
#ifdef SMT875_SPP
        KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,             KC_SPC,   KC_SPC,             KC_RALT,  KC_RGUI,  MO(WIN_FN),    KC_RCTL, KC_LEFT,   KC_DOWN, KC_RGHT),
#else
        KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,             KC_SPC,   KC_SPC,             KC_SPC,   KC_RALT,  MO(WIN_FN),    KC_RCTL, KC_LEFT,   KC_DOWN, KC_RGHT),
#endif
    [WIN_FN] = LAYOUT(  /* FN */
        _______,  KC_BRID,  KC_BRIU,  LWIN(KC_TAB),  LWIN(KC_D),  KC_WBAK,  KC_WSCH,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, _______,  _______, _______,
        _______,  IM_BT1,   IM_BT2,   IM_BT3,   IM_2G4,   IM_USB,   _______,  _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI, _______,  _______, _______,
        KRGB_TOG, RGB_MOD,  SW_WASD,  _______,  RGB_SAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, LRGB_TOG, KC_RGBT, _______,
        _______,  RGB_RMOD, _______,  _______,  RGB_SAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,
        _______,            _______,   KC_WDS,  KC_MAC,  _______,  IM_BATQ,  NK_TOGG,  _______,  _______,  _______,  _______,           _______,  RGB_VAI,
        _______,  GU_TOGG,  _______,            _______,            _______,  _______,            _______,  _______,  _______,  _______, RGB_HUI,  RGB_VAD, RGB_HUD),

    [MAC_BASE1] = LAYOUT(  /* Base */
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  LWIN(KC_DOWN),  KC_WSCH,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, KC_MUTE,   KC_HOME, KC_PSCR,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_INS,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_DEL,  KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
#ifdef SMT875_SPP
        KC_LCTL,  KC_LALT,  KC_LGUI,            KC_SPC,             KC_SPC,   KC_SPC,             KC_RALT,  KC_RGUI,  MO(MAC_FN1),    KC_RCTL, KC_LEFT,   KC_DOWN, KC_RGHT),
#else
        KC_LCTL,  KC_LALT,  KC_LGUI,            KC_SPC,             KC_SPC,   KC_SPC,             KC_SPC,   KC_RALT,  MO(MAC_FN1),    KC_RCTL, KC_LEFT,   KC_DOWN, KC_RGHT),
#endif
    [MAC_FN1] = LAYOUT(  /* FN */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  _______,  _______, _______,
        _______,  IM_BT1,   IM_BT2,   IM_BT3,   IM_2G4,   IM_USB,   _______,  _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI, _______,  _______, _______,
        KRGB_TOG, RGB_MOD,  SW_WASD,  _______,  RGB_SAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, LRGB_TOG, _______, _______,
        _______,  RGB_RMOD, _______,  _______,  RGB_SAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,
        _______,            _______,   KC_WDS,  KC_MAC,   _______,  IM_BATQ,  NK_TOGG,  _______,  _______,  _______,  _______,           _______,  RGB_VAI,
        _______,  _______,  _______,            _______,            _______,  _______,            _______,  _______,  _______,  _______, RGB_HUI,  RGB_VAD, RGB_HUD),

    [MAC_BASE2] = LAYOUT(  /* Base */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_MUTE,   KC_HOME, KC_PSCR,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_INS,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_DEL,  KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,           KC_RSFT,   KC_UP,
#ifdef SMT875_SPP
        KC_LCTL,  KC_LALT,  KC_LGUI,            KC_SPC,             KC_SPC,   KC_SPC,             KC_RALT,  KC_RGUI,  MO(MAC_FN2),    KC_RCTL, KC_LEFT,   KC_DOWN, KC_RGHT),
#else
        KC_LCTL,  KC_LALT,  KC_LGUI,            KC_SPC,             KC_SPC,   KC_SPC,             KC_SPC,   KC_RALT,  MO(MAC_FN2),    KC_RCTL, KC_LEFT,   KC_DOWN, KC_RGHT),
#endif
    [MAC_FN2] = LAYOUT(  /* FN */
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  LWIN(KC_DOWN),  KC_WSCH,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______, _______, _______,
        _______,  IM_BT1,   IM_BT2,   IM_BT3,   IM_2G4,   IM_USB,   _______,  _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI, _______,  _______, _______,
        KRGB_TOG, RGB_MOD,  SW_WASD,  _______,  RGB_SAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, LRGB_TOG, _______, _______,
        _______,  RGB_RMOD, _______,  _______,  RGB_SAD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,
        _______,            _______,  KC_WDS,   KC_MAC,  _______,  IM_BATQ,  NK_TOGG,  _______,   _______,  _______,  _______,           _______,  RGB_VAI,
        _______,  _______,  _______,            _______,            _______,  _______,            _______,  _______,  _______,  _______, RGB_HUI,  RGB_VAD, RGB_HUD)
};

// clang-format on



blink_rgb_t blink_rgbs[RGB_MATRIX_BLINK_COUNT] = {
    {.index = IM_MM_RGB_BLINK_INDEX_BT1, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_BT2, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_BT3, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_2G4, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_USB, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb}
};

bool blink_rgbs_sync = false;


bool blink_gui_tog_f = false;
uint8_t blink_gui_tog_c = false;
uint32_t blink_gui_tog_tmr = false;

bool blink_win_tog_f = false;
uint8_t blink_win_tog_c = false;
uint32_t blink_win_tog_tmr = false;

bool blink_mac_tog_f = false;
uint8_t blink_mac_tog_c = false;
uint32_t blink_mac_tog_tmr = false;

im_lkey_t lkey_define_user[IM_LKEY_COUNT] = {
    {.keycode = GU_TOGG, .hole_time = 3000},
    {.keycode = KC_RGBT, .hole_time = 3000},
    {.keycode = SW_WASD, .hole_time = 3000},
    {.keycode = NK_TOGG, .hole_time = 3000},
    {.keycode = KC_MAC,  .hole_time = 3000},
    {.keycode = KC_WDS,  .hole_time = 3000}
};

// 此函数不需要改动
typedef union {
    uint32_t raw;
    struct {
        uint8_t flag: 1;
        uint8_t rgb_enable: 1;
        uint8_t key_rgb_enable: 1;
        uint8_t mac_os_layer: 1;
        uint8_t mac_fn_swap:  1;
        uint8_t swap_wasd:  1;
        uint8_t logo_rgb_enable: 1;
        uint8_t btwl_sleep_enable: 1;
    };
} confinfo_t;
confinfo_t confinfo;

bool rgb_test_mode_flag = false;
uint8_t rgb_test_mode_color = 0;

HSV logo_hsv;

void eeconfig_confinfo_update(uint32_t raw) {

    eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, raw);
}

uint32_t eeconfig_confinfo_read(void) {

    return eeprom_read_dword((uint32_t *)CONFINFO_EECONFIG_ADDR);
}

void eeconfig_confinfo_default(void) {
    confinfo.flag = true;
    confinfo.rgb_enable = true;
    confinfo.logo_rgb_enable = true;
    confinfo.key_rgb_enable = true;
    confinfo.mac_os_layer = false;
    confinfo.mac_fn_swap = false;
    confinfo.swap_wasd = false;
    confinfo.btwl_sleep_enable = true;
    eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);
}


// 此函数不需要改动
bool mm_get_rgb_enable(void) {
    // return confinfo.key_rgb_enable || confinfo.logo_rgb_enable;
    return confinfo.key_rgb_enable || confinfo.logo_rgb_enable || rgb_matrix_config.enable;
}

// 此函数不需要改动
void mm_set_rgb_enable(bool state) {
    rgb_matrix_config.enable = state;
    confinfo.key_rgb_enable = state;
    confinfo.logo_rgb_enable = state;
}

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable = true;
#endif
}

// 初始化和参数相关的操作，在恢复出厂设置时此函数会被调用
bool im_init_user(void) {

    logo_rgb_matrix_init();

    confinfo.raw = eeprom_read_dword((uint32_t *)CONFINFO_EECONFIG_ADDR);
    if (!confinfo.raw) {
        eeconfig_confinfo_default();
    }
    default_layer_set(1UL << (confinfo.mac_os_layer == true ? 2 : 0));
    if (confinfo.mac_os_layer) {
        if (confinfo.mac_fn_swap == false) {
            default_layer_set(1<<2);
        } else {
            default_layer_set(1<<4);
        }
        if (keymap_config.no_gui) {
            keymap_config.no_gui = !keymap_config.no_gui;
            eeconfig_update_keymap(keymap_config.raw);
        }
    }
    rgb_test_mode_flag = false;
    rgb_test_mode_color = 0;

    logo_hsv.h = 0;
    logo_hsv.s = 255;
    logo_hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;

    return true;
}

uint8_t pre_rgb_mode = 0xff;

extern void rgb_matrix_update_pwm_buffers(void);

// 用户主循环
uint32_t recover_timer = 0;
uint32_t btwl_sleep_sw_timer = 0;
uint32_t mac_fn_sw_timer = 0;

void recv_blink_rgb(uint8_t r, uint8_t g, uint8_t b, uint16_t itv) {
    rgb_matrix_set_color_all(0,0,0);
    rgb_matrix_update_pwm_buffers();
    for (uint16_t i = 0; i < 1000; i++) {
        wait_us(itv);
    }
    rgb_matrix_set_color_all(r, g, b);
    rgb_matrix_update_pwm_buffers();
    for (uint16_t i = 0; i < 1000; i++) {
        wait_us(itv);
    }
}
void recv_blink_frgb(uint8_t r, uint8_t g, uint8_t b, uint16_t itv) {
    rgb_matrix_set_color_all(0,0,0);
    rgb_matrix_update_pwm_buffers();
    for (uint16_t i = 0; i < 1000; i++) {
        wait_us(itv);
    }
    rgb_matrix_set_color_all(r, g, b);
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
        if (i >= 1 && i <= 12) {
            rgb_matrix_set_color(i, r, g, b);
        } else {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    rgb_matrix_update_pwm_buffers();
    for (uint16_t i = 0; i < 1000; i++) {
        wait_us(itv);
    }
}
void reset_all_kb_args(void) {
    eeconfig_disable();
}
void keyboard_recover_factory(void) {
    reset_all_kb_args();
    clear_keyboard();
    for (uint8_t i = 0; i < 3; ++i) {
        recv_blink_rgb(100, 0, 0, 300);
    }
    clear_keyboard();
    // 重启
    NVIC_SystemReset();
}

void btwl_sleep_mode_toggle(void) {
    clear_keyboard();
    if (confinfo.btwl_sleep_enable) {
        confinfo.btwl_sleep_enable = false;
        bts_send_vendor(v_dis_sleep_bt);

        mm_eeconfig.sleep_timeout = 0;
        eeconfig_update_kb(mm_eeconfig.raw);

        eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);

        for (uint8_t i = 0; i < 3; ++i) {
            recv_blink_rgb(100, 0, 0, 200);
        }
    } else {
        confinfo.btwl_sleep_enable = true;
        bts_send_vendor(v_en_sleep_bt);

        mm_eeconfig.sleep_timeout = mm_sleep_timeout_vendor;
        eeconfig_update_kb(mm_eeconfig.raw);

        for (uint8_t i = 0; i < 3; ++i) {
            recv_blink_rgb(0, 100, 0, 200);
        }
    }
    clear_keyboard();
}

uint8_t bat_pre_pvol = 10;

uint32_t bat_pre_pvol_timer = 0;

bool im_loop_user(void) {

/*
    if (mm_eeconfig.devs != DEVS_USB) {
        if (timer_elapsed32(bat_pre_pvol_timer) >= 2000) {
            bts_send_bat_pvol(bat_pre_pvol*10); // 发送一次导致蓝牙无法连接
            bat_pre_pvol_timer = timer_read32();
        } else {
            bat_pre_pvol = bts_info.bt_info.pvol / 10;
        }
    }
*/

    bool stop_output_temp = false;
    if (!mm_get_rgb_enable()) {
        if (blink_rgbs_sync || host_keyboard_led_state().caps_lock || keymap_config.no_gui || confinfo.swap_wasd || mm_eeconfig.charging || bts_info.bt_info.pvol < 10 || im_bat_req_flag) {
            writePin(RGB_DRIVER_EN_PIN, RGB_DRIVER_EN_STATE);
            if (pre_rgb_mode != 0)  {
                pre_rgb_mode = rgb_matrix_get_mode();
                rgb_matrix_set_color_all(0,0,0);
            }
            rgb_matrix_mode_noeeprom(0);
            rgb_matrix_indicators_advanced_kb(0, RGB_MATRIX_LED_COUNT);
            rgb_matrix_update_pwm_buffers();
        } else {
            writePin(RGB_DRIVER_EN_PIN, !RGB_DRIVER_EN_STATE);
            if (pre_rgb_mode != 0xff) {
                rgb_matrix_mode_noeeprom(pre_rgb_mode);
            }
        }
    }

    if (matrix_is_on(2,5) && matrix_is_on(4,8) && matrix_is_on(5,11)) {
        clear_keyboard();
        stop_output_temp = true;
        if (recover_timer != 0 && timer_elapsed32(recover_timer) >= 3000) {
            keyboard_recover_factory();
        }
    } else {
        recover_timer = timer_read32();
    }

    if (matrix_is_on(3,2) && matrix_is_on(3,9) && matrix_is_on(5,11)) {
        clear_keyboard();
        stop_output_temp = true;
        if (btwl_sleep_sw_timer != 0 && timer_elapsed32(btwl_sleep_sw_timer) >= 3000) {
            btwl_sleep_mode_toggle();
            btwl_sleep_sw_timer = timer_read32();
        }
    } else {
        btwl_sleep_sw_timer = timer_read32();
    }

    if (matrix_is_on(4,2) && matrix_is_on(3,6) && matrix_is_on(5,11)) {
        clear_keyboard();
        stop_output_temp = true;
        if (mac_fn_sw_timer != 0 && timer_elapsed32(mac_fn_sw_timer) >= 5000) {
            clear_keyboard();
            for (uint8_t i = 0; i < 5; ++i) {
                recv_blink_frgb(0, 0, 100, 1000);
            }
            clear_keyboard();
            if (confinfo.mac_os_layer) {
                if (confinfo.mac_fn_swap == false) {
                    confinfo.mac_fn_swap = true;
                    default_layer_set(1<<4);
                } else {
                    default_layer_set(1<<2);
                    confinfo.mac_fn_swap = false;
                }
                eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);
            }
            mac_fn_sw_timer = timer_read32();
        }
    } else {
        mac_fn_sw_timer = timer_read32();
    }

    if (stop_output_temp == true) {
        stop_out_put = true;
        unregister_code(KC_M);
        unregister_code(KC_T);
        unregister_code(KC_S);
        unregister_code(KC_L);
    } else {
        stop_out_put = false;
    }

    return true;
}

// 恢复出厂设置回调函数
bool im_reset_settings_user(void) {

    return true;
}

bool im_lkey_process_user(uint16_t keycode, bool pressed) {
    switch (keycode) {
        case NK_TOGG: {
            if (pressed) {
                keymap_config.nkro = !keymap_config.nkro;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // clear to prevent stuck keys
                return false;
            }
        } break;
        case KC_MAC: {
            if (pressed) {
                blink_mac_tog_f = true;
                if (confinfo.mac_fn_swap == false) {
                    default_layer_set(1<<2);
                } else {
                    default_layer_set(1<<4);
                }
                confinfo.mac_os_layer = true;
                eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);
                if (keymap_config.no_gui) {
                    keymap_config.no_gui = !keymap_config.no_gui;
                    eeconfig_update_keymap(keymap_config.raw);
                }
            }
            return false;
        } break;
        case KC_WDS: {
            if (pressed) {
                blink_win_tog_f = true;
                default_layer_set(1<<0);
                confinfo.mac_os_layer = false;
                eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);
            }
            return false;
        } break;
        case GU_TOGG: {
            if (pressed) {
                if (!keymap_config.no_gui) {
                    blink_gui_tog_f = true;
                }
                keymap_config.no_gui = !keymap_config.no_gui;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // clear to prevent stuck keys
                return false;
            }
        } break;
        case KC_RGBT: {
            if (pressed) {
                rgb_test_mode_flag = true;
                rgb_test_mode_color = 0;
                return false;
            }
        } break;
        case SW_WASD: {
            if (pressed) {
                if (confinfo.swap_wasd) {
                    confinfo.swap_wasd = false;
                } else {
                    confinfo.swap_wasd = true;
                }
                eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);
                return false;
            }
        } break;
        default: break;
    }

    return true;
}

bool im_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (stop_out_put) {
        if (keycode == MO(0) || keycode == MO(1) || keycode == MO(2) || keycode == MO(3) || keycode == MO(4) || keycode == MO(5)) {
            return true;
        }
        return false;
    }
    if (confinfo.swap_wasd) {
        switch (keycode) {
            case SW_WASD: {
                if (record->event.pressed) {
                    confinfo.swap_wasd = false;
                    eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);
                }
                return false;
            } break;
            case KC_W:
                if (record->event.pressed) {
                    register_code(KC_UP);
                } else {
                    unregister_code(KC_UP);
                }
                return false;
            case KC_A:
                if (record->event.pressed) {
                    register_code(KC_LEFT);
                } else {
                    unregister_code(KC_LEFT);
                }
                return false;
            case KC_S:
                if (record->event.pressed) {
                    register_code(KC_DOWN);
                } else {
                    unregister_code(KC_DOWN);
                }
                return false;
            case KC_D:
                if (record->event.pressed) {
                    register_code(KC_RIGHT);
                } else {
                    unregister_code(KC_RIGHT);
                }
                return false;
            case KC_UP:
                if (record->event.pressed) {
                    register_code(KC_W);
                } else {
                    unregister_code(KC_W);
                }
                return false;
            case KC_LEFT:
                if (record->event.pressed) {
                    register_code(KC_A);
                } else {
                    unregister_code(KC_A);
                }
                return false;
            case KC_DOWN:
                if (record->event.pressed) {
                    register_code(KC_S);
                } else {
                    unregister_code(KC_S);
                }
                return false;
            case KC_RIGHT:
                if (record->event.pressed) {
                    register_code(KC_D);
                } else {
                    unregister_code(KC_D);
                }
                return false;
        }
    }

    switch (keycode) {
        case NK_TOGG: {
            return false;
        } break;
        case LWIN(KC_TAB): {
            if (record->event.pressed) {
                register_code(KC_LWIN);
                tap_code(KC_TAB);
                unregister_code(KC_LWIN);
            }
            return false;
        } break;
        case LWIN(KC_D): {
            if (record->event.pressed) {
                register_code(KC_LWIN);
                tap_code(KC_D);
                unregister_code(KC_LWIN);
            }
            return false;
        } break;
        case LWIN(KC_DOWN): {
            if (record->event.pressed) {
                register_code(KC_LWIN);
                tap_code(KC_DOWN);
                unregister_code(KC_LWIN);
            }
            return false;
        } break;
        case LRGB_TOG: {
            if (record->event.pressed) {
                logo_rgb_mode_step();
                if (get_logo_rgb_mode() == 0) {
                    confinfo.logo_rgb_enable = false;
                } else {
                    confinfo.logo_rgb_enable = true;
                }
                eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);
                if (!confinfo.logo_rgb_enable && !confinfo.key_rgb_enable) {
                    writePin(RGB_DRIVER_EN_PIN, !RGB_DRIVER_EN_STATE);
                    rgb_matrix_disable();
                } else {
                    writePin(RGB_DRIVER_EN_PIN, RGB_DRIVER_EN_STATE);
                    rgb_matrix_enable();
                }
            }
            return false;
        } break;
        case KRGB_TOG: {
            if (record->event.pressed) {
                if (confinfo.key_rgb_enable) {
                    confinfo.key_rgb_enable = false;
                } else {
                    confinfo.key_rgb_enable = true;
                }
                eeprom_update_dword((uint32_t *)CONFINFO_EECONFIG_ADDR, confinfo.raw);
                if (!confinfo.logo_rgb_enable && !confinfo.key_rgb_enable) {
                    writePin(RGB_DRIVER_EN_PIN, !RGB_DRIVER_EN_STATE);
                    rgb_matrix_disable();
                } else {
                    writePin(RGB_DRIVER_EN_PIN, RGB_DRIVER_EN_STATE);
                    rgb_matrix_enable();
                }
            }
            return false;
        } break;
        case GU_TOGG: {
            if (record->event.pressed) {
                keymap_config.no_gui = false;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // clear to prevent stuck keys
            }
            return false;
        } break;
        case KC_RIGHT: {
            if (record->event.pressed) {
                if (rgb_test_mode_flag) {
                    rgb_test_mode_color += 1;
                    rgb_test_mode_color %= 4;
                    return false;
                }
            }
            return true;
        } break;
        case KC_DEL: {
            if (record->event.pressed) {
                if (rgb_test_mode_flag) {
                    rgb_test_mode_flag = false;
                    return false;
                }
            }
            return true;
        } break;
        default:
            break;
    }
    return true;
}


bool im_mm_rgb_blink_hook_user(uint8_t index, mm_linker_rgb_t state) {

    if (state != mlrs_none) {
        blink_rgbs_sync = true;
    } else {
        blink_rgbs_sync = false;
    }
    return true;
}

uint32_t full_bat_timer = 0;
uint8_t full_bat_timer_flag = 0;

uint8_t low_pow_timer_c = 0;
uint8_t low_pow_timer_s = 0;
uint32_t low_pow_timer = 0;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (confinfo.logo_rgb_enable != false) {
        if (mm_eeconfig.charging) {
            if (bts_info.bt_info.pvol > 95) {
                if (full_bat_timer_flag == 0) {
                    full_bat_timer_flag = 1;
                    full_bat_timer = timer_read32(); // 开始计时
                }
                if (full_bat_timer_flag == 1 && timer_elapsed32(full_bat_timer) <= 5000) { // 5s内
                    rgb_matrix_set_color(48, RGB_GREEN);
                    rgb_matrix_set_color(49, RGB_GREEN);
                    rgb_matrix_set_color(50, RGB_GREEN);
                    full_bat_timer_flag = 1;
                } else { // 5s外，结束计时
                    logo_rgb_matrix_task();
                    full_bat_timer_flag = 2;
                }
            } else {
                rgb_matrix_set_color(48, RGB_RED);
                rgb_matrix_set_color(49, RGB_RED);
                rgb_matrix_set_color(50, RGB_RED);
                full_bat_timer_flag = 0;
            }
        } else {
            logo_rgb_matrix_task();
            full_bat_timer_flag = 0; // 下次计时用
        }
    } else {
        if (mm_eeconfig.charging) {
            if (bts_info.bt_info.pvol > 95) {
                if (full_bat_timer_flag == 0) {
                    full_bat_timer_flag = 1;
                    full_bat_timer = timer_read32(); // 开始计时
                }
                if (full_bat_timer_flag == 1 && timer_elapsed32(full_bat_timer) <= 5000) { // 5s内
                    rgb_matrix_set_color(48, RGB_GREEN);
                    rgb_matrix_set_color(49, RGB_GREEN);
                    rgb_matrix_set_color(50, RGB_GREEN);
                    full_bat_timer_flag = 1;
                } else { // 5s外，结束计时
                    full_bat_timer_flag = 2;
                    rgb_matrix_set_color(48, 0, 0, 0);
                    rgb_matrix_set_color(49, 0, 0, 0);
                    rgb_matrix_set_color(50, 0, 0, 0);
                }
            } else {
                rgb_matrix_set_color(48, RGB_RED);
                rgb_matrix_set_color(49, RGB_RED);
                rgb_matrix_set_color(50, RGB_RED);
                full_bat_timer_flag = 0;
            }
        } else {
            rgb_matrix_set_color(48, 0, 0, 0);
            rgb_matrix_set_color(49, 0, 0, 0);
            rgb_matrix_set_color(50, 0, 0, 0);
            full_bat_timer_flag = 0;
        }
    }

    if (mm_eeconfig.charging==false && bts_info.bt_info.pvol <= 10) {
        if (low_pow_timer_s == false) {
            low_pow_timer = timer_read32();
            low_pow_timer_c = 0;
        }
        low_pow_timer_s = true;
    } else {
        low_pow_timer_s = false;
    }
    if (low_pow_timer_s == true) {
        if (timer_elapsed32(low_pow_timer) > 1000) {
            low_pow_timer = timer_read32();
            low_pow_timer_c += 1;
            low_pow_timer_c %= 2;
        }
        if (low_pow_timer_c == 0) {
            rgb_matrix_set_color(48, RGB_RED);
            rgb_matrix_set_color(49, RGB_RED);
            rgb_matrix_set_color(50, RGB_RED);
        } else {
            rgb_matrix_set_color(48, 0,0,0);
            rgb_matrix_set_color(49, 0,0,0);
            rgb_matrix_set_color(50, 0,0,0);
        }
    }

    if (confinfo.key_rgb_enable == false && !im_bat_req_flag) {
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
            if (i == 48 || i == 49 || i == 50) {
                continue;
            }
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }

    if (confinfo.swap_wasd) {
        rgb_matrix_set_color(34, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);
        rgb_matrix_set_color(60, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);
        rgb_matrix_set_color(61, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);
        rgb_matrix_set_color(62, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);

        rgb_matrix_set_color(76, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
        rgb_matrix_set_color(77, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
        rgb_matrix_set_color(78, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
        rgb_matrix_set_color(79, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(63, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
    }
    if (keymap_config.no_gui) {
        rgb_matrix_set_color(88, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);
    }

    if (rgb_test_mode_flag) {
        switch (rgb_test_mode_color) {
            case 0: {
                rgb_matrix_set_color_all(125, 125, 125);
            } break;
            case 1: {
                rgb_matrix_set_color_all(125, 0, 0);
            } break;
            case 2: {
                rgb_matrix_set_color_all(0, 125, 0);
            } break;
            case 3: {
                rgb_matrix_set_color_all(0, 0, 125);
            } break;
            default: {
                rgb_matrix_set_color_all(125, 125, 125);
            } break;
        }
        return false;
    }

    if (blink_gui_tog_f) {
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
            if (i == 48 || i == 49 || i == 50) {
                continue;
            }
            rgb_matrix_set_color(i, 0, 0, 0);
        }
        if (blink_gui_tog_tmr == 0 || timer_elapsed32(blink_gui_tog_tmr) >= 300) {
            blink_gui_tog_tmr = timer_read32();
            blink_gui_tog_c += 1;
            blink_gui_tog_c %= 7;
        }
        if (blink_gui_tog_c == 1 || blink_gui_tog_c == 3 || blink_gui_tog_c == 5) {
            rgb_matrix_set_color(88, RGB_MATRIX_MAXIMUM_BRIGHTNESS,0,0);
        } else {
            rgb_matrix_set_color(88, 0,0,0);
        }
        if (blink_gui_tog_c == 6) {
            blink_gui_tog_f = false;
        }
        return false;
    }

    if (blink_win_tog_f) {
        if (blink_win_tog_tmr == 0 || timer_elapsed32(blink_win_tog_tmr) >= 300) {
            blink_win_tog_tmr = timer_read32();
            blink_win_tog_c += 1;
            blink_win_tog_c %= 7;
        }
        if (blink_win_tog_c == 1 || blink_win_tog_c == 3 || blink_win_tog_c == 5) {
            for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
                if (i == 48 || i == 49 || i == 50) {
                    continue;
                }
                rgb_matrix_set_color(i, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
            }
        } else {
            for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
                if (i == 48 || i == 49 || i == 50) {
                    continue;
                }
                rgb_matrix_set_color(i, 0, 0, 0);
            }
        }

        if (blink_win_tog_c == 6) {
            blink_win_tog_f = false;
        }
        return false;
    }

    if (blink_mac_tog_f) {
        if (blink_mac_tog_tmr == 0 || timer_elapsed32(blink_mac_tog_tmr) >= 300) {
            blink_mac_tog_tmr = timer_read32();
            blink_mac_tog_c += 1;
            blink_mac_tog_c %= 7;
        }
        if (blink_mac_tog_c == 1 || blink_mac_tog_c == 3 || blink_mac_tog_c == 5) {
            for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
                if (i == 48 || i == 49 || i == 50) {
                    continue;
                }
                rgb_matrix_set_color(i, 0, 0, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
            }
        } else {
            for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
                if (i == 48 || i == 49 || i == 50) {
                    continue;
                }
                rgb_matrix_set_color(i, 0, 0, 0);
            }
        }

        if (blink_mac_tog_c == 6) {
            blink_mac_tog_f = false;
        }
        return false;
    }

    if (yr_factory_test) {
        if (rgb_t_timer == 0) rgb_t_timer = timer_read32();
        if (timer_elapsed32(rgb_t_timer) > rgb_t_itv) {
            rgb_t_timer = timer_read32();
            rgb_t_pos = (rgb_t_pos + 1) % 3;
        }
        switch (rgb_t_pos) {
            case 0:
                rgb_matrix_set_color_all(rgb_t_v, 0, 0);
                break;
            case 1:
                rgb_matrix_set_color_all(0, rgb_t_v, 0);
                break;
            case 2:
                rgb_matrix_set_color_all(0, 0, rgb_t_v);
            default:
                break;

        }
    }

    return true;
}

bool via_command_yr(uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);
    uint8_t *command_data = &(data[1]);
    if (*command_id == 0x03 && command_data[0] == 0x96) {
        dprintf(">>Recv a pkg with cmd_data1: [%d] cmd_data1: [%d]!!\n", command_data[1], command_data[2]);
        if (command_data[1] == 0x96) { // Factory test
            if (!yr_factory_test) {
                yr_factory_test = true;
            }
        }
        // length = 3;
        if (command_data[2] == 0x96) { // Factory test
            uint8_t check_data = bts_info.bt_info.version;
            dprintf("check_data %d\n", check_data);
            if (check_data < 51) {
                command_data[2] = 0x44;
            }
        }
        raw_hid_send(data, length);
        return true;
    }
    return false;
}
