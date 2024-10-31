#include "logo_rgbm.h"
#include "rgb_matrix.h"
#include "eeprom.h"
#include <math.h>
#include <lib/lib8tion/lib8tion.h>
#include <stdint.h>

static logo_rgb_matrix_config_t logo_rgb_matrix_config;


HSV logo_rgb_hsv = {255,255,255};
uint8_t logo_rgb_speed = 125;

void eeconfig_update_logo_rgb_matrix_default(void) {
    logo_rgb_matrix_config.flag = true;
    logo_rgb_matrix_config.mode = 1;
    logo_rgb_speed = 125;
    logo_rgb_hsv.h = 255;
    logo_rgb_hsv.s = 255;
    logo_rgb_hsv.v = 255;
    eeprom_update_dword((uint32_t *)LOGORGB_EECONFIG_ADDR, logo_rgb_matrix_config.raw);
}

void logo_rgb_matrix_init(void) {
    logo_rgb_matrix_config.raw = eeprom_read_dword((uint32_t *)LOGORGB_EECONFIG_ADDR);
    if (!logo_rgb_matrix_config.raw) {
        eeconfig_update_logo_rgb_matrix_default();
    }
}

void CycleIMath(uint8_t time, bool sync) {
    for (uint8_t i = 48; i < 51; i++) {
        HSV hsv = logo_rgb_hsv;
        hsv.h = time;
        if (sync) {
            hsv.h += (i-48)*60;
            hsv.h %= 255;
        }
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}

static uint8_t is_breathing_highest = 1;
static uint8_t is_breathing_lowest = 1;
static uint8_t hue_index = 0;
static uint8_t val_index = 0;
static uint8_t hue_stepper = 0;
void CycleBreathingMath(uint16_t time) {
    HSV hsv = logo_rgb_hsv;
    hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    if (is_breathing_lowest){
        val_index = hsv.v;
        hue_index = hue_stepper;
        hue_stepper += 8;
        is_breathing_lowest ^= 1;
    } else {
        if (hsv.v >= val_index && is_breathing_highest) {
            is_breathing_highest ^= 1;
        } else {
            if (hsv.v <= 0 && !is_breathing_highest) {
                is_breathing_highest ^= 1;
                is_breathing_lowest  ^= 1;
            }
        }
    }
    hsv.h = hue_index;
    RGB rgb       = hsv_to_rgb(hsv);
    for (uint8_t i = 48; i < 51; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}

void CycleAll(bool sync) {
    uint8_t time = g_rgb_timer * qadd8(logo_rgb_speed / 4, 1) / 256;
    CycleIMath(time, sync);
}

void CycleBreathing(void) {
    uint16_t time = g_rgb_timer * (logo_rgb_speed / 8) / 256;
    CycleBreathingMath(time);
}

void StaticColor(uint8_t r, uint8_t g, uint8_t b) {
    RGB rgb = {r, g, b};
    for (uint8_t i = 48; i < 51; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}

void logo_rgb_mode_step(void) {
    logo_rgb_matrix_config.mode += 1;
    logo_rgb_matrix_config.mode %= 8;
    eeprom_update_dword((uint32_t *)LOGORGB_EECONFIG_ADDR, logo_rgb_matrix_config.raw);
}

uint8_t get_logo_rgb_mode(void) {
    return logo_rgb_matrix_config.mode;
}

void logo_rgb_matrix_task(void) {
    switch (logo_rgb_matrix_config.mode)
    {
        case 0: // off
            StaticColor(RGB_OFF);
        case 1:
            CycleBreathing();
            break;
        case 2:
            CycleAll(false);
            break;
        case 3:
            CycleAll(true);
            break;
        case 4:
            StaticColor(RGB_YELLOW);
            break;
        case 5:
            StaticColor(RGB_CYAN);
            break;
        case 6:
            StaticColor(RGB_PINK);
            break;
        case 7:
            StaticColor(RGB_WHITE);
            break;
        default:
            StaticColor(RGB_OFF);
            break;
    }
}
