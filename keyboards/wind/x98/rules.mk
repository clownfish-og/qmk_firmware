# Configure for 128K flash
MCU_LDSCRIPT = STM32F103xB

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

#VIAL_INSECURE = yes    #禁用启动VIAL恶意刷新固件的按键
