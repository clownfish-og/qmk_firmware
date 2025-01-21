#include QMK_KEYBOARD_H
#include "rgb_settings.h"
#include "eeprom.h"
#include "via.h"

user_config_t user_config; // Global configuration struct

enum via_hue_value {
    id_capslock_rgb   = 1,
    id_numlock_rgb    = 2,
    id_scrolllock_rgb = 3,
};

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if ( *channel_id == id_custom_channel ) {
        switch (*command_id) {
            case id_custom_set_value:
            {
                user_config_set_rgb(value_id_and_data);
                break;
            }
            case id_custom_get_value:
            {
                user_config_get_rgb(value_id_and_data);
                break;
            }
            case id_custom_save:
            {
                eeconfig_update_user_datablock(&user_config); // Save to EEPROM
                break;
            }
            default:
            {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    *command_id = id_unhandled;
}


// VIA Command Handling
void  user_config_set_rgb(uint8_t *data) {

    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *hsv_data = &(data[1]); // Point to the RGB values

    hsv_t temp_hsv;
    temp_hsv.h = hsv_data[0]; // First byte: Red
    temp_hsv.s = hsv_data[1]; // Second byte: Green

    switch (*value_id) {
        case id_capslock_rgb:
            user_config.caps_lock_hs = temp_hsv;
            break;
        case id_numlock_rgb:
            user_config.num_lock_hs = temp_hsv;
            break;
        case id_scrolllock_rgb:
            user_config.scroll_lock_hs = temp_hsv;
            break;
        default:
            return; // Unknown value ID, do nothing
    }
}

void user_config_get_rgb(uint8_t *data) {
    // data = [ value_id, R, G, B ]
    uint8_t *value_id = &(data[0]);
    uint8_t *hsv_data = &(data[1]); // Destination buffer for RGB data

    hsv_t temp_hsv;

    switch (*value_id) {
        case id_capslock_rgb:
            temp_hsv = user_config.caps_lock_hs;
            break;
        case id_numlock_rgb:
            temp_hsv = user_config.num_lock_hs;
            break;
        case id_scrolllock_rgb:
            temp_hsv = user_config.scroll_lock_hs;
            break;
    }

    hsv_data[0] = temp_hsv.h; // Send Red
    hsv_data[1] = temp_hsv.s; // Send Green
}

// User EEPROM Initialization
void keyboard_post_init_user(void) {
    eeconfig_read_user_datablock(&user_config);
}

