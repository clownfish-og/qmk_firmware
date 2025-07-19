# Wind X98 R2 by Windstudio

![WindX98 R2](FIXME: add link!!!)

QMK firmware for the wired PCB variant of Wind X98 R2. [More info on geekhack.org](https://geekhack.org/index.php?topic=122107.0)

- Keyboard Maintainer: [ClownFish](https://github.com/clownfish-og)
- Hardware Supported: Wind X98 R2 wired PCB with STM32F103CBT6 MCU
- Hardware Availability: [windstudio.store](https://windstudio.store/collections/wind-x98-r2)

Make example for this keyboard (after setting up your build environment):

    make windstudio/wind_x98/r2:default

Flashing example for this keyboard:

    make windstudio/wind_x98/r2:default:flash

See the [build environment setup](getting_started_build_tools) and the [make instructions](getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](newbs).

## Bootloader

Enter the bootloader in 3 ways:

- **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
- **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
- **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
