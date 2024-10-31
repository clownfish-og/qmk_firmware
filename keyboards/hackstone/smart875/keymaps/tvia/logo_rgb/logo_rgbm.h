#pragma once

#include "quantum.h"
#include "color.h"

typedef union {
    uint32_t raw;
    struct
    {
        uint8_t flag: 1;
        uint8_t mode;
    };
} logo_rgb_matrix_config_t;

void logo_rgb_matrix_init(void);
void logo_rgb_matrix_task(void);
void logo_rgb_mode_step(void);
uint8_t get_logo_rgb_mode(void);
void eeconfig_update_logo_rgb_matrix(void);

// off                     // 0
// void CycleAll(void);       // 1
// void CycleBreathing(void); // 2
// void StaticYellow(void);     // 3
// void StaticGreen(void);   // 4
// void StaticPink(void);   // 4
// void StaticWhite(void);   // 4
