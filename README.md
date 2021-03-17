# My planck keyboard layout

I use [QMK Firmware](https://github.com/qmk/qmk_firmware) for my
[planck](https://olkb.com/collections/planck) keyboard. Right now I just
have the one keyboard, and so the `keymap.c` and `keymap.h` are for
a [planck EZ from Ergodox](https://ergodox-ez.com/pages/planck). The
source code is GPL, so you're free to use and modify it, if you wish. You
should be aware, however, that I use the Rev6 configuration, but on an EZ
board. That means there's an extra key hanging off the edge on the bottom
row for all the layers to account for the spacebar taking up two physical
slots, but only one element in the layer array.

I have these files symlinked into a local fork of the QMK Firmware, which
you may find be be a useful way to do it as well.
