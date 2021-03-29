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
  NEW_SAFE_RANGE
};

#define LOWER MO(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)
#define ADJUST MO(ADJUST_LAYER)
#define CRNR_L LT(CORNER_LAYER, KC_LBRC)
#define CRNR_R LT(CORNER_LAYER, KC_RBRC)
#define KC_LSBR SFT_T(KC_LBRC)
#define KC_RSBR SFT_T(KC_RBRC)
#define KC_LSCB SFT_T(KC_LCBR)
#define KC_RSCB SFT_T(KC_RCBR)
#define HYPER_L C_S_T(KC_RBRC)
#define HYPER_R C_S_T(KC_LBRC)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_ENT RCTL_T(KC_ENT)
#define NAV_SCLN LT(NAV_LAYER, KC_SCLN)
#define CAPITAL OSM(MOD_LSFT)
#define GUI_GRV LGUI(KC_GRV)
#define STCH_EX DF(QWERTY_LAYER)
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))
#define __________________CNR_R1___________________ DF(WPATH_LAYER), DF(CAMEL_LAYER), DF(KEBAB_LAYER), DF(SNAKE_LAYER), DF(PATH_LAYER)
#define __________________CNR_L3___________________ LCTL(KC_Z), LCTL(KC_X), LCTL(KC_INS), LSFT(KC_INS), XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Qwerty)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  '  │
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
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_QUOT,
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
    MY_MINS, _________________LOWER_L1__________________, _________________LOWER_R1__________________, MY_EQL,
    _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,
    KC_LSBR, _________________LOWER_L3__________________, _________________LOWER_R3__________________, KC_RSBR,
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
    MY_PLUS, _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_UNDS,
    _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,
    KC_LSCB, _________________RAISE_L3__________________, _________________RAISE_R3__________________, KC_RSCB,
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
    XXXXXXX, RESET,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, KC_PSCR,         XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DYN_MACRO_PLAY1, DYN_REC_START1,
    XXXXXXX, XXXXXXX, XXXXXXX,   KC_CAPS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DYN_MACRO_PLAY2, DYN_REC_START2,
    XXXXXXX, XXXXXXX, AG_SWAP,   AG_NORM,  _______, LIT_TOG,          _______, XXXXXXX, XXXXXXX, XXXXXXX,         DYN_REC_STOP, _______
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MY_EQL:
                SEND_STRING(" = ")
                return false; break;
            case MY_PLUS:
                SEND_STRING(" + ")
                return false; break;
            case MY_MINS:
                SEND_STRING(" - ")
                return false; break;
        }
    }
    return true;
};
