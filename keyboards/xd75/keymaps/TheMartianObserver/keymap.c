#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _L1,
    _L2,
    _L3,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_ortho_5x15(
        KC_ESC,        KC_1,         KC_2,    KC_3,    KC_4,    KC_5, KC_NO, C(G(KC_Q)),  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_DEL,  KC_BSPC,
        KC_TAB,        KC_Q,         KC_W,    KC_E,    KC_R,    KC_T, KC_NO, KC_NO,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_GRV, MO(3),
        MT(MOD_LCTL, KC_ESC), MT(MOD_LSFT, KC_A),         MT(MOD_LCTL, KC_S),    MT(MOD_LALT, KC_D),    MT(MOD_LGUI, KC_F),    KC_G,    KC_HOME, KC_PGUP,   KC_H,    MT(MOD_RGUI, KC_J),    MT(MOD_RALT, KC_K),    MT(MOD_RCTL, KC_L),   MT(MOD_RSFT, KC_SCLN), KC_QUOT, KC_ENT,
        OSM(MOD_LSFT), KC_Z,         KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN,   KC_N,    KC_M,    KC_COMM, KC_DOT,  LGUI_T(KC_SLSH), KC_UP, RSFT_T(KC_BSLS),
        OSM(MOD_HYPR), OSM(MOD_MEH), OSM(MOD_LCTL), OSM(MOD_LALT),OSM(MOD_LGUI),  LSFT_T(KC_SPC),  LT(2, KC_DEL), LT(2, KC_BSPC), LT(1, KC_SPC), OSM(MOD_RGUI), OSM(MOD_RALT), OSM(MOD_RCTL), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_L1] = LAYOUT_ortho_5x15(
        KC_NO,        KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,KC_NO, KC_6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        C(A(KC_DEL)), KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_NO, KC_NO, KC_6,    KC_7,    KC_8,    KC_9,   KC_0, KC_NO, KC_NO,
         KC_CAPS, KC_MINUS, KC_UNDS, KC_EQL, KC_PLUS, KC_LPRN, KC_NO,   KC_NO,   KC_NO, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_ENT, KC_NO,
         KC_NO, KC_LBRC, KC_RBRC, KC_LCBR,  KC_RCBR, KC_RPRN, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         _______, _______, _______, _______, _______,_______, KC_NO,   KC_NO,KC_NO, _______, _______, _______, KC_NO, KC_NO, KC_NO
    ),

    [_L2] = LAYOUT_ortho_5x15(
        KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,         KC_NO,         KC_NO,         KC_NO,          KC_NO, KC_MUTE, KC_NO, KC_NO,    KC_NO,    KC_UP,    KC_NO,   KC_NO, KC_NO, KC_NO,
         KC_NO, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI),  KC_NO, KC_VOLU,   KC_F15,   KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_ENT, KC_NO,
         KC_NO, KC_NO,         KC_NO,         KC_NO,         KC_NO,          KC_NO, KC_VOLD,   KC_F14,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         _______, _______, _______, _______, _______,_______, KC_NO,   KC_NO,KC_NO, _______, _______, _______, KC_NO, KC_NO, KC_NO
    ),


    [_L3] = LAYOUT_ortho_5x15(
        RESET,  CG_SWAP, CG_NORM, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO, KC_NO, _______,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO, KC_NO,   KC_NO,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
};
