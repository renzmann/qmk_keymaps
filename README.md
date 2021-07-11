# My planck keyboard layout

I use [QMK Firmware](https://github.com/qmk/qmk_firmware) for my
[planck](https://olkb.com/collections/planck) keyboard. The EZ `keymap.c` and
`keymap.h` are for a [planck EZ from Ergodox](https://ergodox-ez.com/pages/planck),
while the `grid` layout is your standard 48 key planck. The source code is GPL, so
you're free to use and modify it, if you wish. You should be aware, however, that I
use the Rev6 configuration, but on an EZ board. That means there's an extra key
hanging off the edge on the bottom row for all the layers to account for the spacebar
taking up two physical slots, but only one element in the layer array.

To use the `make` automation, this repo assumes that you've already cloned
`qmk_firmware` from the link above, and that a `.venv` python virtual environment
sits at the top level of that repository that's capable of running the `qmk flash`
command. Assuming that's all done, you can use e.g. `make grid` to flash the
`planck_grid` keymap to your keyboard.

## TODO's

1. EZ is just a special case of MIT, so we should somehow make those layers common
   accross those files.
