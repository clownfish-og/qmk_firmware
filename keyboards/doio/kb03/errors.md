***TRYING TO ADD PWM FOR RGB_MATRIX***  
**I have gone from this:**

```
Generating: .build/obj_doio_kb03_default/src/info_config.h                                          [OK]
Generating: .build/obj_doio_kb03_default/src/default_keyboard.h                                     [OK]
Generating: .build/obj_doio_kb03_default/src/default_keyboard.c                                     [OK]
Compiling: keyboards/doio/kb03/kb03.c                                                               [OK]
Compiling: .build/obj_doio_kb03_default/src/default_keyboard.c                                      [OK]
Compiling: quantum/keymap_introspection.c                                                           [OK]
Compiling: quantum/quantum.c                                                                        [OK]
Compiling: quantum/bitwise.c                                                                        [OK]
Compiling: quantum/led.c                                                                            [OK]
Compiling: quantum/action.c                                                                         [OK]
Compiling: quantum/action_layer.c                                                                   [OK]
Compiling: quantum/action_tapping.c                                                                 [OK]
Compiling: quantum/action_util.c                                                                    [OK]
Compiling: quantum/eeconfig.c                                                                       [OK]
Compiling: quantum/keyboard.c                                                                       [OK]
Compiling: quantum/keymap_common.c                                                                  [OK]
Compiling: quantum/keycode_config.c                                                                 [OK]
Compiling: quantum/sync_timer.c                                                                     [OK]
Compiling: quantum/logging/debug.c                                                                  [OK]
Compiling: quantum/logging/sendchar.c                                                               [OK]
Compiling: quantum/process_keycode/process_default_layer.c                                          [OK]
Compiling: quantum/logging/print.c                                                                  [OK]
Compiling: quantum/matrix_common.c                                                                  [OK]
Compiling: quantum/matrix.c                                                                         [OK]
Compiling: quantum/debounce/sym_defer_g.c                                                           [OK]
Compiling: quantum/main.c                                                                           [OK]
Compiling: lib/printf/src/printf/printf.c                                                           [OK]
Compiling: drivers/eeprom/eeprom_driver.c                                                           [OK]
Compiling: drivers/eeprom/eeprom_wear_leveling.c                                                    [OK]
Compiling: quantum/wear_leveling/wear_leveling.c                                                    [OK]
Compiling: platforms/chibios/drivers/wear_leveling/wear_leveling_efl.c                              [OK]
Compiling: quantum/process_keycode/process_underglow.c                                              [OK]
Compiling: quantum/process_keycode/process_rgb_matrix.c                                             [OK]
Compiling: quantum/color.c                                                                          [OK]
Compiling: quantum/rgb_matrix/rgb_matrix.c                                                          [OK]
Compiling: quantum/rgb_matrix/rgb_matrix_drivers.c                                                  [OK]
Compiling: quantum/led_tables.c                                                                     [OK]
Compiling: lib/fnv/qmk_fnv_type_validation.c                                                        [OK]
Compiling: lib/fnv/hash_32a.c                                                                       [OK]
Compiling: lib/fnv/hash_64a.c                                                                       [OK]
Compiling: lib/lib8tion/lib8tion.c                                                                  [OK]
Compiling: quantum/encoder.c                                                                        [OK]
Compiling: drivers/encoder/encoder_quadrature.c                                                     [OK]
Compiling: drivers/ws2812.c                                                                         [OK]
Compiling: platforms/chibios/drivers/ws2812_pwm.c                                                  platforms/chibios/drivers/ws2812_pwm.c: In function 'ws2812_init':
platforms/chibios/drivers/ws2812_pwm.c:314:18: error: unknown type name 'PWMConfig'
  314 |     static const PWMConfig ws2812_pwm_config = {
      |                  ^~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:315:9: error: field name not in record or union initializer
  315 |         .frequency = WS2812_PWM_TICK_FREQUENCY,
      |         ^
platforms/chibios/drivers/ws2812_pwm.c:315:9: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:316:9: error: field name not in record or union initializer
  316 |         .period    = WS2812_PWM_PERIOD, // Mit dieser Periode wird UDE-Event erzeugt und ein neuer Wert (Länge WS2812_BIT_N) vom DMA ins CCR geschrieben
      |         ^
platforms/chibios/drivers/ws2812_pwm.c:316:9: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:93:27: error: excess elements in scalar initializer [-Werror]
   93 | #define WS2812_PWM_PERIOD (WS2812_PWM_TICK_FREQUENCY / WS2812_PWM_FREQUENCY) /**< Clock period in PWM ticks. */
      |                           ^
platforms/chibios/drivers/ws2812_pwm.c:316:22: note: in expansion of macro 'WS2812_PWM_PERIOD'
  316 |         .period    = WS2812_PWM_PERIOD, // Mit dieser Periode wird UDE-Event erzeugt und ein neuer Wert (Länge WS2812_BIT_N) vom DMA ins CCR geschrieben
      |                      ^~~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:93:27: note: (near initialization for 'ws2812_pwm_config')
   93 | #define WS2812_PWM_PERIOD (WS2812_PWM_TICK_FREQUENCY / WS2812_PWM_FREQUENCY) /**< Clock period in PWM ticks. */
      |                           ^
platforms/chibios/drivers/ws2812_pwm.c:316:22: note: in expansion of macro 'WS2812_PWM_PERIOD'
  316 |         .period    = WS2812_PWM_PERIOD, // Mit dieser Periode wird UDE-Event erzeugt und ein neuer Wert (Länge WS2812_BIT_N) vom DMA ins CCR geschrieben
      |                      ^~~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:317:9: error: field name not in record or union initializer
  317 |         .callback  = NULL,
      |         ^
platforms/chibios/drivers/ws2812_pwm.c:317:9: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:317:22: error: excess elements in scalar initializer [-Werror]
  317 |         .callback  = NULL,
      |                      ^~~~
platforms/chibios/drivers/ws2812_pwm.c:317:22: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:318:9: error: field name not in record or union initializer
  318 |         .channels =
      |         ^
platforms/chibios/drivers/ws2812_pwm.c:318:9: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:319:13: error: braces around scalar initializer [-Werror]
  319 |             {
      |             ^
platforms/chibios/drivers/ws2812_pwm.c:319:13: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:320:18: error: array index in non-array initializer
  320 |                 [0 ... 3]                = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},    // Channels default to disabled
      |                  ^
platforms/chibios/drivers/ws2812_pwm.c:320:18: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:320:17: error: braces around scalar initializer [-Werror]
  320 |                 [0 ... 3]                = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},    // Channels default to disabled
      |                 ^
platforms/chibios/drivers/ws2812_pwm.c:320:17: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:320:45: error: field name not in record or union initializer
  320 |                 [0 ... 3]                = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},    // Channels default to disabled
      |                                             ^
platforms/chibios/drivers/ws2812_pwm.c:320:45: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:320:53: error: 'PWM_OUTPUT_DISABLED' undeclared (first use in this function)
  320 |                 [0 ... 3]                = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},    // Channels default to disabled
      |                                                     ^~~~~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:320:53: note: each undeclared identifier is reported only once for each function it appears in
platforms/chibios/drivers/ws2812_pwm.c:320:74: error: field name not in record or union initializer
  320 |                 [0 ... 3]                = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},    // Channels default to disabled
      |                                                                          ^
platforms/chibios/drivers/ws2812_pwm.c:320:74: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:320:86: error: excess elements in scalar initializer [-Werror]
  320 |                 [0 ... 3]                = {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},    // Channels default to disabled
      |                                                                                      ^~~~
platforms/chibios/drivers/ws2812_pwm.c:320:86: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:29:32: error: array index in non-array initializer
   29 | #    define WS2812_PWM_CHANNEL 2 // Channel
      |                                ^
platforms/chibios/drivers/ws2812_pwm.c:321:18: note: in expansion of macro 'WS2812_PWM_CHANNEL'
  321 |                 [WS2812_PWM_CHANNEL - 1] = {.mode = WS2812_PWM_OUTPUT_MODE, .callback = NULL}, // Turn on the channel we care about
      |                  ^~~~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:29:32: note: (near initialization for 'ws2812_pwm_config')
   29 | #    define WS2812_PWM_CHANNEL 2 // Channel
      |                                ^
platforms/chibios/drivers/ws2812_pwm.c:321:18: note: in expansion of macro 'WS2812_PWM_CHANNEL'
  321 |                 [WS2812_PWM_CHANNEL - 1] = {.mode = WS2812_PWM_OUTPUT_MODE, .callback = NULL}, // Turn on the channel we care about
      |                  ^~~~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:321:17: error: braces around scalar initializer [-Werror]
  321 |                 [WS2812_PWM_CHANNEL - 1] = {.mode = WS2812_PWM_OUTPUT_MODE, .callback = NULL}, // Turn on the channel we care about
      |                 ^
platforms/chibios/drivers/ws2812_pwm.c:321:17: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:321:45: error: field name not in record or union initializer
  321 |                 [WS2812_PWM_CHANNEL - 1] = {.mode = WS2812_PWM_OUTPUT_MODE, .callback = NULL}, // Turn on the channel we care about
      |                                             ^
platforms/chibios/drivers/ws2812_pwm.c:321:45: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:64:36: error: 'PWM_OUTPUT_ACTIVE_HIGH' undeclared (first use in this function)
   64 | #    define WS2812_PWM_OUTPUT_MODE PWM_OUTPUT_ACTIVE_HIGH
      |                                    ^~~~~~~~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:321:53: note: in expansion of macro 'WS2812_PWM_OUTPUT_MODE'
  321 |                 [WS2812_PWM_CHANNEL - 1] = {.mode = WS2812_PWM_OUTPUT_MODE, .callback = NULL}, // Turn on the channel we care about
      |                                                     ^~~~~~~~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:321:77: error: field name not in record or union initializer
  321 |                 [WS2812_PWM_CHANNEL - 1] = {.mode = WS2812_PWM_OUTPUT_MODE, .callback = NULL}, // Turn on the channel we care about
      |                                                                             ^
platforms/chibios/drivers/ws2812_pwm.c:321:77: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:321:89: error: excess elements in scalar initializer [-Werror]
  321 |                 [WS2812_PWM_CHANNEL - 1] = {.mode = WS2812_PWM_OUTPUT_MODE, .callback = NULL}, // Turn on the channel we care about
      |                                                                                         ^~~~
platforms/chibios/drivers/ws2812_pwm.c:321:89: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:321:44: error: excess elements in scalar initializer [-Werror]
  321 |                 [WS2812_PWM_CHANNEL - 1] = {.mode = WS2812_PWM_OUTPUT_MODE, .callback = NULL}, // Turn on the channel we care about
      |                                            ^
platforms/chibios/drivers/ws2812_pwm.c:321:44: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:319:13: error: excess elements in scalar initializer [-Werror]
  319 |             {
      |             ^
platforms/chibios/drivers/ws2812_pwm.c:319:13: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:327:9: error: field name not in record or union initializer
  327 |         .cr2  = 0,
      |         ^
platforms/chibios/drivers/ws2812_pwm.c:327:9: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:327:17: error: excess elements in scalar initializer [-Werror]
  327 |         .cr2  = 0,
      |                 ^
platforms/chibios/drivers/ws2812_pwm.c:327:17: note: (near initialization for 'ws2812_pwm_config')
platforms/chibios/drivers/ws2812_pwm.c:328:9: error: field name not in record or union initializer
  328 |         .dier = TIM_DIER_UDE, // DMA on update event for next period
      |         ^
platforms/chibios/drivers/ws2812_pwm.c:328:9: note: (near initialization for 'ws2812_pwm_config')
In file included from ./lib/chibios/os/common/ext/ST/STM32F1xx/stm32f1xx.h:149,
                 from ./lib/chibios/os/common/startup/ARMCMx/devices/STM32F1xx/cmparams.h:73,
                 from ./lib/chibios/os/common/ports/ARMv7-M/chcore.h:32,
                 from ./lib/chibios/os/rt/include/chport.h:37,
                 from ./lib/chibios/os/rt/include/ch.h:106,
                 from ./lib/chibios/os/hal/osal/rt-nil/osal.h:32,
                 from ./lib/chibios/os/hal/include/hal.h:30,
                 from ./platforms/chibios/drivers/wear_leveling/wear_leveling_efl_config.h:6,
                 from <command-line>:
./lib/chibios/os/common/ext/ST/STM32F1xx/stm32f103xb.h:3994:45: error: excess elements in scalar initializer [-Werror]
 3994 | #define TIM_DIER_UDE_Msk                    (0x1U << TIM_DIER_UDE_Pos)         /*!< 0x00000100 */
      |                                             ^
./lib/chibios/os/common/ext/ST/STM32F1xx/stm32f103xb.h:3995:45: note: in expansion of macro 'TIM_DIER_UDE_Msk'
 3995 | #define TIM_DIER_UDE                        TIM_DIER_UDE_Msk                   /*!<Update DMA request enable */
      |                                             ^~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:328:17: note: in expansion of macro 'TIM_DIER_UDE'
  328 |         .dier = TIM_DIER_UDE, // DMA on update event for next period
      |                 ^~~~~~~~~~~~
./lib/chibios/os/common/ext/ST/STM32F1xx/stm32f103xb.h:3994:45: note: (near initialization for 'ws2812_pwm_config')
 3994 | #define TIM_DIER_UDE_Msk                    (0x1U << TIM_DIER_UDE_Pos)         /*!< 0x00000100 */
      |                                             ^
./lib/chibios/os/common/ext/ST/STM32F1xx/stm32f103xb.h:3995:45: note: in expansion of macro 'TIM_DIER_UDE_Msk'
 3995 | #define TIM_DIER_UDE                        TIM_DIER_UDE_Msk                   /*!<Update DMA request enable */
      |                                             ^~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:328:17: note: in expansion of macro 'TIM_DIER_UDE'
  328 |         .dier = TIM_DIER_UDE, // DMA on update event for next period
      |                 ^~~~~~~~~~~~
In file included from ./lib/chibios/os/hal/ports/STM32/STM32F1xx/hal_lld.h:216,
                 from ./lib/chibios/os/hal/include/hal.h:249:
platforms/chibios/drivers/ws2812_pwm.c:26:31: error: 'PWMD2' undeclared (first use in this function)
   26 | #    define WS2812_PWM_DRIVER PWMD2 // TIMx
      |                               ^~~~~
./lib/chibios/os/hal/ports/STM32/LLD/DMAv1/stm32_dma.h:366:40: note: in definition of macro 'dmaStreamSetPeripheral'
  366 |   (dmastp)->channel->CPAR = (uint32_t)(addr);                               \
      |                                        ^~~~
platforms/chibios/drivers/ws2812_pwm.c:347:53: note: in expansion of macro 'WS2812_PWM_DRIVER'
  347 |     dmaStreamSetPeripheral(WS2812_PWM_DMA_STREAM, &(WS2812_PWM_DRIVER.tim->CCR[WS2812_PWM_CHANNEL - 1])); // Ziel ist der An-Zeit im Cap-Comp-Register
      |                                                     ^~~~~~~~~~~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:371:5: error: implicit declaration of function 'pwmStart' [-Werror=implicit-function-declaration]
  371 |     pwmStart(&WS2812_PWM_DRIVER, &ws2812_pwm_config);
      |     ^~~~~~~~
platforms/chibios/drivers/ws2812_pwm.c:372:5: error: implicit declaration of function 'pwmEnableChannel' [-Werror=implicit-function-declaration]
  372 |     pwmEnableChannel(&WS2812_PWM_DRIVER, WS2812_PWM_CHANNEL - 1, 0); // Initial period is 0; output will be low until first duty cycle is DMA'd in
      |     ^~~~~~~~~~~~~~~~
cc1: all warnings being treated as errors
 [ERRORS]
 | 
 | 
 | 
make[1]: *** [builddefs/common_rules.mk:362: .build/obj_doio_kb03_default/ws2812_pwm.o] Error 1
Make finished with errors
make: *** [Makefile:415: doio/kb03:default] Error 1
```
**To this:**
```
Compiling: keyboards/doio/kb03/kb03.c                                                               [OK]
Compiling: .build/obj_doio_kb03_default/src/default_keyboard.c                                      [OK]
Compiling: quantum/keymap_introspection.c                                                           [OK]
Compiling: quantum/quantum.c                                                                        [OK]
Compiling: quantum/bitwise.c                                                                        [OK]
Compiling: quantum/led.c                                                                            [OK]
Compiling: quantum/action.c                                                                         [OK]
Compiling: quantum/action_layer.c                                                                   [OK]
Compiling: quantum/action_tapping.c                                                                 [OK]
Compiling: quantum/action_util.c                                                                    [OK]
Compiling: quantum/eeconfig.c                                                                       [OK]
Compiling: quantum/keyboard.c                                                                       [OK]
Compiling: quantum/keymap_common.c                                                                  [OK]
Compiling: quantum/keycode_config.c                                                                 [OK]
Compiling: quantum/sync_timer.c                                                                     [OK]
Compiling: quantum/logging/debug.c                                                                  [OK]
Compiling: quantum/logging/sendchar.c                                                               [OK]
Compiling: quantum/process_keycode/process_default_layer.c                                          [OK]
Compiling: quantum/logging/print.c                                                                  [OK]
Compiling: quantum/matrix_common.c                                                                  [OK]
Compiling: quantum/matrix.c                                                                         [OK]
Compiling: quantum/debounce/sym_defer_g.c                                                           [OK]
Compiling: quantum/main.c                                                                           [OK]
Compiling: lib/printf/src/printf/printf.c                                                           [OK]
Compiling: drivers/eeprom/eeprom_driver.c                                                           [OK]
Compiling: drivers/eeprom/eeprom_wear_leveling.c                                                    [OK]
Compiling: quantum/wear_leveling/wear_leveling.c                                                    [OK]
Compiling: platforms/chibios/drivers/wear_leveling/wear_leveling_efl.c                              [OK]
Compiling: quantum/process_keycode/process_underglow.c                                              [OK]
Compiling: quantum/process_keycode/process_rgb_matrix.c                                             [OK]
Compiling: quantum/color.c                                                                          [OK]
Compiling: quantum/rgb_matrix/rgb_matrix.c                                                          [OK]
Compiling: quantum/rgb_matrix/rgb_matrix_drivers.c                                                  [OK]
Compiling: quantum/led_tables.c                                                                     [OK]
Compiling: lib/fnv/qmk_fnv_type_validation.c                                                        [OK]
Compiling: lib/fnv/hash_32a.c                                                                       [OK]
Compiling: lib/fnv/hash_64a.c                                                                       [OK]
Compiling: lib/lib8tion/lib8tion.c                                                                  [OK]
Compiling: quantum/encoder.c                                                                        [OK]
Compiling: drivers/encoder/encoder_quadrature.c                                                     [OK]
Compiling: drivers/ws2812.c                                                                         [OK]
Compiling: platforms/chibios/drivers/ws2812_pwm.c                                                  In file included from ./lib/chibios/os/hal/ports/STM32/STM32F1xx/hal_lld.h:216,
                 from ./lib/chibios/os/hal/include/hal.h:249,
                 from ./platforms/chibios/drivers/wear_leveling/wear_leveling_efl_config.h:6,
                 from <command-line>:
platforms/chibios/drivers/ws2812_pwm.c: In function 'ws2812_init':
platforms/chibios/drivers/ws2812_pwm.c:347:70: error: request for member 'tim' in something not a structure or union
  347 |     dmaStreamSetPeripheral(WS2812_PWM_DMA_STREAM, &(WS2812_PWM_DRIVER.tim->CCR[WS2812_PWM_CHANNEL - 1])); // Ziel ist der An-Zeit im Cap-Comp-Register
      |                                                                      ^
./lib/chibios/os/hal/ports/STM32/LLD/DMAv1/stm32_dma.h:366:40: note: in definition of macro 'dmaStreamSetPeripheral'
  366 |   (dmastp)->channel->CPAR = (uint32_t)(addr);                               \
      |                                        ^~~~
platforms/chibios/drivers/ws2812_pwm.c:371:14: error: lvalue required as unary '&' operand
  371 |     pwmStart(&WS2812_PWM_DRIVER, &ws2812_pwm_config);
      |              ^
platforms/chibios/drivers/ws2812_pwm.c:372:22: error: lvalue required as unary '&' operand
  372 |     pwmEnableChannel(&WS2812_PWM_DRIVER, WS2812_PWM_CHANNEL - 1, 0); // Initial period is 0; output will be low until first duty cycle is DMA'd in
      |                      ^
 [ERRORS]
 | 
 | 
 | 
make[1]: *** [builddefs/common_rules.mk:362: .build/obj_doio_kb03_default/ws2812_pwm.o] Error 1
Make finished with errors
make: *** [Makefile:415: doio/kb03:default] Error 1
```
**And now I feel very stuck**  
also not very confident in the `define`s I set being correct.  
