#include QMK_KEYBOARD_H
#include "quantum.h"
#include "version.h"

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif

enum user_layers {
  QWERTY_LAYER,
  NUM_LAYER,
  NAV_LAYER,
  CORNER_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  ADJUST_LAYER,
  FN_LAYER
};

// "MY" is usually pretty safe to avoid conflicts
enum user_keycodes {
  MY_EQL = SAFE_RANGE,
  MY_PLUS,
  MY_MINS,
  KC_MACA,
  KC_MACS,
  KC_MACD,
  KC_MACF,
  KC_MACG,
  KC_MACH,
  KC_MACJ,
  KC_MACK,
  NEW_SAFE_RANGE
};

// Layers
#define LOWER  MO(LOWER_LAYER)
#define RAISE  MO(RAISE_LAYER)
#define ADJUST LT(ADJUST_LAYER, KC_UNDS)
#define CRNR_L LT(CORNER_LAYER, KC_LBRC)
#define CRNR_R LT(CORNER_LAYER, KC_RBRC)
#define CORNER MO(CORNER_LAYER)
#define FN     MO(FN_LAYER)
#define NAV    MO(NAV_LAYER)
#define NAV_SPC  LT(NAV_LAYER, KC_SPC)
#define NUM_SPC  LT(NUM_LAYER, KC_SPC)
#define CAMEL  DF(CAMEL_LAYER)
#define SNAKE  DF(SNAKE_LAYER)
#define KEBAB  DF(KEBAB_LAYER)

// Modified
#define M_LEFT G(KC_LEFT)
#define M_UP   G(KC_UP)
#define M_DOWN G(KC_DOWN)
#define M_RGHT G(KC_RGHT)

// Tapdance keys
#define RSE_MINS LT(RAISE_LAYER, KC_MINS)
#define KC_LSBR  SFT_T(KC_LBRC)
#define KC_RSBR  SFT_T(KC_RBRC)
#define KC_LSCB  SFT_T(KC_LCBR)
#define KC_RSCB  SFT_T(KC_RCBR)
#define HYPER_L  C_S_T(KC_RBRC)
#define HYPER_R  C_S_T(KC_LBRC)
#define A_TAB    ALT_T(KC_TAB)
#define A_QT     ALT_T(KC_QUOT)
#define A_LBRC   ALT_T(KC_LBRC)
#define A_RBRC   ALT_T(KC_RBRC)
#define TAB_CMDS SGUI_T(KC_TAB)
#define QTE_CMDS SGUI_T(KC_QUOT)
#define CTL_ESC  LCTL_T(KC_ESC)
#define CTL_QUOT LCTL_T(KC_QUOT)
#define CTL_ENT  RCTL_T(KC_ENT)
#define NAV_SCLN LT(NAV_LAYER, KC_SCLN)
#define NAV_BSP  LT(NAV_LAYER, KC_BSPC)
#define CNR_GRV  LT(CORNER_LAYER, KC_GRV)
#define SFT_SPC  SFT_T(KC_SPC)
#define CNR_LBRC LT(CORNER_LAYER, KC_LBRC)
#define CNR_RBRC LT(CORNER_LAYER, KC_RBRC)

// Stitching keys
#define CAPITAL OSM(MOD_LSFT)
#define GUI_GRV LGUI(KC_GRV)
#define STCH_EX DF(QWERTY_LAYER)

// Common rows
#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________SPECIAL_L_________________ KC_PLUS, KC_UNDS, KC_LPRN, KC_TILD, KC_PIPE
#define _________________SPECIAL_R_________________ KC_BSLS, KC_GRV,  KC_RPRN, KC_MINS, KC_EQL

#define __________________NUMS_L___________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________________NUMS_R___________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________NUMUP_L___________________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________NUMUP_R___________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL

#define _________________TROUGH_L__________________ KC_PLUS, KC_MINS, KC_BSLS, KC_GRV,  KC_PIPE
#define _________________TROUGH_R__________________ KC_PIPE, KC_TILD, KC_COMM, KC_DOT,  KC_SLSH

#define __________________NAV_L1___________________ KC_PLUS, KC_UNDS, KC_PGUP, _______, _______
#define __________________NAV_L2___________________ _______, KC_HOME, KC_PGDN, KC_END,  _______
#define __________________NAV_L3___________________ _______, _______, _______, _______, _______

#define __________________NAV_R1___________________ _______, KC_HOME, KC_END,  _______, _______
#define __________________NAV_R2___________________ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define __________________NAV_R3___________________ _______, KC_PGDN, KC_PGUP, _______, _______

#define _________________CORNER_R1_________________ _______, KC_DEL,  KC_DEL,  KC_MACA, KC_MACS
#define _________________CORNER_R2_________________ _______, KC_BSPC, KC_BSPC, KC_MACD, KC_MACF
#define _________________CORNER_R3_________________ _______, KC_TAB,  KC_TAB,  KC_MACG, KC_MACH

#define _______________STITCH_SWITCH_______________ _______, _______, _______, _______, _______

#define __________VOLUME_________ KC_MUTE, KC_VOLD, KC_VOLU
#define __________MEDIA__________ KC_MPRV, KC_MPLY, KC_MNXT

// Expands the row #define things above
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_planck_mit_wrapper(...) LAYOUT_planck_1x2uC(__VA_ARGS__)
#define LAYOUT_planck_2x2u_wrapper(...) LAYOUT_planck_2x2u(__VA_ARGS__)

