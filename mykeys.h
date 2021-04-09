// Layers
#define LOWER MO(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)
#define ADJUST MO(ADJUST_LAYER)
#define CRNR_L LT(CORNER_LAYER, KC_LBRC)
#define CRNR_R LT(CORNER_LAYER, KC_RBRC)

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

// Stitching keys
#define CAPITAL OSM(MOD_LSFT)
#define GUI_GRV LGUI(KC_GRV)
#define STCH_EX DF(QWERTY_LAYER)
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))

// Common rows
#define __________________CNR_R1___________________ DF(WPATH_LAYER), DF(CAMEL_LAYER), DF(KEBAB_LAYER), DF(SNAKE_LAYER), DF(PATH_LAYER)
#define __________________CNR_L3___________________ LCTL(KC_Z), LCTL(KC_X), LCTL(KC_INS), LSFT(KC_INS), XXXXXXX

// Expands the row #define things above
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)