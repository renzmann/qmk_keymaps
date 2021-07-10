# My planck keyboard layout

I use [QMK Firmware](https://github.com/qmk/qmk_firmware) for my
[planck](https://olkb.com/collections/planck) keyboard. The EZ `keymap.c` and
`keymap.h` are for a [planck EZ from Ergodox](https://ergodox-ez.com/pages/planck),
while the `grid` layout is your standard 48 key planck. The source code is GPL, so
you're free to use and modify it, if you wish. You should be aware, however, that I
use the Rev6 configuration, but on an EZ board. That means there's an extra key
hanging off the edge on the bottom row for all the layers to account for the spacebar
taking up two physical slots, but only one element in the layer array.

## TODO's

1. Build a Makefile for automating linking/compiling/flashing
1. EZ is just a special case of MIT, so we should somehow make those layers common
   accross those files.
