***ClownFish***  
I am working on a project for a emote macropad and I am trying to override the caps lock if it is on as emotes are case-sensitive, but it seems like shift is being released in the middle of the string and not after it is sent. I have tried calling `caps_word_on()` and `SS_DOWN(X_LSFT) ... SS_UP(X_LSFT)` as well, with the same or worse result(caps word did not work at all but I think that's expected after reading more of the backend code). Using the macro `SEND_STRING(SS_LSFT(keycode_strings[i].string));`  will not compile as I have the keycodes stored as ints in an array to fit them all into the firmware and the function expects a string literal for an argument. But defining a keycode 
```c
 if (host_keyboard_led_state().caps_lock) {
    SEND_STRING(SS_LSFT(asdfghjkl))
    };
else {
    SEND_STRING(asdfghjkl)
};
```
 ~~works fine~~ [I thought this worked yesterday but now it seems to be doing the same thing, exiting the shift when it hits a shifted character in the string]. Board is the Winry25 which uses a 32U4 chip, not sure if that matters though. This is my current code:
```c
keycode_string_t keycode_strings[] = {
    {CAPGEN5, SS_LCTL("acvvvvv")},
    {CAPGEN8, SS_LCTL("acvvvvvvvv")},
    {CAPGEN10, SS_LCTL("acvvvvvvvvvv")},
    /*
    ...
    */
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
                if (keycode >= 0x7E03 && keycode <= 0x7FFF) {
                    if (host_keyboard_led_state().caps_lock) {
                        register_code(KC_LSFT);
                        send_string(keycode_strings[i].string);
                        unregister_code(KC_LSFT);
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
```

***elpekeñin***
> `caps_word_on()`  

yeah, never used the feature, but i would expect it to add/tweak the processing within a `process_record_*` function, which indeed doesn't get called when running `send_string`, making it useless for this case  

>  32U4 chip, not sure if that matters though  

32u4 *does* matter here since it means that `SEND_STRING` and `send_string` are different things (on other controllers, they would be aliases for the same code under the hood)  

---

also , i have no idea what your `keycode_string_t` is a `typedef` for, but if it is just `struct{int,char*}` (as in ID, string) you are wasting space, because you might use the index into the array as an identifier already without storing an extra int for each entry...  

and also, if you wanted to squeeze the most out of your space, your strings must be standalone variables with the "magical" `PROGMEM` qualifier, being then referred by an array  
  
***ClownFish***  
oh I think I'm exiting the SS_LSFT when there's a shifted keycode in the string  
is there a way to get past that?  
writing the code as it is in my fork with each keycode ~~worked~~ but it was 99% of max, this way is 83%  
https://github.com/clownfish-og/qmk_firmware/blob/cdd31891b281f02d5243b472374abb42dca4db15/keyboards/buppad/common/buppad_common.c  
and yes the typedef is just that
```typedef struct {
    uint16_t keycode;
    const char *string;
} keycode_string_t;
```

***elpekeñin***  
following the "you dont need an extra id" idea...

a common pattern for "batches" of similar keycodes is to make sure they are defined correlative in your enum (lets say `enum { SOMETHING = QK_USER, SOME_STUFF, FOO, BAR, BAZ, ..., MORE_STUFF,};`), such that:  

* can easily tell them apart from others:`if (FOO <= keycode && keycode <= BAZ)`
* can convert them to a 0-based (read: index into array) identifier with: `keycode - FOO` (aka: offset by the starting value)  

another option is to have a second enum (it being 0-based-counting already), and compute the real keycode values as `QK_USER + ENUM_ELEMENT` (or perhaps start somwhere else or whatever, you get the idea ~~i hope~~)  

as per the PROGMEM part  
...yeah, this is ugly and not ergonomic, but should save some bytes off your precious RAM:  
```c
// disclaimer, im not sure if the "location" of PROGMEM here matters
// ... if it does, im not sure if this is the correct place :P
const char PROGMEM *foo = "foo";
const char PROGMEM *bar = "bar";
const char PROGMEM *baz = "baz";

// thanks to PROGMEM, those are now stored in FLASH (plenty more room) rather than RAM
// now, we make a "regular" variable (in RAM) storing their locations
// might also skip the explicit indexing ([...] = ...), but beware ordering if doing so
const char *strings[] = {
    [FOO - START] = foo,
    [BAR - START] = bar,
    [BAZ - START] = baz,
};

// in process_*
if (START <= keycode && keycode <= END) {
    const char *str = strings[keycode - START];
    // beware, this string is stored on PROGMEM, not RAM
    // must use the correct function so that QMK doesnt read garbage from the same address in ram
    // TLDR: note the `_P` in here
    send_string_P^(str);
}
```

***ClownFish***  
tysm I will give this a try  

***elpekeñin***  
that would still not fix your "shift inside shift" issue, but will hopefully help with the space 🙂  

***ClownFish***  
right  

***elpekeñin***  
but i dont see a reason why you wouldn't be able to do smth like `SHIFT("foo") "bar" SHIFT("baz")`  
implicit concatenation of string literals is your friend 😉  

***ClownFish***  
I could, was hoping for a shortcut but I guess this is the way  
thank you for your help  

***ClownFish***  
I fixed the shift on shift thing, idk why I didnt think of it before but `ctype` has `toupper` and `tolower` functions
```c
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
```  
It feels a little hacky and I still need to work on moving everything to PROGMEM, but it seems to do exactly what I wanted now so at least that's one problem solved 😄
