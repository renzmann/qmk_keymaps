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
   * TODO we'll have to define our own tapdance thing to get underscore on tap: https://beta.docs.qmk.fm/using-qmk/software-features/feature_tap_dance#example-5-using-tap-dance-for-advanced-mod-tap-and-layer-tap-keys-id-example-5
   * LSA = left shift + left alt
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *  Hold for ⌥  -- │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  '  │ -- Hold for ⌥
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │ -- Tap for Enter
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap for )
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │ CNR │ ⌃⇧  │  ⌥  │  ⌘  │  ↓  │SfSpc│NAVSp│  ↑  │  ⌘  │  ⌥  │ ⌃⇧  │ CNR │ -- Tap for ]
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                         /                       Tap for "_" /                 /
   *    Tap for ] [ --------'-----------------------------------------------------'
   */
  [QWERTY_LAYER] = LAYOUT_planck_grid_wrapper(
    LSA_TAB, _________________QWERTY_L1_________________,   _________________QWERTY_R1_________________,   LSA_QT,
    CTL_ESC, _________________QWERTY_L2_________________,   _________________QWERTY_R2_________________,   CTL_ENT,
    KC_LSPO, _________________QWERTY_L3_________________,   _________________QWERTY_R3_________________,   KC_RSPC,
    CNR_LBRC, HYPER_L, KC_LALT, KC_LGUI, LOWER, SFT_SPC, NAV_SPC, TD(RSE_UNDS), KC_RGUI, KC_RALT, HYPER_R, CNR_RBRC
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
    _______, _______, _______, _______, _______, KC_LSFT, CAPITAL, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, _______, KC_LSFT, KC_MINS, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, _______, KC_LSFT, KC_UNDS, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, _______, KC_LSFT, KC_SLSH, _______, _______, _______, _______, _______
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
    _______, _______, _______, _______, _______, KC_LSFT, KC_BSLS, _______, _______, _______, _______, _______
  ),

  /* Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  _  │  =  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  +  │  -  │  \  │  `  │  |  │  |  │  ~  │  ,  │  .  │  /  │     │
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     ┃     ┃     │     │ ADJ │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _________________NUMUP_L___________________, _________________NUMUP_R___________________, _______,
    _______, __________________NUMS_L___________________, __________________NUMS_R___________________, _______,
    _______, _________________TROUGH_L__________________, _________________TROUGH_R__________________, _______,
    _______, _______, _______, _______, _______, _______, _______, ADJUST,  _______, _______, _______, _______
  ),

  /* Symbol layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  +  │  _  │  (  │  ~  │  |  │  \  │  `  │  )  │  -  │  =  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  {  │  }  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  +  │  -  │  \  │  `  │  |  │  |  │  ~  │  ,  │  .  │  /  │CAPS │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │ ADJ │     │     ┃     ┃     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _________________SPECIAL_L_________________, _________________SPECIAL_R_________________, _______,
    _______, _________________NUMUP_L___________________, _________________NUMUP_R___________________, _______,
    _______, _________________TROUGH_L__________________, _________________TROUGH_R__________________, KC_CAPS,
    _______, _______, _______, _______, ADJUST,  _______, _______, _______, _______, _______, _______, _______
  ),

  /* Directional navigation layer
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  +  │  _  │PgUp │     │     │     │Home │ End │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Home │PgDn │ End │     │  ←  │  ↓  │  ↑  │  →  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │PgUp │PgDn │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     ┃     ┃     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
   */
  [NAV_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, __________________NAV_L1___________________, __________________NAV_R1___________________, _______,
    _______, __________________NAV_L2___________________, __________________NAV_R2___________________, _______,
    _______, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
    _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______
  ),

  /* Corner (window management/mouse/media controls) layer
   *                                                   ,----- Del/BS with left hand only when using mouse (hold corner with palm)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │Prev │Play │Next │ Del │     │ Del │ Del │     │     │     │ -- Trill to delete
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │Mute │Vol- │Vol+ │BkSpc│     │BkSpc│BkSpc│     │     │     │ -- Trill to backspace
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │CAMEL│SNAKE│KEBAB│     │     │ Tab │ Tab │     │     │     │ -- Swiftly cycle through tab menus
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃     ┃     │     │     │     │     │     │     │     │     │     ┃     ┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
   */
  [CORNER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, __________MEDIA__________, KC_DEL,  _________________CORNER_R1_________________, _______,
    _______, _______, __________VOLUME_________, KC_BSPC, _________________CORNER_R2_________________, _______,
    _______, _______________STITCH_SWITCH_______________, _________________CORNER_R3_________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
    _______, _______,  _______,  _______,  _______,  RESET,    RESET,    _______,  _______,  _______,  _______, _______
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

// Tapdance definitions
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode
void rseunds_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_UNDS);
            break;
        case TD_SINGLE_HOLD:
            layer_on(RAISE_LAYER);
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 underscores `__` within tapping term
            tap_code16(KC_UNDS);
            register_code16(KC_UNDS);
            break;
        default:
            ;
    }
}

void rseunds_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_UNDS);
            break;
        case TD_SINGLE_HOLD:
            layer_off(RAISE_LAYER);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_UNDS);
            break;
        default:
            ;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [RSE_UNDS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rseunds_finished, rseunds_reset)
};

