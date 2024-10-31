# MCU name
MCU = WB32FQ95

# Bootloader selection
BOOTLOADER = wb32-dfu

# Firmware version
SOFTWARE_VERSION = 2

# Build Options
#   change yes to no to disable
#
# 一般固定
KEYBOARD_SHARED_EP = no
BOOTMAGIC_ENABLE = yes         # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes          # Mouse keys
EXTRAKEY_ENABLE = yes          # Audio control and System control
NKRO_ENABLE = yes              # Enable N-Key Rollover
CONSOLE_ENABLE = no            # Console for debug
COMMAND_ENABLE = no            # Commands for debug and configuration
BACKLIGHT_ENABLE = no          # Enable keyboard backlight functionality
AUDIO_ENABLE = no              # Audio output
SUSPEND_STOP_ENABLE = no       # Enter stop mode when the keyboard suspend
HAPTIC_ENABLE = no             # Haptic
RGB_RECORD_ENABLE = no        # Light effect recording
MULTIMODE_ENABLE = yes         # three mode
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = spi_flash
MULTIMODE_DRIVER = uart1

# 可配置功能
ENCODER_ENABLE = no           # Encoder
LED_BLINK_ENABLE = no          # Led blink
RGBLIGHT_ENABLE = no          # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes        # RGB matrix
RGB_MATRIX_BLINK_ENABLE = yes  # RGB matrix blink

RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = spi
# RGBLIGHT_DRIVER = custom
# BACKLIGHT_DRIVER = timer

# GPIO_UART_ENABLE = yes

# Wireless module configuration
RULES_MK_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
include $(RULES_MK_DIR)/../multimode/multimode.mk


OPT_DEFS += -DSMT875_SPP
