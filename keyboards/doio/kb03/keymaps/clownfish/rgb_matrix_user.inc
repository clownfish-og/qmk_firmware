// !!! DO NOT ADD #pragma once !!! //

RGB_MATRIX_EFFECT(NO_UNDERGLOW)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool NO_UNDERGLOW(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
            rgb_matrix_set_color(i, RGB_OFF);
        } else if (HAS_FLAGS(g_led_config.flags[i], 0x04)) {
            rgb_matrix_enable();
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif