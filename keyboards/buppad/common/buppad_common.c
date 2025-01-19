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

bool process_record_bup(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CAPGEN5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvv"));
            }
            return false;
        case CAPGEN8:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvvvvv"));
            }
            return false;
        case CAPGEN10:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvvvvvvv"));
            }
            return false;
        case ACID: // begin bup emotes
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupAcid "));
            } else {
                SEND_STRING(("bupAcid "));
            }
            }
            return false;
        case ASCEND:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupAscend "));
            } else {
                SEND_STRING(("bupAscend "));
            }
            }
            return false;
        case AYO:
            if (record->event.pressed) {
                if (host_keyboard_led_state().caps_lock) {
                    SEND_STRING(SS_LSFT("bupAyo "));
                } else {
                    SEND_STRING(("bupAyo "));
                }
            }
            return false;
        case BACKDOOR:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBackDoor "));
            } else {
                SEND_STRING("bupBackDoor ");
            }
            }
            return false;
        case BALLOON:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBalloon "));
            } else {
                SEND_STRING("bupBalloon ");
            }
            }
            return false;
        case BART:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBart "));
            } else {
                SEND_STRING("bupBart ");
            }
            }
            return false;
        case BASSFACE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBASSSFACE "));
            } else {
                SEND_STRING("bupBASSSFACE ");
            }
            }
            return false;
        case BEARDDANCE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBEARDDANCE "));
            } else {
                SEND_STRING("bupBEARDDANCE ");
            }
            }
            return false;
        case BIGBRAIN:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBigBrain "));
            } else {
                SEND_STRING("bupBigBrain ");
            }
            }
            return false;
        case BITS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBITS "));
            } else {
                SEND_STRING("bupBITS ");
            }
            }
            return false;
        case BOB:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBOB "));
            } else {
                SEND_STRING("bupBOB ");
            }
            }
            return false;
        case BOOMER:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBOOMER "));
            } else {
                SEND_STRING("bupBOOMER ");
            }
            }
            return false;
        case BROC:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBroc "));
            } else {
                SEND_STRING("bupBroc ");
            }
            }
            return false;
        case BUG:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBug "));
            } else {
                SEND_STRING("bupBug ");
            }
            }
            return false;
        case BUP:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBUP "));
            } else {
                SEND_STRING("bupBUP ");
            }
            }
            return false;
        case BUPS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBUPS "));
            } else {
                SEND_STRING("bupBUPS ");
            }
            }
            return false;
        case BUPWAD:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupBUPWAD "));
            } else {
                SEND_STRING("bupBUPWAD ");
            }
            }
            return false;
        case CALL:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupCall "));
            } else {
                SEND_STRING("bupCall ");
            }
            }
            return false;
        case CATDANCE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupCATDANCE "));
            } else {
                SEND_STRING("bupCATDANCE ");
            }
            }
            return false;
        case CHEERS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupCHEERS "));
            } else {
                SEND_STRING("bupCHEERS ");
            }
            }
            return false;
        case CHEESE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupCheese "));
            } else {
                SEND_STRING("bupCheese ");
            }
            }
            return false;
        case CHEFKISS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupChefkiss "));
            } else {
                SEND_STRING("bupChefkiss ");
            }
            }
            return false;
        case CLOUDS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupClouds "));
            } else {
                SEND_STRING("bupClouds ");
            }
            }
            return false;
        case CROWN:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupCrown "));
            } else {
                SEND_STRING("bupCrown ");
            }
            }
            return false;
        case DIDDY:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDiddy "));
            } else {
                SEND_STRING("bupDiddy ");
            }
            }
            return false;
        case DISCO:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDisco "));
            } else {
                SEND_STRING("bupDisco ");
            }
            }
            return false;
        case DOIT:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDOIT "));
            } else {
                SEND_STRING("bupDOIT ");
            }
            }
            return false;
        case DONUT:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDonut "));
            } else {
                SEND_STRING("bupDonut ");
            }
            }
            return false;
        case DRAGON:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDragon "));
            } else {
                SEND_STRING("bupDragon ");
            }
            }
            return false;
        case DRUMS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDrums "));
            } else {
                SEND_STRING("bupDrums ");
            }
            }
            return false;
        case DUCKDANCE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDUCKDANCE "));
            } else {
                SEND_STRING("bupDUCKDANCE ");
            }
            }
            return false;
        case DUCKHEAD:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDuckhead "));
            } else {
                SEND_STRING("bupDuckhead ");
            }
            }
            return false;
        case DYE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupDye "));
            } else {
                SEND_STRING("bupDye ");
            }
            }
            return false;
        case EE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupEE "));
            } else {
                SEND_STRING("bupEE ");
            }
            }
            return false;
        case EYE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupEye "));
            } else {
                SEND_STRING("bupEye ");
            }
            }
            return false;
        case FIRE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupFire "));
            } else {
                SEND_STRING("bupFire ");
            }
            }
            return false;
        case FLUTE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupFLUTE "));
            } else {
                SEND_STRING("bupFLUTE ");
            }
            }
            return false;
        case FREAKOUT:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupFreakout "));
            } else {
                SEND_STRING("bupFreakout ");
            }
            }
            return false;
        case FROG:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupFROG "));
            } else {
                SEND_STRING("bupFROG ");
            }
            }
            return false;
        case GLUTES:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupGlutes "));
            } else {
                SEND_STRING("bupGlutes ");
            }
            }
            return false;
        case GOOSE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupGoose "));
            } else {
                SEND_STRING("bupGoose ");
            }
            }
            return false;
        case GROGU:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupGrogu "));
            } else {
                SEND_STRING("bupGrogu ");
            }
            }
            return false;
        case HEADOUT:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupHEADOUT "));
            } else {
                SEND_STRING("bupHEADOUT ");
            }
            }
            return false;
        case HEART:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupHeart "));
            } else {
                SEND_STRING("bupHeart ");
            }
            }
            return false;
        case HORN:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupHORN "));
            } else {
                SEND_STRING("bupHORN ");
            }
            }
            return false;
        case ID:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupID "));
            } else {
                SEND_STRING("bupID ");
            }
            }
            return false;
        case JAWNESSA:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupJAWNESSA "));
            } else {
                SEND_STRING("bupJAWNESSA ");
            }
            }
            return false;
        case JELLY:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupJelly "));
            } else {
                SEND_STRING("bupJelly ");
            }
            }
            return false;
        case KEKW:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupKekw "));
            } else {
                SEND_STRING("bupKekw ");
            }
            }
            return false;
        case KEYS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupKEYS "));
            } else {
                SEND_STRING("bupKEYS ");
            }
            }
            return false;
        case LIGHTER:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupLighter "));
            } else {
                SEND_STRING("bupLighter ");
            }
            }
            return false;
        case LOVE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupLOVE "));
            } else {
                SEND_STRING("bupLOVE ");
            }
            }
            return false;
        case MOOSE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupMOOSE "));
            } else {
                SEND_STRING("bupMOOSE ");
            }
            }
            return false;
        case NOD:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupNod "));
            } else {
                SEND_STRING("bupNod ");
            }
            }
            return false;
        case PATBANG:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupPATBANG "));
            } else {
                SEND_STRING("bupPATBANG ");
            }
            }
            return false;
        case PLUG:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupPlug "));
            } else {
                SEND_STRING("bupPlug ");
            }
            }
            return false;
        case RAINBOW:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupRAINBOW "));
            } else {
                SEND_STRING("bupRAINBOW ");
            }
            }
            return false;
        case RAVE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupRave "));
            } else {
                SEND_STRING("bupRave ");
            }
            }
            return false;
        case REVERSE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupReverse "));
            } else {
                SEND_STRING("bupReverse ");
            }
            }
            return false;
        case RUMP:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupRump "));
            } else {
                SEND_STRING("bupRump ");
            }
            }
            return false;
        case SABER:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupSABER "));
            } else {
                SEND_STRING("bupSABER ");
            }
            }
            return false;
        case SALUTE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupSalute "));
            } else {
                SEND_STRING("bupSalute ");
            }
            }
            return false;
        case SH:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupSh "));
            } else {
                SEND_STRING("bupSh ");
            }
            }
            return false;
        case SLAY:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupSlay "));
            } else {
                SEND_STRING("bupSlay ");
            }
            }
            return false;
        case SMIRK:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupSmirk "));
            } else {
                SEND_STRING("bupSmirk ");
            }
            }
            return false;
        case SPOOKY:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupSpooky "));
            } else {
                SEND_STRING("bupSpooky ");
            }
            }
            return false;
        case SWEATY:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupSweaty "));
            } else {
                SEND_STRING("bupSweaty ");
            }
            }
            return false;
        case THANKS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupTHANKS "));
            } else {
                SEND_STRING("bupTHANKS ");
            }
            }
            return false;
        case THING:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupThing "));
            } else {
                SEND_STRING("bupThing ");
            }
            }
            return false;
        case TIEDYE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupTIEDYE "));
            } else {
                SEND_STRING("bupTIEDYE ");
            }
            }
            return false;
        case TINFOIL:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupTINFOIL "));
            } else {
                SEND_STRING("bupTINFOIL ");
            }
            }
            return false;
        case UP:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupUp "));
            } else {
                SEND_STRING("bupUp ");
            }
            }
            return false;
        case UWU:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupUWU "));
            } else {
                SEND_STRING("bupUWU ");
            }
            }
            return false;
        case WATER:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupWater "));
            } else {
                SEND_STRING("bupWater ");
            }
            }
            return false;
        case WAVE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupWAVE "));
            } else {
                SEND_STRING("bupWAVE ");
            }
            }
            return false;
        case WINK:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupWink "));
            } else {
                SEND_STRING("bupWink ");
            }
            }
            return false;
        case WIZ:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupWiz "));
            } else {
                SEND_STRING("bupWiz ");
            }
            }
            return false;
        case WOOK:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupWOOK "));
            } else {
                SEND_STRING("bupWOOK ");
            }
            }
            return false;
        case WUB:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupWUB "));
            } else {
                SEND_STRING("bupWUB ");
            }
            }
            return false;
        case ZEJIBO:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupZejibo "));
            } else {
                SEND_STRING("bupZejibo ");
            }
            }
            return false;
        case ZELDABUP:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("bupZELDABUP "));
            } else {
                SEND_STRING("bupZELDABUP ");
            }
            }
            return false; // end bup emotes
        case BOP: // begin twitch emotes
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("BOP "));
            } else {
                SEND_STRING("BOP ");
            }
            }
            return false;
        case BOPBOP:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("BopBop "));
            } else {
                SEND_STRING("BopBop ");
            }
            }
            return false;
        case DINODANCE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("DinoDance "));
            } else {
                SEND_STRING("DinoDance ");
            }
            }
            return false;
        case GLITCHLIT:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("GlitchLit "));
            } else {
                SEND_STRING("GlitchLit ");
            }
            }
            return false;
        case GOATEMOTEY:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("GoatEmotey "));
            } else {
                SEND_STRING("GoatEmotey ");
            }
            }
            return false;
        case GOLDPLZ:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("GoldPLZ "));
            } else {
                SEND_STRING("GoldPLZ ");
            }
            }
            return false;
        case KAPPA:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("Kappa "));
            } else {
                SEND_STRING("Kappa ");
            }
            }
            return false;
        case KREYGASM:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("Kreygasm "));
            } else {
                SEND_STRING("Kreygasm ");
            }
            }
            return false;
        case MODLOVE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("ModLove "));
            } else {
                SEND_STRING("ModLove ");
            }
            }
            return false;
        case NOTLIKETHIS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("NotLikeThis "));
            } else {
                SEND_STRING("NotLikeThis ");
            }
            }
            return false;
        case POWERUPL:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("PowerUpL "));
            } else {
                SEND_STRING("PowerUpL ");
            }
            }
            return false;
        case POWERUPR:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("PowerUpR "));
            } else {
                SEND_STRING("PowerUpR ");
            }
            }
            return false;
        case RIPEPPERONIS:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("riPepperonis "));
            } else {
                SEND_STRING("riPepperonis ");
            }
            }
            return false;
        case SABAPING:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("SabaPing "));
            } else {
                SEND_STRING("SabaPing ");
            }
            }
            return false;
        case SINGSMIC:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("SingsMic "));
            } else {
                SEND_STRING("SingsMic ");
            }
            }
            return false;
        case SINGSNOTE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("SingsNote "));
            } else {
                SEND_STRING("SingsNote ");
            }
            }
            return false;
        case STINKYCHEESE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("StinkyCheese "));
            } else {
                SEND_STRING("StinkyCheese ");
            }
            }
            return false;
        case TOMBRAID:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("TombRaid "));
            } else {
                SEND_STRING("TombRaid ");
            }
            }
            return false;
        case TWITCHCONHYPE:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("TwitchConHYPE "));
            } else {
                SEND_STRING("TwitchConHYPE ");
            }
            }
            return false;
        case TWITCHLIT:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("TwitchLit "));
            } else {
                SEND_STRING("TwitchLit ");
            }
            }
            return false;
        case TWITCHRAID:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("twitchRaid "));
            } else {
                SEND_STRING("twitchRaid ");
            }
            }
            return false;
        case UNITY:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("TwitchUnity "));
            } else {
                SEND_STRING("TwitchUnity ");
            }
            }
            return false;
        case VOTENAY:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("VoteNay "));
            } else {
                SEND_STRING("VoteNay ");
            }
            }
            return false;
        case VOTEYEA:
            if (record->event.pressed) {
            if (host_keyboard_led_state().caps_lock) {
                SEND_STRING(SS_LSFT("VoteYea "));
            } else {
                SEND_STRING("VoteYea ");
            }
            }
            return false; // end twitch emotes
        default:
            return true; // Process all other keycodes normally
    }
}
