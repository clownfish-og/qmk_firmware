/* Copyright 2024 ClownFish (@clownfish-og)
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

#include QMK_KEYBOARD_H
#include <ctype.h>
#include "keymap.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(  // wertyoo commands
        MAINSC,  WELCOME, BRB,     SMALL,   VINYL,
        NEW,     SLOTHS,  GYPSY,   NINJA,   STRAT,
        _JAMMIN, _GLUTES, _WIGGLE, _CLNFSH, _BONGO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TO(3),   KC_NO,   KC_NO,   KC_NO,   KC_ENT
    ),
    [1] = LAYOUT(  // wertyoo emotes
        APPROVE, AYO,     BONGO,   CHEF,    CLOWNFISH,
        COOL,    DOIT,    DANCE,   EXCITE,  GIFT,
        GLUTES,  HIYA,    HORN,    HUG,     HEARTBEAT,
        HYPE,    JAMMIN,  WIGGLE,  GRIN,    FIRESAUCE,
        TO(0),   TUNE,    WAVE,    CAPGEN5, KC_ENT
    ),
    [2] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [3] = LAYOUT(  // RGB settings
        TO(0),   TO(1),   TO(2),   KC_NO,   KC_NO,
        UG_NEXT, UG_VALU, UG_HUEU, UG_SATU, UG_SPDU,
        UG_PREV, UG_VALD, UG_HUED, UG_SATD, UG_SPDD,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TT(4),   RMAM,    RMPL,    RMSW,    UG_TOGG
    ),
    [4] = LAYOUT(  // Numpad
        TO(0),   KC_NUM,  KC_PSLS, KC_PAST, KC_BSPC,
        KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_NO,
        KC_TRNS, KC_P0,   KC_P0,   KC_PDOT, KC_PENT
    ),
};

const char approve[] PROGMEM = "wertyo2Approve ";
const char ayo[] PROGMEM = "wertyo2Ayo ";
const char bongo[] PROGMEM = "wertyo2Bongo ";
const char chef[] PROGMEM = "wertyo2ChefsKiss ";
const char clownfish[] PROGMEM = "wertyo2Clownfish ";
const char cool[] PROGMEM = "wertyo2Cool ";
const char doit[] PROGMEM = "wertyo2DOIT ";
const char dance[] PROGMEM = "wertyo2Dance ";
const char excite[] PROGMEM = "wertyo2Excite ";
const char gift[] PROGMEM = "wertyo2Gift ";
const char glutes[] PROGMEM = "wertyo2Glutes ";
const char heartbeat[] PROGMEM = "wertyo2Heartbeat ";
const char hiya[] PROGMEM = "wertyo2Hiya ";
const char horn[] PROGMEM = "wertyo2Horn ";
const char hug[] PROGMEM = "wertyo2Hug ";
const char hype[] PROGMEM = "wertyo2Hype ";
const char jammin[] PROGMEM = "wertyo2Jammin ";
const char wiggle[] PROGMEM = "wertyo2Wiggle ";
const char firesauce[] PROGMEM = "wertyo2FireSauce ";
const char grin[] PROGMEM = "wertyo2Grin ";
const char heart[] PROGMEM = "wertyo2Heart ";
const char tune[] PROGMEM = "wertyo2Tune ";
const char wave[] PROGMEM = "wertyo2Wave ";
const char bop[] PROGMEM = "BOP ";
const char bopbop[] PROGMEM = "BopBop ";
const char dinodance[] PROGMEM = "DinoDance ";
const char glitchlit[] PROGMEM = "GlitchLit ";
const char goatemotey[] PROGMEM = "GoatEmotey ";
const char goldplz[] PROGMEM = "GoldPLZ ";
const char kappa[] PROGMEM = "Kappa ";
const char kreygasm[] PROGMEM = "Kreygasm ";
const char modlove[] PROGMEM = "ModLove";
const char notlikethis[] PROGMEM = "NotLikeThis ";
const char powerupl[] PROGMEM = "PowerUpL ";
const char powerupr[] PROGMEM = "PowerUpR ";
const char singsmic[] PROGMEM = "SingsMic ";
const char singsnote[] PROGMEM = "SingsNote ";
const char stinkycheese[] PROGMEM = "StinkyCheese ";
const char tombraider[] PROGMEM = "TombRaid ";
const char twitchconhype[] PROGMEM = "TwitchConHYPE ";
const char twitchlit[] PROGMEM = "TwitchLit ";
const char twitchraid[] PROGMEM = "twitchRaid ";
const char unity[] PROGMEM = "TwitchUnity ";
const char mainscene[] PROGMEM = "!main";
const char welcome[] PROGMEM = "!welcome";
const char brb[] PROGMEM = "!break";
const char small[] PROGMEM = "!small";
const char vinyl[] PROGMEM = "!vinyl";
const char new[] PROGMEM = "!newvisual";
const char sloths[] PROGMEM = "!sloths";
const char gypsy[] PROGMEM = "!gypsy";
const char ninja[] PROGMEM = "!ninja";
const char stratus[] PROGMEM = "!stratus";
const char v_jammin[] PROGMEM = "!jammin";
const char v_glutes[] PROGMEM = "!glutes";
const char v_wiggle[] PROGMEM = "!wiggle";
const char v_clownfish[] PROGMEM = "!clownfish";
const char v_bongo[] PROGMEM = "!bongo";

PGM_P const suffix[] PROGMEM = {
    approve,
    ayo,
    bongo,
    chef,
    clownfish,
    cool,
    doit,
    dance,
    excite,
    gift,
    glutes,
    heartbeat,
    hiya,
    horn,
    hug,
    hype,
    jammin,
    wiggle,
    firesauce,
    grin,
    heart,
    tune,
    wave,
    bop,
    bopbop,
    dinodance,
    glitchlit,
    goatemotey,
    goldplz,
    kappa,
    kreygasm,
    modlove,
    notlikethis,
    powerupl,
    powerupr,
    singsmic,
    singsnote,
    stinkycheese,
    tombraider,
    twitchconhype,
    twitchlit,
    twitchraid,
    unity,
    mainscene,
    welcome,
    brb,
    small,
    vinyl,
    new,
    sloths,
    gypsy,
    ninja,
    stratus,
    v_jammin,
    v_glutes,
    v_wiggle,
    v_clownfish,
    v_bongo
};

const int first_emote = FIRST_EMOTE;
const int last_emote = LAST_EMOTE;

// This function inverts the capitalization of each character in the given string.
void invert_caps(char *str) {
    while (*str) {
        if (islower(*str)) {
            *str = toupper(*str);
        } else if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case FIRST_EMOTE ... LAST_EMOTE: {
                uint8_t i = keycode - FIRST_EMOTE;
                bool caps = host_keyboard_led_state().caps_lock;
                char emote_buffer[36];
                emote_buffer[0] = '\0';
                strncpy_P(emote_buffer, (PGM_P)pgm_read_ptr(&(suffix[i])), sizeof(emote_buffer) - 2);
                if (caps) {
                    invert_caps(emote_buffer);
                }
                send_string(emote_buffer);
                return false;
            }
        }
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //  Define an assortment of HSV values for indicators and convert HSV to RGB (important for limiting brightness with WS2812)
    rgb_t rgb0 = hsv_to_rgb((hsv_t){200, 255, 200});                    // MAGENTA
    rgb_t rgb2 = hsv_to_rgb((hsv_t){170, 255, 200});                    // BLUE
    rgb_t rgb2v = hsv_to_rgb((hsv_t){170, 255, rgb_matrix_get_val()});  // BLUE - BRIGHTNESS VARIES
    rgb_t rgb3 = hsv_to_rgb((hsv_t){85, 255, 200});                     // GREEN
    rgb_t rgb3v = hsv_to_rgb((hsv_t){85, 255, rgb_matrix_get_val()});   // GREEN - BRIGHTNESS VARIES
    rgb_t rgb5 = hsv_to_rgb((hsv_t){0, 255, 200});                      // RED
    rgb_t rgb5v = hsv_to_rgb((hsv_t){0, 255, rgb_matrix_get_val()});    // RED - BRIGHTNESS VARIES
    rgb_t rgb6 = hsv_to_rgb((hsv_t){0, 0, 200});                        // WHITE
    rgb_t rgb6v = hsv_to_rgb((hsv_t){0, 0, rgb_matrix_get_val()});      // WHITE - BRIGHTNESS VARIES

        // Determine the active layer
        uint8_t active_layer = get_highest_layer(layer_state);

        if (!rgb_matrix_get_flags()) {  // RGB is toggled off
            rgb_matrix_set_color_all(RGB_BLACK);
        }

    /*
    keylight LED index to position legend
    -----------------------
    | 20 |21 |22 |23 | 24 |
    -----------------------
    | 19 | 6 | 7 | 8 | 9  |
    -----------------------
    | 18 | 5 | 0 | 1 | 10 |
    -----------------------
    | 17 | 4 | 3 | 2 | 11 |
    -----------------------
    | 16 |15 |14 |13 | 12 |
    -----------------------
    */

    // Set indicator LEDs
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (active_layer) {
            case 0:
                break;
            case 1:
                rgb_matrix_set_color(12, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW GREEN
                rgb_matrix_set_color(13, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW GREEN
                rgb_matrix_set_color(14, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW GREEN
                rgb_matrix_set_color(15, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW GREEN
                rgb_matrix_set_color(16, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW GREEN
                break;
            case 2:
                rgb_matrix_set_color(12, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                rgb_matrix_set_color(13, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                rgb_matrix_set_color(14, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                rgb_matrix_set_color(15, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                rgb_matrix_set_color(16, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                break;
            case 3:                                             // RGB SETTINGS LAYER
                rgb_matrix_set_color(16, rgb5v.r, rgb5v.g, rgb5v.b);  // TT(6) RED - BRIGHTNESS VARIES
                rgb_matrix_set_color(20, rgb5.r, rgb5.g, rgb5.b);     // TOP ROW RED
                rgb_matrix_set_color(21, rgb5.r, rgb5.g, rgb5.b);     // TOP ROW RED
                rgb_matrix_set_color(22, rgb5.r, rgb5.g, rgb5.b);     // TOP ROW RED
                rgb_matrix_set_color(23, rgb5.r, rgb5.g, rgb5.b);     // TOP ROW RED
                rgb_matrix_set_color(24, rgb5.r, rgb5.g, rgb5.b);     // TOP ROW RED
                break;
            case 4:                                             // NUMPAD LAYER
                if (!host_keyboard_led_state().num_lock) {          // NUMLOCK OFF
                    rgb_matrix_set_color_all(rgb2v.r, rgb2v.g, rgb2v.b);  // ALL BLUE - BRIGHTNESS VARIES
                    rgb_matrix_set_color(21, rgb6.r, rgb6.g, rgb6.b);     // NUMLOCK WHITE
                    rgb_matrix_set_color(1, rgb3v.r, rgb3v.g, rgb3v.b);   // ARROW KEYS GREEN
                    rgb_matrix_set_color(3, rgb3v.r, rgb3v.g, rgb3v.b);   // ARROW KEYS GREEN
                    rgb_matrix_set_color(5, rgb3v.r, rgb3v.g, rgb3v.b);   // ARROW KEYS GREEN
                    rgb_matrix_set_color(7, rgb3v.r, rgb3v.g, rgb3v.b);   // ARROW KEYS GREEN
                    rgb_matrix_set_color(20, rgb0.r, rgb0.g, rgb0.b);     // TO(0) MAGENTA
                    rgb_matrix_set_color(19, RGB_BLACK);                  // LEFT COLUMN BLACK
                    rgb_matrix_set_color(18, RGB_BLACK);                  // LEFT COLUMN BLACK
                    rgb_matrix_set_color(17, RGB_BLACK);                  // LEFT COLUMN BLACK
                    rgb_matrix_set_color(16, rgb5v.r, rgb5v.g, rgb5v.b);  // TT(6) RED - BRIGHTNESS VARIES
                } else {                                            // NUMLOCK ON
                    rgb_matrix_set_color_all(rgb6v.r, rgb6v.g, rgb6v.b);  // ALL WHITE - BRIGHTNESS VARIES
                    rgb_matrix_set_color(21, rgb2.r, rgb2.g, rgb2.b);  // NUMLOCK BLUE
                    rgb_matrix_set_color(20, rgb0.r, rgb0.g, rgb0.b);     // TO(0) MAGENTA
                    rgb_matrix_set_color(19, RGB_BLACK);                  // LEFT COLUMN BLACK
                    rgb_matrix_set_color(18, RGB_BLACK);                  // LEFT COLUMN BLACK
                    rgb_matrix_set_color(17, RGB_BLACK);                  // LEFT COLUMN BLACK
                    rgb_matrix_set_color(16, rgb5v.r, rgb5v.g, rgb5v.b);  // TT(6) RED - BRIGHTNESS VARIES
                }
                break;
            default:
                rgb_matrix_set_color_all(RGB_BLACK);
                break;
        }
    }
    return false;
}

#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) {
    return mod;
}
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
#endif
