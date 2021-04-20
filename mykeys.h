#include "quantum.h"
#include "version.h"

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif

enum user_layers {
  QWERTY_LAYER,
  CAMEL_LAYER,
  KEBAB_LAYER,
  SNAKE_LAYER,
  PATH_LAYER,
  WPATH_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  NAV_LAYER,
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

// Layers
#define LOWER MO(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)
#define ADJUST MO(ADJUST_LAYER)
#define CRNR_L LT(CORNER_LAYER, KC_LBRC)
#define CRNR_R LT(CORNER_LAYER, KC_RBRC)
#define NAV   MO(NAV_LAYER)

// Modified
#define M_LEFT G(KC_LEFT)
#define M_UP   G(KC_UP)
#define M_DOWN G(KC_DOWN)
#define M_RGHT G(KC_RGHT)

// Tapdance keys
#define KC_LSBR SFT_T(KC_LBRC)
#define KC_RSBR SFT_T(KC_RBRC)
#define KC_LSCB SFT_T(KC_LCBR)
#define KC_RSCB SFT_T(KC_RCBR)
#define HYPER_L C_S_T(KC_RBRC)
#define HYPER_R C_S_T(KC_LBRC)
#define LSA_TAB LSA_T(KC_TAB)
#define LSA_QT  LSA_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_ENT RCTL_T(KC_ENT)
#define NAV_SCLN LT(NAV_LAYER, KC_SCLN)
#define NAV_BSP LT(NAV_LAYER, KC_BSPC)
#define NAV_SPC LT(NAV_LAYER, KC_SPC)

// Stitching keys
#define CAPITAL OSM(MOD_LSFT)
#define GUI_GRV LGUI(KC_GRV)
#define STCH_EX DF(QWERTY_LAYER)
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))

// Window manager keys
#define WM_FULL LALT(LGUI(KC_F))
#define WM_NEXT LCTL(LALT(LGUI(KC_RGHT)))
#define WM_PREV LCTL(LALT(LGUI(KC_LEFT)))
#define WM_NW   LCTL(LGUI(KC_LEFT))
#define WM_N    LALT(LGUI(KC_UP))
#define WM_NE   LCTL(LGUI(KC_RGHT))
#define WM_E    LALT(LGUI(KC_RGHT))
#define WM_SE   S(LCTL(LGUI(KC_RGHT)))
#define WM_S    LALT(LGUI(KC_DOWN))
#define WM_SW   S(LCTL(LGUI(KC_LEFT)))
#define WM_W    LALT(LGUI(KC_LEFT))
#define WM_CNTR LALT(LGUI(KC_C))

// Common rows
#define __________________CNR_R1___________________ DF(WPATH_LAYER), DF(CAMEL_LAYER), DF(KEBAB_LAYER), DF(SNAKE_LAYER), DF(PATH_LAYER)
#define __________________CNR_L3___________________ LCTL(KC_Z), LCTL(KC_X), LCTL(KC_INS), LSFT(KC_INS), XXXXXXX

#define __________________NAV_L1___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_L2___________________ XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END
#define __________________NAV_L3___________________ XXXXXXX, LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT)

#define __________________NAV_R1___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_R2___________________ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX
#define __________________NAV_R3___________________ LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), XXXXXXX

#define __________________GUI_L1___________________ KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, XXXXXXX
#define __________________GUI_L2___________________ KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, XXXXXXX
#define __________________GUI_L3___________________ KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX

#define __________________GUI_R1___________________ XXXXXXX, WM_PREV, WM_NW,   WM_N,    WM_NE
#define __________________GUI_R2___________________ XXXXXXX, WM_FULL, WM_W,    WM_CNTR, WM_E
#define __________________GUI_R3___________________ XXXXXXX, WM_NEXT, WM_SW,   WM_S,    WM_SE

#define __________VOLUME_________ KC_MUTE, KC_VOLD, KC_VOLU
#define __________MEDIA__________ KC_MPRV, KC_MPLY, KC_MNXT

// Expands the row #define things above
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
