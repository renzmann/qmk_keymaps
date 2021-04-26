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


#include QMK_KEYBOARD_H
#include "mymacro.h"
#include "mykeys.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Qwerty)
   * LSA = left shift + left alt
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * Hold for LSA -- │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  '  │ -- Hold for LSA
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │ -- Tap for Enter
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap for )
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │ NAV │Hyper│  ⌥  │  ⌘  │  ↓  │Space│CORNR│  ↑  │  ⌘  │  ⌥  │Hyper│ NAV │ -- Tap for
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                         /                                                     /
   *    Tap for ] [ --------'-----------------------------------------------------'
   */
  [QWERTY_LAYER] = LAYOUT_planck_grid_wrapper(
    LSA_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    LSA_QT,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, CTL_ENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    NAV,     HYPER_L, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  CNR_SPC, RAISE,  KC_RGUI, KC_RALT, HYPER_R, NAV
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
    _______, _______, _______, _______, _______, CAPITAL, CAPITAL, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, _______, KC_MINS, KC_MINS, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, _______, KC_UNDS, KC_UNDS, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, _______, KC_SLSH, KC_SLSH, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, _______, KC_BSLS, KC_BSLS, _______, _______, _______, _______, _______
  ),

  //TODO common top layers to .h file
  /* Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │ Del │  _  │  +  │  |  │  ~  │  (  │  )  │  `  │  \  │  -  │  =  │BkSpc│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │Shift│  -  │  =  │  `  │  [  │  {  │  }  │  ]  │  ,  │  .  │  /  │Shift│ -- Tap for ]
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     ┃     ┃Space│Space│ ADJ │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_DEL,  KC_UNDS, KC_PLUS, KC_PIPE, KC_TILD, KC_LPRN, KC_RPRN, KC_GRV,  KC_BSLS, KC_MINS, KC_EQL,  KC_BSPC,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_LSBR, KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, KC_RSBR,
    _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  ADJUST,  _______, _______, _______, _______
  ),

  /* Symbol layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │ Del │  _  │  +  │  |  │  ~  │  (  │  )  │  `  │  \  │  -  │  =  │BkSpc│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  {  │  }  │     │ \
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤  |-- Mostly shifted version of lower layer
   *    Tap for { -- │Shift│  _  │  +  │  ~  │  [  │  {  │  }  │  ]  │  ,  │  .  │  /  │Shift│-/-- Tap for }
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │ ADJ │Space│Space┃     ┃     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_DEL,  KC_UNDS, KC_PLUS, KC_PIPE, KC_TILD, KC_LPRN, KC_RPRN, KC_GRV,  KC_BSLS, KC_MINS, KC_EQL,  KC_BSPC,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______,
    KC_LSCB, KC_UNDS, KC_PLUS, KC_TILD, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, KC_RSCB,
    _______, _______, _______, _______, ADJUST,  KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______
  ),

  // TODO move the parens back toward the center
  /* Directional navigation layer
   *
   *          Large movements -----/```````````````````\   /```````````````````\----- Vim-style arrow keys
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │ Del │     │  {  │  [  │  (  │     │     │  )  │  ]  │  }  │     │BkSpc│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Home │PgUp │PgDn │ End │  ←  │  ↓  │  ↑  │  →  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │ ⌘ ← │ ⌘ ↑ │ ⌘ ↓ │ ⌘ → │ ⌥ ← │ ⌥ ↓ │ ⌥ ↑ │ ⌥ → │     │     │
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃     ┃     │     │     │     │Shift│Shift│     │     │     │     ┃     ┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
   */
  [NAV_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_DEL,  KC_UNDS, KC_LCBR, KC_LBRC, KC_LPRN, _______, _______, KC_RPRN, KC_RBRC, KC_RCBR, KC_EQL,  KC_BSPC,
    _______, __________________NAV_L2___________________, __________________NAV_R2___________________, _______,
    _______, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
    _______, _______, _______, _______, XXXXXXX, KC_LSFT, KC_RSFT, XXXXXXX, _______, _______, _______, _______
  ),

  // TODO rename from "corner" to something else
  /* GUI (window management/mouse/media controls) layer
   *
   *         Mouse keys -----/```````````````````\               /```````````````````\----- Window manager
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │Ms B2│Prev │Play │Next │     │     │Prev │ NW  │  N  │ NE  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Ms L │Mute │Vol- │Vol+ │     │     │Full │  W  │Centr│  E  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Undo │ Cut │Copy │Paste│     │     │Next │ SW  │  S  │ SE  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     ┃     ┃     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
   */
  [CORNER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, __________MEDIA__________, _______, __________________GUI_R1___________________, _______,
    _______, _______, __________VOLUME_________, _______, __________________GUI_R2___________________, _______,
    _______, __________________GUI_L3___________________, __________________GUI_R3___________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │
   *                 ├─────╆━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━╅─────┼─────┤
   *                 │     ┃                          MACROS                     ┃Play1│Rec 1│ -- Record/play macro 1
   *                 ├─────╄━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━╃─────┼─────┤
   *                 │     │     │     │Caps │     │     │     │     │     │     │Play2│Rec 2│ -- Record/play macro 2
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │Swap │Norm ┃     ┃   RESET   ┃     ┃Toggl│Brig-│Brig+│Stop │ -- Stop recording macro
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/             \_____________\_ Backlight _/
   */
  [ADJUST_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,
    XXXXXXX, KC_MAC_A, KC_MAC_S, KC_MAC_D, KC_MAC_F, KC_MAC_G, KC_MAC_H, KC_MAC_J, KC_MAC_K, KC_MAC_L, DM_PLY1, DM_REC1,
    XXXXXXX, XXXXXXX,  XXXXXXX,  KC_CAPS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DM_PLY2, DM_REC2,
    XXXXXXX, XXXXXXX,  AG_SWAP,  AG_NORM,  _______,  RESET,    RESET,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX, DM_RSTP
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


void convert_hsl_scale(int *hue, int *sat, int *val)
{
    *hue = (int)((float)*hue / 360.0 * 255.0);
    *sat = (int)((float)*sat * 255.0);
    *val = (int)((float)*val * 255.0);
}


#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    /* int h = 55; */
    /* int s = 59; */
    /* int l = 54; */

    /* convert_hsl_scale(&h, &s, &l); */

    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_GOLDENROD);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif
