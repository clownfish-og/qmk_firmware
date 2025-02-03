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
    [0] = LAYOUT(
        TO(1),      CHEESE,     AMNESIA,    GROOVY,     DUCKDANCE,
        DISCO,      DIDDY,      CATDANCE,   SLAY,       BEARDDANCE,
        PATBANG,    FREAKOUT,   DRUMS,      FROG,       KEKW,
        BACKDOOR,   LOVE,       THANKS,     ZEJIBO,     BUG,
        BITS,       MOOSE,      BUP,        CAPGEN5,    KC_ENT
    ),
    [1] = LAYOUT(
        TO(0),      TO(5),      TO(2),      TO(3),      TO(4),
        WATER,      DONUT,      DYE,        SMIRK,      EXCUSEME,
        RUMP,       TINFOIL,    CLOUDS,     SALT,       WINK,
        BALLOON,    HEART,      ASCEND,     JELLY,      PLUG,
        RAVE,       CROWN,      TIEDYE,     DRAGON,     SUS
    ),
    [2] = LAYOUT(
        TO(0),      TO(1),      TO(5),      TO(3),      TO(4),
        DUCKHEAD,   WIZ,        CHEFKISS,   MAPLE,      BIGBRAIN,
        CALL,       DOIT,       GROGU,      JAWNESSA,   BART,
        BUPS,       BROC,       BUPWAD,     LUIGIBUP,   ZELDABUP,
        AYO,        TUNE,       SH,         EE,         ID
    ),
    [3] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(5),      TO(4),
        BASSSFACE,   BOB,        LIGHTER,    UWU,        UP,
        NOD,        GOOSE,      BOOMER,     WUB,        WOOK,
        HEADOUT,    RAINBOW,    SALUTE,     SWEATY,     HORN,
        FLUTE,      FIRE,       CHEERS,     KEYS,       CHILLGUY
    ),
    [4] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(3),      TO(5),
        BDANCE,     BMINGO,     BMONKEY,    BPUG,       BUGH,
        KGLUTES,    KHI,        KHUG,       KLEI,       KLOVE,
        KCLAP,      KGATO,      KGGS,       KRDNC,      KSMUG,
        BOPBOP,     DINODANCE,  UNITY,      KAPPA,      TOMBRAID
    ),
    [5] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(3),      TO(4),
        RGB_MOD,    RGB_VAI,    RGB_HUI,    RGB_SAI,    RGB_SPI,
        RGB_RMOD,   RGB_VAD,    RGB_HUD,    RGB_SAD,    RGB_SPD,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        RGB_M_P,    RGB_M_B,    RGB_M_R,    RGB_M_SW,   RGB_TOG
    ),
};



    const char *suffix[] = {
    "Amnesia",
    "Ayo",
    "BackDoor",
    "Balloon",
    "Bart",
    "BEARDDANCE",
    "BigBrain",
    "BITS",
    "BOOMER",
    "Bug",
    "BUP",
    "BUPS",
    "BUPWAD",
    "Call",
    "CATDANCE",
    "CHEERS",
    "Cheese",
    "Chefkiss",
    "Crown",
    "Diddy",
    "Disco",
    "DOIT",
    "Donut",
    "Drums",
    "DUCKDANCE",
    "Duckhead",
    "Dye",
    "EE",
    "Fire",
    "FLUTE",
    "Freakout",
    "FROG",
    "Grogu",
    "Groovy",
    "HEADOUT",
    "HORN",
    "ID",
    "Kekw",
    "KEYS",
    "Lighter",
    "LOVE",
    "LUIGIBUP",
    "MOOSE",
    "PATBANG",
    "Plug",
    "Salute",
    "Sh",
    "Slay",
    "Sweaty",
    "THANKS",
    "WOOK",
    "WUB",
    "Zejibo",
    "ZELDABUP",
    "Broc",
    "Clouds",
    "Goose",
    "Heart",
    "JAWNESSA",
    "Rave",
    "Salt",
    "TINFOIL",
    "Water",
    "Wiz",
    "BASSSFACE",
    "BOB",
    "Chillguy",
    "Dragon",
    "Jelly",
    "Maple",
    "Rump",
    "Smirk",
    "UWU",
    "Wink",
    "AbDUCKtion",
    "Ascend",
    "ASHDUCKEM",
    "EXCUSEME",
    "FANCYDUCK",
    "Gold",
    "HEADPHONES",
    "KTULUEHUG",
    "RAINBOW",
    "Smug",
    "Sus",
    "Nod",
    "TIEDYE",
    "TUNE",
    "Up",
    "WAVE",
    "BOP",
    "BopBop",
    "DinoDance",
    "GlitchLit",
    "GoatEmotey",
    "GoldPLZ",
    "Kappa",
    "Kreygasm",
    "ModLove",
    "NotLikeThis",
    "PowerUpL",
    "PowerUpR",
    "SingsMic",
    "SingsNote",
    "StinkyCheese",
    "TombRaid",
    "TwitchConHYPE",
    "TwitchLit",
    "twitchRaid",
    "TwitchUnity",
    "VoteNay",
    "VoteYea",
    "Dance",
    "Mingo",
    "Monkey",
    "Pug",
    "Ugh",
    "Clap",
    "Gato",
    "GGs",
    "GLUTES",
    "HI",
    "HUG",
    "Lei",
    "Love",
    "Rdnc",
    "SMUG"
};

#define FIRST_EMOTE AMNESIA
#define LAST_EMOTE KSMUG
const int start_bup = AMNESIA;
const int end_bup = WAVE;
const int start_bex = BDANCE;
const int end_bex = BUGH;
const int start_ktlu = KCLAP;
const int end_ktlu = KSMUG;
const int first_emote = FIRST_EMOTE;
const int last_emote = LAST_EMOTE;

const char bup_p[] = "bup";
const char bex_p[] = "bexfro";
const char ktlu_p[] = "ktulue";

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

bool process_record_bup(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case CAPGEN5:
                SEND_STRING(SS_LCTL("acvvvvv"));
                return false;
            case CAPGEN8:
                SEND_STRING(SS_LCTL("acvvvvvvvv"));
                return false;
            case CAPGEN10:
                SEND_STRING(SS_LCTL("acvvvvvvvvvv"));
                return false;
            case FIRST_EMOTE ... LAST_EMOTE: {
                bool caps = host_keyboard_led_state().caps_lock;
                uint8_t i = keycode - first_emote;
                uprintf("i: %d\n", i);
                char emote_buffer[40];
                uprintf("Size of emote_buffer: %d\n", sizeof(emote_buffer));
                emote_buffer[0] = '\0';

                if (start_bup <= keycode && keycode <= end_bup) {  // Most keycodes use the bup prefix
                    strncpy(emote_buffer, bup_p, sizeof(emote_buffer));  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix[i]);                     // append suffix to buffer
                } else if (start_bex <= keycode && keycode <= end_bex) {   // Handle Bex keycodes
                    strncpy(emote_buffer, bex_p, sizeof(emote_buffer));  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix[i]);                     // append suffix to buffer
                } else if (start_ktlu <= keycode && keycode <= end_ktlu) {  // Handle Ktulue keycodes
                    strncpy(emote_buffer, ktlu_p, sizeof(emote_buffer));  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix[i]);                     // append suffix to buffer
                } else {
                    strncpy(emote_buffer, suffix[i], sizeof(emote_buffer));  // Non-prefixed keycodes
                }

                // Debug output
                uprintf("Keycode: %u, Suffix: %s, Emote: %s\n", keycode, suffix[i], emote_buffer);

                if (caps) {
                    invert_caps(emote_buffer);
                }

                // Append a space and send the emote
                strcat(emote_buffer, " ");
                send_string(emote_buffer);
                uprintf("Keycode: %u, Output: %s\n", keycode, emote_buffer);
                return false;
            }
            default:
                break;
        }
    }
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_bup(keycode, record)) {
        return false;
    }

    return true;
}
#ifdef MAGIC_ENABLE
#undef MAGIC_ENABLE
#endif
#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif
#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
#endif
