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
#include "keymap.h"
#include <ctype.h>
#include <stdlib.h>

#include "quantum.h"

keycode_string_t keycode_strings[] = {
    {CAPGEN5, SS_LCTL("acvvvvv")},
    {CAPGEN8, SS_LCTL("acvvvvvvvv")},
    {CAPGEN10, SS_LCTL("acvvvvvvvvvv")},
    {ACID, "bupAcid "},
    {ASCEND, "bupAscend "},
    {AYO, "bupAyo "},
    {BACKDOOR, "bupBackDoor "},
    {BALLOON, "bupBalloon "},
    {BART, "bupBart "},
    {BASSFACE, "bupBASSSFACE "},
    {BEARDDANCE, "bupBEARDDANCE "},
    {BIGBRAIN, "bupBigBrain "},
    {BITS, "bupBITS "},
    {BOB, "bupBOB "},
    {BOOMER, "bupBOOMER "},
    {BROC, "bupBroc "},
    {BUG, "bupBug "},
    {BUP, "bupBUP "},
    {BUPS, "bupBUPS "},
    {BUPWAD, "bupBUPWAD "},
    {CALL, "bupCall "},
    {CATDANCE, "bupCATDANCE "},
    {CHEERS, "bupCHEERS "},
    {CHEESE, "bupCheese "},
    {CHEFKISS, "bupChefkiss "},
    {CLOUDS, "bupClouds "},
    {CROWN, "bupCrown "},
    {DIDDY, "bupDiddy "},
    {DISCO, "bupDisco "},
    {DOIT, "bupDOIT "},
    {DONUT, "bupDonut "},
    {DRAGON, "bupDragon "},
    {DRUMS, "bupDrums "},
    {DUCKDANCE, "bupDUCKDANCE "},
    {DUCKHEAD, "bupDuckhead "},
    {DYE, "bupDye "},
    {EE, "bupEE "},
    {EYE, "bupEye "},
    {FIRE, "bupFire "},
    {FLUTE, "bupFLUTE "},
    {FREAKOUT, "bupFreakout "},
    {FROG, "bupFROG "},
    {GLUTES, "bupGlutes "},
    {GOOSE, "bupGoose "},
    {GROGU, "bupGrogu "},
    {HEADOUT, "bupHEADOUT "},
    {HEART, "bupHeart "},
    {HORN, "bupHORN "},
    {ID, "bupID "},
    {JAWNESSA, "bupJAWNESSA "},
    {JELLY, "bupJelly "},
    {KEKW, "bupKekw "},
    {KEYS, "bupKEYS "},
    {LIGHTER, "bupLighter "},
    {LOVE, "bupLOVE "},
    {MOOSE, "bupMOOSE "},
    {NOD, "bupNod "},
    {PATBANG, "bupPATBANG "},
    {PLUG, "bupPlug "},
    {RAINBOW, "bupRAINBOW "},
    {RAVE, "bupRave "},
    {REVERSE, "bupReverse "},
    {RUMP, "bupRump "},
    {SABER, "bupSABER "},
    {SALUTE, "bupSalute "},
    {SH, "bupSh "},
    {SLAY, "bupSlay "},
    {SMIRK, "bupSmirk "},
    {SPOOKY, "bupSpooky "},
    {SWEATY, "bupSweaty "},
    {THANKS, "bupTHANKS "},
    {THING, "bupThing "},
    {TIEDYE, "bupTIEDYE "},
    {TINFOIL, "bupTINFOIL "},
    {UP, "bupUp "},
    {UWU, "bupUWU "},
    {WATER, "bupWater "},
    {WAVE, "bupWAVE "},
    {WINK, "bupWink "},
    {WIZ, "bupWiz "},
    {WOOK, "bupWOOK "},
    {WUB, "bupWUB "},
    {ZEJIBO, "bupZejibo "},
    {ZELDABUP, "bupZELDABUP "},
    {BOP, "BOP "},
    {BOPBOP, "BopBop "},
    {DINODANCE, "DinoDance "},
    {GLITCHLIT, "GlitchLit "},
    {GOATEMOTEY, "GoatEmotey "},
    {GOLDPLZ, "GoldPLZ "},
    {KAPPA, "Kappa "},
    {KREYGASM, "Kreygasm "},
    {MODLOVE, "ModLove "},
    {NOTLIKETHIS, "NotLikeThis "},
    {POWERUPL, "PowerUpL "},
    {POWERUPR, "PowerUpR "},
    {RIPEPPERONIS, "riPepperonis "},
    {SABAPING, "SabaPing "},
    {SINGSMIC, "SingsMic "},
    {SINGSNOTE, "SingsNote "},
    {STINKYCHEESE, "StinkyCheese "},
    {TOMBRAID, "TombRaid "},
    {TWITCHCONHYPE, "TwitchConHYPE "},
    {TWITCHLIT, "TwitchLit "},
    {TWITCHRAID, "twitchRaid "},
    {UNITY, "TwitchUnity "},
    {VOTENAY, "VoteNay "},
    {VOTEYEA, "VoteYea "},
};

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
        for (int i = 0; i < sizeof(keycode_strings) / sizeof(keycode_strings[0]); i++) {
            if (keycode == keycode_strings[i].keycode) {
                if (keycode >= FIRST_EMOTE_KEYCODE && keycode <= LAST_EMOTE_KEYCODE) {
                    if (host_keyboard_led_state().caps_lock) {
                        size_t len = strlen(keycode_strings[i].string) + 1; // +1 for null terminator
                        char *inverted_string = (char *)malloc(len);
                        if (inverted_string != NULL) {
                            strcpy(inverted_string, keycode_strings[i].string);
                            invert_caps(inverted_string);
                            send_string(inverted_string);
                            free(inverted_string);
                        }
                    } else {
                        send_string(keycode_strings[i].string);
                    }
                } else {
                    send_string(keycode_strings[i].string);
                }
                return false;
            }
        }
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1),      CHEESE,     EYE,        GLUTES,     DUCKDANCE,
        DISCO,      DIDDY,      CATDANCE,   SLAY,       BEARDDANCE,
        PATBANG,    FREAKOUT,   DRUMS,      FROG,       KEKW,
        BACKDOOR,   LOVE,       THANKS,     ZEJIBO,     BUG,
        BITS,       MOOSE,      BUP,        CAPGEN5,    KC_ENT
    ),
    [1] = LAYOUT(
        TO(0),      TO(5),      TO(2),      TO(3),      TO(4),
        THING,      DONUT,      DYE,        SMIRK,      REVERSE,
        RUMP,       ACID,       CLOUDS,     WATER,      WINK,
        BALLOON,    HEART,      ASCEND,     JELLY,      PLUG,
        RAVE,       CROWN,      TIEDYE,     DRAGON,     KC_ENT
    ),
    [2] = LAYOUT(
        TO(0),      TO(1),      TO(5),      TO(3),      TO(4),
        DUCKHEAD,   WIZ,        CHEFKISS,   TINFOIL,    BIGBRAIN,
        CALL,       DOIT,       GROGU,      JAWNESSA,   BART,
        BUPS,       BROC,       BUPWAD,     SPOOKY,     ZELDABUP,
        AYO,        ID,         SH,         EE,         KC_ENT
    ),
    [3] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(5),      TO(4),
        BASSFACE,   BOB,        SABER,      UWU,        UP,
        NOD,        GOOSE,      BOOMER,     WUB,        WOOK,
        HEADOUT,    RAINBOW,    SALUTE,     SWEATY,     HORN,
        FLUTE,      FIRE,       CHEERS,     KEYS,       KC_ENT
    ),
    [4] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(3),      TO(5),
        WAVE,       LIGHTER,    GLITCHLIT,  TWITCHLIT,  NOTLIKETHIS,
        GOLDPLZ,    KREYGASM,   POWERUPL,   POWERUPR,   TWITCHCONHYPE,
        SINGSMIC,   SINGSNOTE,  TOMBRAID,   TWITCHRAID, GOATEMOTEY,
        BOPBOP,     DINODANCE,  UNITY,      KAPPA,      KC_ENT
    ),
    [5] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(3),      TO(4),
        RGB_MOD,    RGB_VAI,    RGB_HUI,    RGB_SAI,    RGB_SPI,
        RGB_RMOD,   RGB_VAD,    RGB_HUD,    RGB_SAD,    RGB_SPD,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        RGB_M_P,    RGB_M_B,    RGB_M_R,    RGB_M_SW,   RGB_TOG
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(!process_record_bup(keycode, record)) {
        return false;
    }

    return true;
}
