/* Copyright 2024 Gondolindrim
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

#include "quantum.h"
#include "hotswap.h"
#include "lib/lib8tion/lib8tion.h"

// Track which LED to use for caps lock (false = LED 0, true = LED 1)
static bool caps_led_toggle = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case CAPS_LT:
            if (record->event.pressed) {
                caps_led_toggle = !caps_led_toggle;
            }
            return false;
        case UG_BREATH:
            if (record->event.pressed) {
                // Toggle between solid (mode 1) and breathing (mode 2)
                uint8_t current_mode = rgb_matrix_get_mode();
                if (current_mode == 2) {
                    rgb_matrix_mode(1); // Switch to solid
                } else {
                    rgb_matrix_mode(2); // Switch to breathing
                }
            }
            return false;
    }
    return true;
}

void keyboard_post_init_kb(void) {
    rgb_matrix_set_color_all(RGB_BLACK);
    keyboard_post_init_user();
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    hsv_t hsv = {rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val()};

    // Check if breathing mode is active (mode 1)
    bool breathing_active = (rgb_matrix_get_mode() == 2);
    uint8_t time = 0;

    if (breathing_active) {
        // Breathing effect parameters (only calculate if needed)
        time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_get_speed() / 4, 1));
    }

    // Handle caps lock indication on LED 0 or 1 based on toggle state
    uint8_t caps_led = caps_led_toggle ? 1 : 0;
    uint8_t other_led = caps_led_toggle ? 0 : 1;

    if (host_keyboard_led_state().caps_lock) {
        if (breathing_active) {
            // Apply breathing effect to caps lock LED
            hsv_t breathing_hsv = hsv;
            breathing_hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
            rgb_t breathing_rgb = hsv_to_rgb(breathing_hsv);

            rgb_matrix_set_color(caps_led, breathing_rgb.r, breathing_rgb.g, breathing_rgb.b);
        } else {
            // Solid color for caps lock LED
            rgb_t rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(caps_led, rgb.r, rgb.g, rgb.b);
        }
        rgb_matrix_set_color(other_led, RGB_BLACK);
    } else {
        rgb_matrix_set_color(0, RGB_BLACK);
        rgb_matrix_set_color(1, RGB_BLACK);
    }

    // Handle num lock indication on LED 2
    if (host_keyboard_led_state().num_lock) {
        if (breathing_active) {
            // Apply breathing effect to num lock LED
            hsv_t breathing_hsv = hsv;
            breathing_hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
            rgb_t breathing_rgb = hsv_to_rgb(breathing_hsv);

            rgb_matrix_set_color(2, breathing_rgb.r, breathing_rgb.g, breathing_rgb.b);
        } else {
            // Solid color for num lock LED
            rgb_t rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b);
        }
    } else {
        rgb_matrix_set_color(2, RGB_BLACK);
    }

    return true;
}
