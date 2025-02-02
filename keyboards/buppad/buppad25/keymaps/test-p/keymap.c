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
    ksmug
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
                char suffix_buffer[30];
                char emote_buffer[40];
                uprintf("Size of suffix_buffer: %d\n", sizeof(suffix_buffer));
                uprintf("Size of emote_buffer: %d\n", sizeof(emote_buffer));
                suffix_buffer[0] = '\0';
                emote_buffer[0] = '\0';
                strcpy_P(suffix_buffer, (suffix[i]));
                uprintf("Suffix buffer: %s\n", suffix_buffer);


                if (start_bup <= keycode && keycode <= end_bup) {  // Most keycodes use the bup prefix
                    strcpy(emote_buffer, bup_p);  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix_buffer);                     // append suffix to buffer
                } else if (keycode >= start_bex && keycode <= end_bex) {   // Handle Bex keycodes
                    strcpy(emote_buffer, bex_p);  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix_buffer);                     // append suffix to buffer
                } else if (keycode >= start_ktlu && keycode <= end_ktlu) {  // Handle Ktulue keycodes
                    strcpy(emote_buffer, ktlu_p);  // load prefix to buffer
                    uprintf("Prefix: %s, ", emote_buffer);
                    strcat(emote_buffer, suffix_buffer);                     // append suffix to buffer
                } else {
                    strcpy(emote_buffer, suffix_buffer);  // Non-prefixed keycodes
                }

                // Debug output
                uprintf("Keycode: %u, Suffix: %s, Emote: %s\n", keycode, suffix_buffer, emote_buffer);

                if (caps) {
                    invert_caps(emote_buffer);
                }

                // Append a space and send the emote
                strcat(emote_buffer, " ");
                send_string(emote_buffer);
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
