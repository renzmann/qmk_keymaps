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
   *                 │ ESC │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │BkSpc│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ⇥  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │Enter│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ^  │MEDIA│  ⌘  │  ⌥  │LOWER│   Space   │RAISE│  ←  │  ↓  │  ↑  │  →  │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [QWERTY_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_ESC,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
    KC_TAB,  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
    KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_ENT,
    KC_LCTL, HYPER_L, KC_LGUI, KC_LALT,   LOWER,     KC_SPC,     RAISE,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  1  │  2  │  3  │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  4  │  5  │  6  │  0  │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  7  │  8  │  9  │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     ┃     ┃     │     │ ADJ │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _________________SPECIAL_L_________________, _________________SPECIAL_R_________________, _______,
    _______, __________________NUMS_L___________________, __________________NUMS_R___________________, _______,
    _______, _________________TROUGH_L__________________, _________________TROUGH_R__________________, _______,
    _______, _______, _______, _______, _______,          _______, ADJUST,  _______, _______, _______, _______, _______
  ),

  /* Symbol layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  +  │  _  │  (  │  ~  │  |  │  \  │  `  │  )  │  -  │  =  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  {  │  }  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │  {  │  }  │  [  │     │     │  ]  │  ,  │  .  │  /  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │ ADJ │     │     ┃     ┃     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _________________SPECIAL_L_________________, _________________SPECIAL_R_________________, _______,
    _______, _________________NUMUP_L___________________, _________________NUMUP_R___________________, _______,
    _______, _________________TROUGH_L__________________, _________________TROUGH_R__________________, _______,
    _______, _______, _______, _______, ADJUST,           _______, _______, _______, _______, _______, _______, _______
  ),

  /* Media layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │ Del │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Mute │Vol- │Vol+ │BkSpc│     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Prev │Play │Next │     │     │     │     │     │     │     │
   *                 ├─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     ┃     ┃     │     │     │     │     │     │     │     │     │     │
   *                 └─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [CORNER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______,
    _______, _______, __________VOLUME_________, KC_BSPC, _______, _______, _______, _______, _______, _______,
    _______, _______, __________MEDIA__________, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  ),

  /* Keyboard settings layer
   *                          ,--------- F-keys centered over matching #'s ---------.
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │     │
   *                 ├─────╆━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━┷━━━━━╅─────┼─────┼─────┤
   *                 │     ┃                      MACROS                   ┃ F11 │ F12 │     │
   *                 ├─────╄━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━┯━━━━━╃─────┼─────┼─────┤
   *                 │     │     │Swap │Norm │     │     │Stop │Rec 1│Play1│Rec 2│Play2│     │
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │     │     ┃     ┃   RESET   ┃     ┃     │     │     │     │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/
   */
  [ADJUST_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  _______,
    _______, KC_MAC_A, KC_MAC_S, KC_MAC_D, KC_MAC_F, KC_MAC_G, KC_MAC_H, KC_MAC_J, KC_MAC_K, KC_F11,   KC_F12,  _______,
    _______, XXXXXXX,  AG_SWAP,  AG_NORM,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DM_REC1,  DM_PLY1,  DM_REC2,  DM_PLY2, _______,
    _______, _______,  _______,  _______,  _______,            RESET,    _______,  _______,  _______,  _______, _______, _______
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
        }
    }
    return true;
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_GOLDENROD);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif
