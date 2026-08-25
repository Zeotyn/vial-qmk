# Lily58 Pro

Lily58 Pro is a Lily58-layout split keyboard on an RP2040-based PCB (Khor Store), with per-half RGB underglow and OLED support.

* Keyboard Maintainer: [zeotyn](https://github.com/zeotyn)
* Hardware Supported: Lily58 Pro PCB (RP2040)
* Hardware Availability: Khor Store

Make example for this keyboard (after setting up your build environment):

    make lily58_pro:zeotyn

Flashing example for this keyboard:

    make lily58_pro:zeotyn:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
