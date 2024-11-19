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

#include "quantum.h"
#include "buppad_common.h"
#include "send_string.h"

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

bool process_record_bup(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        for (int i = 0; i < sizeof(keycode_strings) / sizeof(keycode_strings[0]); i++) {
            if (keycode == keycode_strings[i].keycode) {
                if (keycode >= ACID && keycode <= 0x7FFF) {
                    if (host_keyboard_led_state().caps_lock) {
                        register_code(KC_RSFT);
                        send_string(keycode_strings[i].string);
                        unregister_code(KC_RSFT);
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
