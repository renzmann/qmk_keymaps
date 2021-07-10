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
  [QWERTY_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    KC_LCTL, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_ENT,
    KC_ESC,  CORNER,  KC_LALT, RAISE,   LOWER,        KC_SPC,      KC_LGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX
  ),

  /* Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  `  │  1  │  2  │  3  │  4  │  {  │  }  │  !  │  @  │  #  │  \  │ DEL │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  5  │  6  │  7  │  8  │  (  │  )  │  -  │  _  │  *  │  =  │  +  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  9  │  0  │  [  │  ]  │     │     │  &  │  ^  │  %  │  $  │     │
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ ADJ │     │     ┃     ┃           │     │  ⌥  │  ⌘  │  ⇧  │CTRL │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_LCBR, KC_RCBR, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS, KC_DEL,
    _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_LPRN, KC_RPRN, KC_MINS, KC_UNDS, KC_ASTR, KC_EQL,  KC_PLUS,
    _______, KC_9,    KC_0,    KC_LBRC, KC_RBRC, _______, _______, KC_AMPR, KC_CIRC, KC_PERC, KC_DLR,  _______,
    _______, ADJUST,  _______, _______, _______,     _______,      _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX
  ),

  /* Function layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │ F1  │ F2  │ F3  │ F4  │     │     │Caps │ Ins │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ F5  │ F6  │ F7  │ F8  │     │Home │PgDn │PgUp │ End │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ F9  │ F10 │ F11 │ F12 │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────╆━━━━━╅─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     ┃     ┃     │           │     │  ⌥  │  ⌘  │  ⇧  │CTRL │
   *                 └─────┴─────┴─────┺━━━━━┹─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_CAPS, KC_INS,  _______, _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______,     _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX
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
  [CORNER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, __________VOLUME_________, KC_BSPC, _______, _______, _______, _______, _______, _______,
    _______, _______, __________MEDIA__________, KC_DEL,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, ADJUST,      _______,      _______, _______, _______, _______, _______, XXXXXXX
  ),

  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Macro│Macro│Macro│Macro│Macro│Macro│Macro│Macro│     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────╆━━━━━╅─────┼─────╆━━━━━╅─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     ┃     ┃ ⌥/⌘ │     ┃     ┃   RESET   │     │     │     │     │     │
   *                 └─────┺━━━━━┹─────┴─────┺━━━━━┹───────────┴─────┴─────┴─────┴─────┴─────┘
   *          Toggle Alt/GUI swap --'
   */
  [ADJUST_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MACA, KC_MACS, KC_MACD, KC_MACF, KC_MACG, KC_MACH, KC_MACJ, KC_MACK, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, AG_TOGG, _______, _______,       RESET,      _______, _______, _______, _______, _______, XXXXXXX
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Macros defined in mymacro.h. This includes things like passwords, so
     * I don't check them into source control
     */
    if (record->event.pressed) {
        switch(keycode) {
            case KC_MACA: ;
                SEND_STRING(MAC_A);
                return false; break;
            case KC_MACS: ;
                SEND_STRING(MAC_S);
                return false; break;
            case KC_MACD: ;
                SEND_STRING(MAC_D);
                return false; break;
            case KC_MACF: ;
                SEND_STRING(MAC_F);
                return false; break;
            case KC_MACG: ;
                SEND_STRING(MAC_G);
                return false; break;
            case KC_MACH: ;
                SEND_STRING(MAC_H);
                return false; break;
            case KC_MACJ: ;
                SEND_STRING(MAC_J);
                return false; break;
            case KC_MACK: ;
                SEND_STRING(MAC_K);
                return false; break;
        }
    }
    return true;
};

