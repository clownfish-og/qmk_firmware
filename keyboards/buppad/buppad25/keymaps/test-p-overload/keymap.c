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


const char amnesia[] PROGMEM = "Amnesia";
const char ayo[] PROGMEM = "Ayo";
const char backdoor[] PROGMEM = "BackDoor";
const char balloon[] PROGMEM = "Balloon";
const char bart[] PROGMEM = "Bart";
const char bearddance[] PROGMEM = "BEARDDANCE";
const char bigbrain[] PROGMEM = "BigBrain";
const char bits[] PROGMEM = "BITS";
const char boomer[] PROGMEM = "BOOMER";
const char bug[] PROGMEM = "Bug";
const char bup[] PROGMEM = "BUP";
const char bups[] PROGMEM = "BUPS";
const char bupwad[] PROGMEM = "BUPWAD";
const char call[] PROGMEM = "Call";
const char catdance[] PROGMEM = "CATDANCE";
const char cheers[] PROGMEM = "CHEERS";
const char cheese[] PROGMEM = "Cheese";
const char chefkiss[] PROGMEM = "Chefkiss";
const char crown[] PROGMEM = "Crown";
const char diddy[] PROGMEM = "Diddy";
const char disco[] PROGMEM = "Disco";
const char doit[] PROGMEM = "DOIT";
const char donut[] PROGMEM = "Donut";
const char drums[] PROGMEM = "Drums";
const char duckdance[] PROGMEM = "DUCKDANCE";
const char duckhead[] PROGMEM = "Duckhead";
const char dye[] PROGMEM = "Dye";
const char ee[] PROGMEM = "EE";
const char fire[] PROGMEM = "Fire";
const char flute[] PROGMEM = "FLUTE";
const char freakout[] PROGMEM = "Freakout";
const char frog[] PROGMEM = "FROG";
const char grogu[] PROGMEM = "Grogu";
const char groovy[] PROGMEM = "Groovy";
const char headout[] PROGMEM = "HEADOUT";
const char horn[] PROGMEM = "HORN";
const char id[] PROGMEM = "ID";
const char kekw[] PROGMEM = "Kekw";
const char keys[] PROGMEM = "KEYS";
const char lighter[] PROGMEM = "Lighter";
const char love[] PROGMEM = "LOVE";
const char luigibup[] PROGMEM = "LUIGIBUP";
const char moose[] PROGMEM = "MOOSE";
const char patbang[] PROGMEM = "PATBANG";
const char plug[] PROGMEM = "Plug";
const char salute[] PROGMEM = "Salute";
const char sh[] PROGMEM = "Sh";
const char slay[] PROGMEM = "Slay";
const char sweaty[] PROGMEM = "Sweaty";
const char thanks[] PROGMEM = "THANKS";
const char wook[] PROGMEM = "WOOK";
const char wub[] PROGMEM = "WUB";
const char zejibo[] PROGMEM = "Zejibo";
const char zeldabup[] PROGMEM = "ZELDABUP";
const char broc[] PROGMEM = "Broc";
const char clouds[] PROGMEM = "Clouds";
const char goose[] PROGMEM = "Goose";
const char heart[] PROGMEM = "Heart";
const char jawnessa[] PROGMEM = "JAWNESSA";
const char rave[] PROGMEM = "Rave";
const char salt[] PROGMEM = "Salt";
const char tinfoil[] PROGMEM = "TINFOIL";
const char water[] PROGMEM = "Water";
const char wiz[] PROGMEM = "Wiz";
const char basssface[] PROGMEM = "BASSSFACE";
const char bob[] PROGMEM = "BOB";
const char chillguy[] PROGMEM = "Chillguy";
const char dragon[] PROGMEM = "Dragon";
const char jelly[] PROGMEM = "Jelly";
const char maple[] PROGMEM = "Maple";
const char rump[] PROGMEM = "Rump";
const char smirk[] PROGMEM = "Smirk";
const char uwu[] PROGMEM = "UWU";
const char wink[] PROGMEM = "Wink";
const char abducktion[] PROGMEM = "AbDUCKtion";
const char ascend[] PROGMEM = "Ascend";
const char ashduckem[] PROGMEM = "ASHDUCKEM";
const char excuseme[] PROGMEM = "EXCUSEME";
const char fancyduck[] PROGMEM = "FANCYDUCK";
const char gold[] PROGMEM = "Gold";
const char headphones[] PROGMEM = "HEADPHONES";
const char ktuluehug[] PROGMEM = "KTULUEHUG";
const char rainbow[] PROGMEM = "RAINBOW";
const char smug[] PROGMEM = "Smug";
const char sus[] PROGMEM = "Sus";
const char nod[] PROGMEM = "Nod";
const char tiedye[] PROGMEM = "TIEDYE";
const char tune[] PROGMEM = "TUNE";
const char up[] PROGMEM = "Up";
const char wave[] PROGMEM = "WAVE";
const char bop[] PROGMEM = "BOP";
const char bopbop[] PROGMEM = "BopBop";
const char dinodance[] PROGMEM = "DinoDance";
const char glitchlit[] PROGMEM = "GlitchLit";
const char goatemotey[] PROGMEM = "GoatEmotey";
const char goldplz[] PROGMEM = "GoldPLZ";
const char kappa[] PROGMEM = "Kappa";
const char kreygasm[] PROGMEM = "Kreygasm";
const char modlove[] PROGMEM = "ModLove";
const char notlikethis[] PROGMEM = "NotLikeThis";
const char powerupl[] PROGMEM = "PowerUpL";
const char powerupr[] PROGMEM = "PowerUpR";
const char singsmic[] PROGMEM = "SingsMic";
const char singsnote[] PROGMEM = "SingsNote";
const char stinkycheese[] PROGMEM = "StinkyCheese";
const char tombraider[] PROGMEM = "TombRaid";
const char twitchconhype[] PROGMEM = "TwitchConHYPE";
const char twitchlit[] PROGMEM = "TwitchLit";
const char twitchraid[] PROGMEM = "twitchRaid";
const char unity[] PROGMEM = "TwitchUnity";
const char votenay[] PROGMEM = "VoteNay";
const char voteyea[] PROGMEM = "VoteYea";
const char bdance[] PROGMEM = "Dance";
const char bmingo[] PROGMEM = "Mingo";
const char bmonkey[] PROGMEM = "Monkey";
const char bpug[] PROGMEM = "Pug";
const char bugh[] PROGMEM = "Ugh";
const char kclap[] PROGMEM = "Clap";
const char kgato[] PROGMEM = "Gato";
const char kggs[] PROGMEM = "GGs";
const char kglutes[] PROGMEM = "GLUTES";
const char khi[] PROGMEM = "HI";
const char khug[] PROGMEM = "HUG";
const char klei[] PROGMEM = "Lei";
const char klove[] PROGMEM = "Love";
const char krdnc[] PROGMEM = "Rdnc";
const char ksmug[] PROGMEM = "SMUG";
const char test1[] PROGMEM = "String1";
const char test2[] PROGMEM = "String2";
const char test3[] PROGMEM = "String3";
const char test4[] PROGMEM = "String4";
const char test5[] PROGMEM = "String5";
const char test6[] PROGMEM = "String6";
const char test7[] PROGMEM = "String7";
const char test8[] PROGMEM = "String8";
const char test9[] PROGMEM = "String9";
const char test10[] PROGMEM = "String10";
const char test11[] PROGMEM = "String11";
const char test12[] PROGMEM = "String12";
const char test13[] PROGMEM = "String13";
const char test14[] PROGMEM = "String14";
const char test15[] PROGMEM = "String15";
const char test16[] PROGMEM = "String16";
const char test17[] PROGMEM = "String17";
const char test18[] PROGMEM = "String18";
const char test19[] PROGMEM = "String19";
const char test20[] PROGMEM = "String20";
const char test21[] PROGMEM = "String21";
const char test22[] PROGMEM = "String22";
const char test23[] PROGMEM = "String23";
const char test24[] PROGMEM = "String24";
const char test25[] PROGMEM = "String25";
const char test26[] PROGMEM = "String26";
const char test27[] PROGMEM = "String27";
const char test28[] PROGMEM = "String28";
const char test29[] PROGMEM = "String29";
const char test30[] PROGMEM = "String30";
const char test31[] PROGMEM = "String31";
const char test32[] PROGMEM = "String32";
const char test33[] PROGMEM = "String33";
const char test34[] PROGMEM = "String34";
const char test35[] PROGMEM = "String35";
const char test36[] PROGMEM = "String36";
const char test37[] PROGMEM = "String37";
const char test38[] PROGMEM = "String38";
const char test39[] PROGMEM = "String39";
const char test40[] PROGMEM = "String40";
const char test41[] PROGMEM = "String41";
const char test42[] PROGMEM = "String42";
const char test43[] PROGMEM = "String43";
const char test44[] PROGMEM = "String44";
const char test45[] PROGMEM = "String45";
const char test46[] PROGMEM = "String46";
const char test47[] PROGMEM = "String47";
const char test48[] PROGMEM = "String48";
const char test49[] PROGMEM = "String49";
const char test50[] PROGMEM = "String50";
const char test51[] PROGMEM = "String51";
const char test52[] PROGMEM = "String52";
const char test53[] PROGMEM = "String53";
const char test54[] PROGMEM = "String54";
const char test55[] PROGMEM = "String55";
const char test56[] PROGMEM = "String56";
const char test57[] PROGMEM = "String57";
const char test58[] PROGMEM = "String58";
const char test59[] PROGMEM = "String59";
const char test60[] PROGMEM = "String60";
const char test61[] PROGMEM = "String61";
const char test62[] PROGMEM = "String62";
const char test63[] PROGMEM = "String63";
const char test64[] PROGMEM = "String64";
const char test65[] PROGMEM = "String65";
const char test66[] PROGMEM = "String66";
const char test67[] PROGMEM = "String67";
const char test68[] PROGMEM = "String68";
const char test69[] PROGMEM = "String69";
const char test70[] PROGMEM = "String70";
const char test71[] PROGMEM = "String71";
const char test72[] PROGMEM = "String72";
const char test73[] PROGMEM = "String73";
const char test74[] PROGMEM = "String74";
const char test75[] PROGMEM = "String75";
const char test76[] PROGMEM = "String76";
const char test77[] PROGMEM = "String77";
const char test78[] PROGMEM = "String78";
const char test79[] PROGMEM = "String79";
const char test80[] PROGMEM = "String80";
const char test81[] PROGMEM = "String81";
const char test82[] PROGMEM = "String82";
const char test83[] PROGMEM = "String83";
const char test84[] PROGMEM = "String84";
const char test85[] PROGMEM = "String85";
const char test86[] PROGMEM = "String86";
const char test87[] PROGMEM = "String87";
const char test88[] PROGMEM = "String88";
const char test89[] PROGMEM = "String89";
const char test90[] PROGMEM = "String90";
const char test91[] PROGMEM = "String91";
const char test92[] PROGMEM = "String92";
const char test93[] PROGMEM = "String93";
const char test94[] PROGMEM = "String94";
const char test95[] PROGMEM = "String95";
const char test96[] PROGMEM = "String96";
const char test97[] PROGMEM = "String97";
const char test98[] PROGMEM = "String98";
const char test99[] PROGMEM = "String99";
const char test100[] PROGMEM = "String100";

