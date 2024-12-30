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

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "action.h"
#include "quantum.h"

#ifdef VIA_ENABLE
#    include "via.h"
#endif

#include "quantum_keycodes.h"



enum custom_keycodes {
    CAPGEN5 = QK_KB_0,
    CAPGEN8,
    CAPGEN10,
    BACKDOOR, //begin bup emotes
    BEARDDANCE,
    BITS,
    BROC,
    BUG,
    BUP,
    BUPS,
    CATDANCE,
    CHEERS,
    CHEESE,
    CHEFKISS,
    CHILLGUY,
    DIDDY,
    DISCO,
    DONUT,
    DRAGON,
    DRUMS,
    DUCKDANCE,
    DUCKHEAD,
    DYE,
    FLUTE,
    FREAKOUT,
    FROG,
    HEART,
    HORN,
    JELLY,
    KEKW,
    KEYS,
    LIGHTER,
    LOVE,
    MOOSE,
    NOD,
    PATBANG,
    SLAY,
    SMIRK,
    SWEATY,
    THANKS,
    WATER,
    WOOK,
    WUB,
    ZEJIBO,
    BOPBOP,
    DINODANCE,
    SINGSMIC,
    SINGSNOTE,
    TOMBRAID,
    TWITCHRAID,
    UNITY,
    BDANCE,
    BMINGO,
    BMONKEY,
    BPUG,
    BUGH,
    GBIRDGROOVE,
    GCATDANCE,
    GFUNNYCATDANCE,
    GJAMMIN,
    GKITTYDAB,
    GKITTYGROOVE,
    GNUMBERONE,
    GRAVEKITTY,
    KCLAP,
    KGATO,
    KGGS,
    KGLUTES,
    KHI,
    KHUG,
    KLEI,
    KLOVE,
    KRDNC,
    KSMUG,
    KWELP //end fam emotes
};

#define FIRST_EMOTE_KEYCODE BACKDOOR
#define LAST_BUP_KEYCODE ZEJIBO
#define FIRST_BEX_KEYCODE BDANCE
#define LAST_BEX_KEYCODE BUGH
#define FIRST_GKTY_KEYCODE GBIRDGROOVE
#define LAST_GKTY_KEYCODE GRAVEKITTY
#define FIRST_KTLU_KEYCODE KCLAP
#define LAST_KTLU_KEYCODE KWELP
#define LAST_EMOTE_KEYCODE KWELP
#define BUP_PREFIX "bup"
#define BEX_PREFIX "bexfro"
#define GKTY_PREFIX "groove21"
#define KTLU_PREFIX "ktulue"
#define MAX_EMOTE_LEN 32

typedef struct {
    uint16_t keycode;
    const char *suffix;
} keycode_string_compressed_t;

bool process_record_bup(uint16_t keycode, keyrecord_t *record);
