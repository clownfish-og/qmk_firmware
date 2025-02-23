// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "kb16b1.h"


#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_kb(void) {
  rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void) {
  rgb_matrix_set_suspend_state(false);
}

#endif