PGM_P const suffix[] PROGMEM = {
    amnesia,
    ayo,
    backdoor,
    balloon,
    bart,
    bearddance,
    bigbrain,
    bits,
    boomer,
    bug,
    bup,
    bups,
    bupwad,
    call,
    catdance,
    cheers,
    cheese,
    chefkiss,
    crown,
    diddy,
    disco,
    doit,
    donut,
    drums,
    duckdance,
    duckhead,
    dye,
    ee,
    fire,
    flute,
    freakout,
    frog,
    grogu,
    groovy,
    headout,
    horn,
    id,
    kekw,
    keys,
    lighter,
    love,
    luigibup,
    moose,
    patbang,
    plug,
    salute,
    sh,
    slay,
    sweaty,
    thanks,
    wook,
    wub,
    zejibo,
    zeldabup,
    broc,
    clouds,
    goose,
    heart,
    jawnessa,
    rave,
    salt,
    tinfoil,
    water,
    wiz,
    basssface,
    bob,
    chillguy,
    dragon,
    jelly,
    maple,
    rump,
    smirk,
    uwu,
    wink,
    abducktion,
    ascend,
    ashduckem,
    excuseme,
    fancyduck,
    gold,
    headphones,
    ktuluehug,
    rainbow,
    smug,
    sus,
    nod,
    tiedye,
    tune,
    up,
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
    votenay,
    voteyea,
    bdance,
    bmingo,
    bmonkey,
    bpug,
    bugh,
    kclap,
    kgato,
    kggs,
    kglutes,
    khi,
    khug,
    klei,
    klove,
    krdnc,
    ksmug,
    test1,
    test2,
    test3,
    test4,
    test5,
    test6,
    test7,
    test8,
    test9,
    test10,
    test11,
    test12,
    test13,
    test14,
    test15,
    test16,
    test17,
    test18,
    test19,
    test20,
    test21,
    test22,
    test23,
    test24,
    test25,
    test26,
    test27,
    test28,
    test29,
    test30,
    test31,
    test32,
    test33,
    test34,
    test35,
    test36,
    test37,
    test38,
    test39,
    test40,
    test41,
    test42,
    test43,
    test44,
    test45,
    test46,
    test47,
    test48,
    test49,
    test50,
    test51,
    test52,
    test53,
    test54,
    test55,
    test56,
    test57,
    test58,
    test59,
    test60,
    test61,
    test62,
    test63,
    test64,
    test65,
    test66,
    test67,
    test68,
    test69,
    test70,
    test71,
    test72,
    test73,
    test74,
    test75,
    test76,
    test77,
    test78,
    test79,
    test80,
    test81,
    test82,
    test83,
    test84,
    test85,
    test86,
    test87,
    test88,
    test89,
    test90,
    test91,
    test92,
    test93,
    test94,
    test95,
    test96,
    test97,
    test98,
    test99,
    test100
};

