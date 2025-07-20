# Pangea Solder (PNG-S Alpha RC2)

![Bowl Pangea Solder](https://via.placeholder.com/800x400?text=Bowl+Pangea+Solder)

The PNG-S Alpha RC2 is the solder variant of the Bowl Pangea full-size mechanical keyboard. It features traditional solder-mount switches and per-key backlight support.

* Keyboard Maintainer: [Gondolindrim](https://github.com/Gondolindrim)
* Hardware Supported: STM32F401-based PCB with solder pads
* Hardware Availability: Contact Bowl directly

## Build Examples

Make example for this keyboard (after setting up your build environment):

    make bowl/pangea/solder:default

Flashing example for this keyboard:

    make bowl/pangea/solder:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
