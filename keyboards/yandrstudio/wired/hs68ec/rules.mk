# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
COMMAND_ENABLE = no         # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover

CUSTOM_MATRIX = lite    # for using the A9 pin as matrix io
QUANTUM_SRC += matrix_ec.c
# QUANTUM_SRC += my_adc_drv_m.c
QUANTUM_SRC += my_adc_drv.c

# KEYBOARD_SHARED_EP = yes
# CONSOLE_ENABLE = yes
# DEBUG_MATRIX_SCAN_RATE_ENABLE = yes

ALLOW_WARNINGS = yes
