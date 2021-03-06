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


#include QMK_KEYBOARD_H
#include "mymacro.h"
#include "mykeys.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Qwerty)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │BkSpc│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │CTRL │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │Enter│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ ESC │MEDIA│  ⌥  │RAISE│LOWER│   Space   │  ⌘  │  ←  │  ↓  │  ↑  │  →  │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [QWERTY_LAYER] = LAYOUT_planck_mit_wrapper(
    KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    KC_LCTL, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_ENT,
    KC_ESC,  CORNER,  KC_LALT, FN,      LOWER,        KC_SPC,      KC_LGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  `  │  1  │  2  │  3  │  4  │  {  │  }  │  !  │  @  │  #  │  \  │ DEL │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  5  │  6  │  7  │  8  │  (  │  )  │  $  │  %  │  ^  │  -  │  =  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  9  │  0  │     │     │  [  │  ]  │  &  │  *  │  _  │  +  │     │
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ ADJ │     │     ┃     ┃           │     │  ⌥  │  ⌘  │  ⇧  │CTRL │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_mit_wrapper(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_SLSH, KC_DEL,
    _______, KC_5,    KC_6,    KC_7,    KC_8,    _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS, KC_EQL,
    _______, KC_9,    KC_7,    _______, _______, _______, _______, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS, _______,
    _______, ADJUST,  _______, _______, _______,     _______,      _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL
  ),

  /* Function layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │ F1  │ F2  │ F3  │ F4  │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ F5  │ F6  │ F7  │ F8  │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ F9  │ F10 │ F11 │ F12 │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────╆━━━━━╅─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     ┃     ┃     │           │     │  ⌥  │  ⌘  │  ⇧  │CTRL │
   *                 └─────┴─────┴─────┺━━━━━┹─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_mit_wrapper(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,     _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL
  ),

  /* Media layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Mute │Vol- │Vol+ │BkSpc│     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Prev │Play │Next │ Del │     │     │     │     │     │     │
   *                 ├─────╆━━━━━╅─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     ┃     ┃     │     │ ADJ │           │     │     │     │     │     │
   *                 └─────┺━━━━━┹─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [CORNER_LAYER] = LAYOUT_planck_mit_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, __________VOLUME_________, KC_BSPC, _______, _______, _______, _______, _______, _______,
    _______, _______, __________MEDIA__________, KC_DEL,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
  ),

  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────╆━━━━━╅─────┼─────╆━━━━━╅─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     ┃     ┃     │     ┃     ┃   RESET   │     │     │     │     │     │
   *                 └─────┺━━━━━┹─────┴─────┺━━━━━┹───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [ADJUST_LAYER] = LAYOUT_planck_mit_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,       RESET,      _______, _______, _______, _______, _______
  )
};
