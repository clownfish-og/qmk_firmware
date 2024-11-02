// Copyright 2024 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "wireless.h"
#include "eeconfig.h"

// clang-format off

#undef ___
#define ___ NO_LED

led_config_t g_led_config = {
    {
        {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15},
        {31,  30,  29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16},
        {32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47},
        {63,  62,  61, 60,  59,  58,  57,  56,  55,  54,  53,  52,   NO_LED,  51,   NO_LED,   NO_LED},
        {64,   NO_LED,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,   NO_LED,  75,  76,   NO_LED},
        {89,  88,  87,   NO_LED,  86,   NO_LED,  85,  84,   NO_LED,  83,  82,  81,  80,  79,  78,  77},
    }, {
        {0,0},{15,0},{30,0},{45,0},{60,0},{75,0},{90,0},{105,0},{119,0},{134,0},{149,0},{164,0},{179,0},{194,0},{209,0},{224,0},
        {224,13},{209,13},{194,13},{179,13},{164,13},{149,13},{134,13},{119,13},{105,13},{90,13},{75,13},{60,13},{45,13},{30,13},{15,13},{0,13},
        {0,26},{15,26},{30,26},{45,26},{60,26},{75,26},{90,26},{105,26},{119,26},{134,26},{149,26},{164,26},{179,26},{194,26},{209,26},{224,26},
        {224,38}, {222,38}, {220,38},    {194,38},       {164,38},{149,38},{134,38},{119,38},{105,38},{90,38},{75,38},{60,38},{45,38},{30,38},{15,38},{0,38},
        {0,51},       {30,51},{45,51},{60,51},{75,51},{90,51},{105,51},{119,51},{134,51},{149,51},{164,51},       {194,51},{209,51},
        {224,64},{209,64},{194,64},{179,64},{164,64},{149,64},{134,64},       {105,64},{90,64},       {60,64},       {30,64},{15,64},{0,64}
}, {
    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,

    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,

    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4,
    4,4,4,4,4, 4,4,4,4,4
}};

typedef union {
    uint32_t raw;
    struct {
        uint8_t flag : 1;
        uint8_t devs : 3;
    };
} confinfo_t;
confinfo_t confinfo;

uint32_t post_init_timer = 0x00;
bool inqbat_flag         = false;

/* 只会调用一次 */
void eeconfig_init_kb_datablock(void) {
    confinfo.flag = true;
    confinfo.devs = DEVS_BT1;
    eeconfig_update_kb_datablock(&confinfo);
}

static void bt_scan_mode(void) {
    if (readPin(RF_MODE_SW_PIN) && !readPin(BT_MODE_SW_PIN)) {
        if ((wireless_get_current_devs() == DEVS_USB) || (wireless_get_current_devs() == DEVS_2G4)) {
            wireless_devs_change(wireless_get_current_devs(), confinfo.devs, false);
        }
    }
    if (readPin(BT_MODE_SW_PIN) && !readPin(RF_MODE_SW_PIN)) {
        if (wireless_get_current_devs() != DEVS_2G4) {
            wireless_devs_change(wireless_get_current_devs(), DEVS_2G4, false); // 2_4G mode
        }
    }
    if (readPin(BT_MODE_SW_PIN) && readPin(RF_MODE_SW_PIN)) {
        if (wireless_get_current_devs() != DEVS_USB) wireless_devs_change(wireless_get_current_devs(), DEVS_USB, false); // usb mode
    }
}

void keyboard_post_init_kb(void) {

#ifdef CONSOLE_ENABLE
    debug_enable = true;
#endif

    eeconfig_read_kb_datablock(&confinfo);

#ifdef LED_POWER_EN_PIN
    gpio_set_pin_output(LED_POWER_EN_PIN);
    gpio_write_pin_high(LED_POWER_EN_PIN);
#endif

#ifdef USB_POWER_EN_PIN
    gpio_write_pin_low(USB_POWER_EN_PIN);
    gpio_set_pin_output(USB_POWER_EN_PIN);
#endif

    gpio_set_pin_input_high(BT_MODE_SW_PIN);
    gpio_set_pin_input_high(RF_MODE_SW_PIN);

    wireless_init();
    bt_scan_mode();
    post_init_timer = timer_read32();
    keyboard_post_init_user();
}

void matrix_scan_kb(void) {
    bt_scan_mode();
    matrix_scan_user();
}

void usb_power_connect(void) {
#    ifdef USB_POWER_EN_PIN
    gpio_write_pin_low(USB_POWER_EN_PIN);
#    endif
}

void usb_power_disconnect(void) {
#    ifdef USB_POWER_EN_PIN
    gpio_write_pin_high(USB_POWER_EN_PIN);
#    endif
}

void suspend_power_down_kb(void) {
#    ifdef LED_POWER_EN_PIN
    gpio_write_pin_low(LED_POWER_EN_PIN);
#    endif
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
#    ifdef LED_POWER_EN_PIN
    gpio_write_pin_high(LED_POWER_EN_PIN);
#    endif
    bt_scan_mode();
    suspend_wakeup_init_user();
}

bool lpwr_is_allow_timeout_hook(void) { /* USB 模式不休眠 */
    if (wireless_get_current_devs() == DEVS_USB) {
        return false;
    }
    return true;
}

void wireless_post_task(void) {
    // auto switching devs
    if (post_init_timer && timer_elapsed32(post_init_timer) >= 100) {
        md_send_devctrl(MD_SND_CMD_DEVCTRL_FW_VERSION);   // get the module fw version.
        md_send_devctrl(MD_SND_CMD_DEVCTRL_SLEEP_BT_EN);  // timeout 30min to sleep in bt mode, enable
        md_send_devctrl(MD_SND_CMD_DEVCTRL_SLEEP_2G4_EN); // timeout 30min to sleep in 2.4g mode, enable
        bt_scan_mode();
        post_init_timer = 0x00;
    }
}


uint32_t wls_process_long_press(uint32_t trigger_time, void *cb_arg) {
    uint16_t keycode = *((uint16_t *)cb_arg);

    switch (keycode) {
        case KC_BT1: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_BT1, true);
        } break;
        case KC_BT2: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_BT2, true);
        } break;
        case KC_BT3: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_BT3, true);
        } break;
        case KC_2G4: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_2G4, true);
        } break;
        default:
            break;
    }

    return 0;
}

bool process_record_wls(uint16_t keycode, keyrecord_t *record) {
    static uint16_t keycode_shadow                     = 0x00;
    static deferred_token wls_process_long_press_token = INVALID_DEFERRED_TOKEN;

    keycode_shadow = keycode;

#    ifndef WLS_KEYCODE_PAIR_TIME
#        define WLS_KEYCODE_PAIR_TIME 3000
#    endif

#    define WLS_KEYCODE_EXEC(wls_dev)                                                                                          \
        do {                                                                                                                   \
            if (record->event.pressed) {                                                                                       \
                if (wls_process_long_press_token == INVALID_DEFERRED_TOKEN) {                                                  \
                    wls_process_long_press_token = defer_exec(WLS_KEYCODE_PAIR_TIME, wls_process_long_press, &keycode_shadow); \
                }                                                                                                              \
            } else {                                                                                                           \
                cancel_deferred_exec(wls_process_long_press_token);                                                            \
                wls_process_long_press_token = INVALID_DEFERRED_TOKEN;                                                         \
            }                                                                                                                  \
        } while (false)

    switch (keycode) {
        case KC_BT1: {
            WLS_KEYCODE_EXEC(DEVS_BT1);
        } break;
        case KC_BT2: {
            WLS_KEYCODE_EXEC(DEVS_BT2);
        } break;
        case KC_BT3: {
            WLS_KEYCODE_EXEC(DEVS_BT3);
        } break;
        case KC_2G4: {
            WLS_KEYCODE_EXEC(DEVS_2G4);
        } break;
        case KC_USB: {
            if (record->event.pressed) {
                wireless_devs_change(wireless_get_current_devs(), DEVS_USB, false);
            }
        } break;
        case KC_BATQ: {
            inqbat_flag = record->event.pressed;
        } break;
        default:
            return true;
    }

    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {

    if (process_record_user(keycode, record) != true) {
        return false;
    }

    if (process_record_wls(keycode, record) != true) {
        return false;
    }

    switch (keycode) {
        default:
            return true;
    }

    return false;
}


bool wls_rgb_indicator_reset        = false;
uint32_t wls_rgb_indicator_timer    = 0x00;
uint32_t wls_rgb_indicator_interval = 0;
uint32_t wls_rgb_indicator_times    = 0;
uint32_t wls_rgb_indicator_index    = 0;
RGB wls_rgb_indicator_rgb           = {0};

void rgb_matrix_wls_indicator_set(uint8_t index, uint8_t r, uint8_t g, uint8_t b, uint32_t interval, uint8_t times) {

    wls_rgb_indicator_timer = timer_read32();

    wls_rgb_indicator_index    = index;
    wls_rgb_indicator_interval = interval;
    wls_rgb_indicator_times    = times * 2;
    wls_rgb_indicator_rgb.r      = r;
    wls_rgb_indicator_rgb.g      = g;
    wls_rgb_indicator_rgb.b      = b;
}

void wireless_devs_change_kb(uint8_t old_devs, uint8_t new_devs, bool reset) {

    wls_rgb_indicator_reset = reset;

    if ((wireless_get_current_devs() != DEVS_USB) && (wireless_get_current_devs() != DEVS_2G4)) {
        confinfo.devs = wireless_get_current_devs();
        eeconfig_update_kb_datablock(&confinfo);
    }

    switch (new_devs) {
        case DEVS_BT1: {
            if (reset) {
                rgb_matrix_wls_indicator_set(30, RGB_GREEN, 200, 1);
            } else {
                rgb_matrix_wls_indicator_set(30, RGB_GREEN, 500, 1);
            }
        } break;
        case DEVS_BT2: {
            if (reset) {
                rgb_matrix_wls_indicator_set(29, RGB_GREEN, 200, 1);
            } else {
                rgb_matrix_wls_indicator_set(29, RGB_GREEN, 500, 1);
            }
        } break;
        case DEVS_BT3: {
            if (reset) {
                rgb_matrix_wls_indicator_set(28, RGB_GREEN, 200, 1);
            } else {
                rgb_matrix_wls_indicator_set(28, RGB_GREEN, 500, 1);
            }
        } break;
        case DEVS_2G4: {
            if (reset) {
                rgb_matrix_wls_indicator_set(27, RGB_BLUE, 200, 1);
            } else {
                rgb_matrix_wls_indicator_set(27, RGB_BLUE, 500, 1);
            }
        } break;
        default:
            break;
    }
}

bool rgb_matrix_wls_indicator_cb(void) {

    if (*md_getp_state() != MD_STATE_CONNECTED) {
        wireless_devs_change_kb(wireless_get_current_devs(), wireless_get_current_devs(), wls_rgb_indicator_reset);
        return true;
    }

    // refresh led
    led_wakeup();

    return false;
}

void rgb_matrix_wls_indicator(void) {

    if (wls_rgb_indicator_timer) {

        if (timer_elapsed32(wls_rgb_indicator_timer) >= wls_rgb_indicator_interval) {
            wls_rgb_indicator_timer = timer_read32();

            if (wls_rgb_indicator_times) {
                wls_rgb_indicator_times--;
            }

            if (wls_rgb_indicator_times <= 0) {
                wls_rgb_indicator_timer = 0x00;
                if (rgb_matrix_wls_indicator_cb() != true) {
                    return;
                }
            }
        }

        if (wls_rgb_indicator_times % 2) {
            rgb_matrix_set_color(wls_rgb_indicator_index, wls_rgb_indicator_rgb.r, wls_rgb_indicator_rgb.g, wls_rgb_indicator_rgb.b);
        } else {
            rgb_matrix_set_color(wls_rgb_indicator_index, 0x00, 0x00, 0x00);
        }
    }

    if (inqbat_flag) {
        rgb_matrix_set_color_all(0x00, 0x00, 0x00);
        for (uint8_t i = 0; i < 10; i++) {
            uint8_t mi_index[10] = RGB_MATRIX_BAT_INDEX_MAP;
            if (i < (*md_getp_bat() / 10)) {
                if (*md_getp_bat() >= 50) {
                    rgb_matrix_set_color(mi_index[i], RGB_GREEN);
                } else if (*md_getp_bat() >= 30) {
                    rgb_matrix_set_color(mi_index[i], RGB_YELLOW);
                } else {
                    rgb_matrix_set_color(mi_index[i], RGB_RED);
                }
            } else {
                rgb_matrix_set_color(mi_index[i], 0x00, 0x00, 0x00);
            }
        }
    }

}


bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {

    if (rgb_matrix_indicators_advanced_user(led_min, led_max) != true) {
        return false;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(63, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
    }
    if (keymap_config.no_gui) {
        rgb_matrix_set_color(88, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);
    }

    rgb_matrix_wls_indicator();

    return true;
}
