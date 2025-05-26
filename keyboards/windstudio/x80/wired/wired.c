/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "wired.h"

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                        rgb_matrix_set_color(0, RGB_RED);
                        rgb_matrix_set_color(1, RGB_RED);
				        rgb_matrix_set_color(2, RGB_RED);
            }
        }
    }
	return false;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


uint8_t mod_state;
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    mod_state = get_mods();
    switch(keycode) {
        case MKC_LG:
            if (record->event.pressed) {
                process_magic(GU_TOGG, record);
            }
            return false;
        case MKC_MACOS:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << 2);
            }
            return false;
        case MKC_WIN:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << 0);
            }
            return false;
        case MKC_SWCG:
            if (record->event.pressed) {
                process_magic(CG_TOGG, record);
            }
            return false;
        case MKC_AB:
            {
                static bool lt_registered;
                static bool gt_registered;
                if (record->event.pressed) {
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                        register_code16(KC_LT);
                        lt_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        gt_registered = true;
                        register_code16(KC_GT);
                        return false;
                    }
                } else {
                    if (lt_registered) {
                        unregister_code16(KC_LT);
                        lt_registered = false;
                        return false;
                    }
                    if (gt_registered) {
                        unregister_code16(KC_GT);
                        gt_registered = false;
                        return false;
                    }
                }
                return false;
            }
        case MKC_MCTL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;
        case MKC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;
        case MKC_LCOMM:
            if (record->event.pressed) {
                register_code(KC_LCMD);
            } else {
                unregister_code(KC_LCMD);
            }
            return false;
        case MKC_RCOMM:
            if (record->event.pressed) {
                register_code(KC_RCMD);
            } else {
                unregister_code(KC_RCMD);
            }
            return false;
        case MKC_LOPT:
            if (record->event.pressed) {
                register_code(KC_LOPT);
            } else {
                unregister_code(KC_LOPT);
            }
            return false;
        case MKC_ROPT:
            if (record->event.pressed) {
                register_code(KC_ROPT);
            } else {
                unregister_code(KC_ROPT);
            }
            return false;
        default:
            return true;
    }
    return true;
}
