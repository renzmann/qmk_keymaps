/* Copyright 2021 Robert Enzmann
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* This keymap is a modified fork of Noah Frederick's:
 * https://github.com/noahfrederick/qmk-keymaps
 */

// TODO replace the bulky stitching layers with code functionality


#include QMK_KEYBOARD_H
#include <stdio.h>
#include <stdlib.h>
#include "mymacro.h"
#include "mykeys.h"


enum user_layers {
  QWERTY_LAYER,
  CAMEL_LAYER,
  KEBAB_LAYER,
  SNAKE_LAYER,
  PATH_LAYER,
  WPATH_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  CORNER_LAYER,
  ADJUST_LAYER
};

// "MY" is usually pretty safe to avoid conflicts
enum user_keycodes {
  MY_EQL = SAFE_RANGE,
  MY_PLUS,
  MY_MINS,
  KC_MAC_A,
  KC_MAC_S,
  KC_MAC_D,
  KC_MAC_F,
  KC_MAC_G,
  KC_MAC_H,
  KC_MAC_J,
  KC_MAC_K,
  KC_MAC_L,
  NEW_SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Qwerty)
   * LSA = left shift + left alt
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * Hold for LSA -- │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  '  │ -- Hold for LSA
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │ -- Tap for Enter
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap for )
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │CORNR│Hyper│  ⌘  │  ⌥  │  ↓  │   Space   │  ↑  │  ⌥  │  ⌘  │Hyper│CORNR│ -- Tap for
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   *                         /                                                     /
   *    Tap for ] [ --------'-----------------------------------------------------'
   */
  [QWERTY_LAYER] = LAYOUT_planck_grid_wrapper(
    LSA_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,   LSA_QT,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, CTL_ENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    CRNR_L,  HYPER_L, KC_LGUI, KC_LALT, LOWER,   KC_SPC,           RAISE,  KC_RALT, KC_LGUI, HYPER_R, CRNR_R,  _______
  ),

  /* Stitching layer (camel)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  Capital  │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [CAMEL_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, CAPITAL,          _______, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (kebab)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     -     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [KEBAB_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_MINS,          _______, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (snake)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     _     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [SNAKE_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_UNDS,          _______, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (path)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     /     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [PATH_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_SLSH,          _______, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (Windows path)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     \     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [WPATH_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_BSLS,          _______, _______, _______, _______, _______, _______
  ),

  /* Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *        Macro -- │" - "│ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │" = "│ -- Macro
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │Shift│  -  │  =  │  `  │  \  │  :  │ndash│mdash│  ,  │  .  │  /  │Shift│ -- Tap for ]
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     ┃     ┃ Backspace │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    MY_MINS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  MY_EQL,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_LSBR, KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_COLN, KC_NDSH, KC_MDSH, KC_COMM, KC_DOT,  KC_SLSH, KC_RSBR,
    _______, _______, _______, _______, _______, KC_BSPC,          ADJUST,  _______, _______, _______, _______, _______
  ),

  /* Symbol layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *        Macro -- │" + "│ F11 │ F12 │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │  _  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  {  │  }  │     │ \
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤  |-- Mostly shifted version of lower layer
   *    Tap for { -- │Shift│  _  │  +  │  ~  │  |  │  :  │ndash│mdash│  ,  │  .  │  /  │Shift│-/-- Tap for }
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  Delete   ┃     ┃     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_grid_wrapper(
    MY_PLUS, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15 , KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20 , KC_UNDS,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______,
    KC_LSCB, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, KC_COLN, KC_NDSH, KC_MDSH, KC_COMM, KC_DOT,  KC_SLSH, KC_RSCB,
    _______, _______, _______, _______, ADJUST,  KC_DEL,           _______, _______, _______, _______, _______, _______
  ),

  /* Corner layer - misc. utilities like arrows, media, stitching layers
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │Vol- │ Prv │Play │Next │Vol+ │WPath│Camel│Kebab│Snake│Path │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ C-z │ C-x │C-Ins│S-Ins│     │     │     │     │     │     │     │
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃     ┃     │     │     │     │           │     │     │     │     ┃     ┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┺━━━━━┛
   */
  [CORNER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, __________________CNR_R1___________________, _______,
    _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, __________________CNR_L3___________________, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_LSFT,          _______, _______, _______, _______, _______, _______
  ),

  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │Reset│     │     │     │     │     │     │ Ins │     │PrScn│     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │Play1│Rec 1│ -- Record/play macro 1
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │Caps │     │     │     │     │     │     │Play2│Rec 2│ -- Record/play macro 2
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │Swap │Norm ┃     ┃  Toggle   ┃     ┃Toggl│Brig-│Brig+│Stop │ -- Stop recording macro
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/             \_____________\_ Backlight _/
   */
  [ADJUST_LAYER] = LAYOUT_planck_grid_wrapper(
    XXXXXXX, RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_INS,   XXXXXXX,  KC_PSCR, XXXXXXX,
    XXXXXXX, KC_MAC_A, KC_MAC_S, KC_MAC_D, KC_MAC_F, KC_MAC_G, KC_MAC_H, KC_MAC_J, KC_MAC_K, KC_MAC_L, DM_PLY1, DM_REC1,
    XXXXXXX, XXXXXXX,  XXXXXXX,  KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DM_PLY2, DM_REC2,
    XXXXXXX, XXXXXXX,  AG_SWAP,  AG_NORM,  _______,  _______,           _______,   XXXXXXX,  XXXXXXX,  XXXXXXX, DM_RSTP, _______
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* Macros defined in mymacro.h. This includes things like passwords, so
     * I don't check this one into source control
     */
    if (record->event.pressed) {
        switch(keycode) {
            case MY_EQL: ;
                SEND_STRING(" = ");
                return false; break;
            case MY_PLUS: ;
                SEND_STRING(" + ");
                return false; break;
            case MY_MINS: ;
                SEND_STRING(" - ");
                return false; break;
            case KC_MAC_A: ;
                SEND_STRING(MAC_A);
                return false; break;
            case KC_MAC_S: ;
                SEND_STRING(MAC_S);
                return false; break;
            case KC_MAC_D: ;
                SEND_STRING(MAC_D);
                return false; break;
            case KC_MAC_F: ;
                SEND_STRING(MAC_F);
                return false; break;
            case KC_MAC_G: ;
                SEND_STRING(MAC_G);
                return false; break;
            case KC_MAC_H: ;
                SEND_STRING(MAC_H);
                return false; break;
            case KC_MAC_J: ;
                SEND_STRING(MAC_J);
                return false; break;
            case KC_MAC_K: ;
                SEND_STRING(MAC_K);
                return false; break;
            case KC_MAC_L: ;
                SEND_STRING(MAC_L);
                return false; break;
        }
    }
    return true;
};
