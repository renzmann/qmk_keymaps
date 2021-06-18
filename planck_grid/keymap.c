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
#include "quantum.h"
#include "mymacro.h"
#include "mykeys.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Qwerty)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *   Tap for ⇥  -- │ ⌘⇧  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ ⌘⇧  │ -- Tap for '
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │ -- Tap for Enter
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for ( -- │  ⌥  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⌥  │ -- Tap for )
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ CNR │Menu │ Ins │     │  ⌘  │ ⇧/␣ │NUM/␣│ RSE │  ←  │  ↓  │  ↑  │  →  │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [QWERTY_LAYER] = LAYOUT_planck_grid_wrapper(
    TAB_CMDS, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, QTE_CMDS,
    CTL_ESC,  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, CTL_ENT,
    KC_LAPO,  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RAPC,
    CORNER,   KC_APP,  KC_INS,  XXXXXXX, KC_LGUI, SFT_SPC, NUM_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
  ),

  /* Numeric layer
   * Here we don't use shift to activate the special characters. This keeps the left
   * thumb free to surround each special character with spaces.
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  _  │  =  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │     │  +  │  -  │  \  │  `  │  |  │  |  │  ~  │  ,  │  .  │  /  │     │ -- Tap for ]
   *                 ├─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
   *                 │ ADJ │     │     │     │     │     ┃     ┃     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
   */
  [NUM_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _________________NUMUP_L___________________, _________________NUMUP_R___________________, _______,
    _______, __________________NUMS_L___________________, __________________NUMS_R___________________, _______,
    A_LBRC,  _________________TROUGH_L__________________, _________________TROUGH_R__________________, A_RBRC,
    ADJUST,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Corner layer
   *                                                   ,----- Del/BS with left hand only when using mouse (hold corner with palm)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │Prev │Play │Next │ Del │     │ Del │ Del │ MAC │ MAC │     │ -- Trill to delete
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Mute │Vol- │Vol+ │BkSpc│     │BkSpc│BkSpc│ MAC │ MAC │     │ -- Trill to backspace
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │ Tab │ Tab │ MAC │ MAC │     │ -- Swiftly cycle through tab menus
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 ┃     ┃     │     │     │     │BkSpc│ ADJ │     │Home │PgDn │PgUp │ End │
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [CORNER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, __________MEDIA__________, KC_DEL,  _________________CORNER_R1_________________, _______,
    _______, _______, __________VOLUME_________, KC_BSPC, _________________CORNER_R2_________________, _______,
    _______, _______, _______, _______, _______, _______, _________________CORNER_R3_________________, _______,
    _______, _______, _______, _______, _______, KC_BSPC, ADJUST,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  /* Function layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │ F11 │ F12 │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │ F19 │ F20 │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     ┃     ┃     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │ F1  │ F2  │ F3  │ F4  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │ F5  │ F6  │ F7  │ F8  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │RESET│     │     │     │     │     │     │ F9  │ F10 │ F11 │ F12 │     │
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
   *                 ┃     ┃     │Swap │Norm │     │     ┃     ┃     │     │     │     │     │
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/
   */
  [ADJUST_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    _______, _______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    RESET,   _______, _______, _______, _______, _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, AG_SWAP, AG_NORM, _______, _______, _______, _______, _______, _______, _______, _______
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

