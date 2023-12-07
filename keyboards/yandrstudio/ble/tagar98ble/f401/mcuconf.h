// Copyright 2022 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef STM32_SPI_USE_SPI3
#define STM32_SPI_USE_SPI3 TRUE

#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE

#undef STM32_PWM_USE_ADVANCED
#define STM32_PWM_USE_ADVANCED TRUE

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#undef  STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE

#undef STM32_PLLM_VALUE
#undef STM32_PLLN_VALUE
#undef STM32_PLLP_VALUE
#undef STM32_PLLQ_VALUE
#undef STM32_PPRE1

#define STM32_PLLM_VALUE                    (STM32_HSECLK/2000000)
#define STM32_PLLN_VALUE                    168
#define STM32_PLLP_VALUE                    4
#define STM32_PLLQ_VALUE                    7
#define STM32_PPRE1                         STM32_PPRE1_DIV4
