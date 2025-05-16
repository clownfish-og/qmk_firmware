Make example for this keyboard (after setting up your build environment):

make leo/x80:default
Flashing example for this keyboard:

make leo/x80:default:flash
To reset the board into bootloader mode, do one of the following:

Hold the Reset switch mounted on the bottom side of the PCB while connecting the USB cable
Hold the Escape key while connecting the USB cable (also erases persistent settings)
Fn+R_Shift+Esc will reset the board to bootloader mode if you have flashed the default QMK keymap