#define FIRST_EMOTE AMNESIA
#define LAST_EMOTE T100
const int start_bup = AMNESIA;
const int end_bup = WAVE;
const int start_bex = BDANCE;
const int end_bex = BUGH;
const int start_ktlu = KCLAP;
const int end_ktlu = KSMUG;
const int start_testa = T1;
const int end_testa = T50;
const int start_testb = T51;
const int end_testb = T100;

const char bup_p[] = "bup";
const char bex_p[] = "bexfro";
const char ktlu_p[] = "ktulue";
const char testa_p[] = "test1";
const char testb_p[] = "test2";

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
                uint8_t i = keycode - FIRST_EMOTE;
                uprintf("i: %d\n", i);
                char suffix_buffer[24];
                char emote_buffer[36];
                uprintf("Size of suffix_buffer: %d\n", sizeof(suffix_buffer));
                uprintf("Size of emote_buffer: %d\n", sizeof(emote_buffer));
                suffix_buffer[0] = '\0';
                emote_buffer[0] = '\0';
                strncpy_P(suffix_buffer, (PGM_P)pgm_read_ptr(&(suffix[i])), sizeof(suffix_buffer) - 1);
                uprintf("Suffix buffer: %s\n", suffix_buffer);


                if (start_bup <= keycode && keycode <= end_bup) {  // Most keycodes use the bup prefix
                    strncpy(emote_buffer, bup_p, sizeof(emote_buffer));  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix_buffer);                     // append suffix to buffer
                } else if (start_bex <= keycode && keycode <= end_bex){   // Handle Bex keycodes
                    strncpy(emote_buffer, bex_p, sizeof(emote_buffer));  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix_buffer);                     // append suffix to buffer
                } else if (start_ktlu <= keycode && keycode <= end_ktlu) {  // Handle Ktulue keycodes
                    strncpy(emote_buffer, ktlu_p, sizeof(emote_buffer));  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix_buffer);                     // append suffix to buffer
                } else if (start_testa <= keycode && keycode <= end_testa){   // Handle Bex keycodes
                    strncpy(emote_buffer, testa_p, sizeof(emote_buffer));  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix_buffer);                     // append suffix to buffer
                } else if (start_testb <= keycode && keycode <= end_testb){   // Handle Bex keycodes
                    strncpy(emote_buffer, testb_p, sizeof(emote_buffer));  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix_buffer);                     // append suffix to buffer
                } else {
                    strncpy(emote_buffer, suffix_buffer, sizeof(emote_buffer));  // Non-prefixed keycodes
                }

                // Debug output
                uprintf("Keycode: %u, Suffix: %s, Emote: %s\n", keycode, suffix_buffer, emote_buffer);

                if (caps) {
                    invert_caps(emote_buffer);
                }

                // Append a space and send the emote
                strcat(emote_buffer, " ");
                send_string(emote_buffer);
                uprintf("Keycode: %u, Caps: %d, Output: %s\n", keycode, caps, emote_buffer);
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
