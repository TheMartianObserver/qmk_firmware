#include QMK_KEYBOARD_H

#include "oneshot.h"

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))
#define LA_SYM LT(_L1, KC_SPC)
#define LA_NAV OSL(_L2)

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};

enum layer_names {
    _QW,
    _L1,
    _L2,
    _L3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_ortho_5x15(
        KC_ESC,               KC_1,         KC_2,    KC_3,    KC_4,    KC_5, KC_MINUS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   G(KC_BSPC), KC_BSPC,
        KC_TAB,               KC_Q,         KC_W,    KC_E,    KC_R,    KC_T, KC_UNDS, KC_PLUS,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  A(KC_BSPC), LT(3, KC_DEL),
        LCTL_T(KC_ESC), KC_A,         KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
        KC_LGUI,        KC_Z,         KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN,   KC_N,    KC_M,    KC_COMM, KC_DOT,  LGUI_T(KC_SLSH), KC_UP, RSFT_T(KC_BSLS),
        OS_SHFT, OS_CTRL, KC_NO, OS_ALT, OS_CMD, LSFT_T(KC_SPC),  LT(1, KC_DEL), KC_BSPC, LT(_L1, KC_SPC), OSL(_L2), KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_L1] = LAYOUT_ortho_5x15(
        C(A(KC_DEL)),        KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,KC_NO, KC_6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TAB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_NO, KC_NO, KC_6,    KC_7,    KC_8,    KC_9,   KC_0, KC_NO, KC_NO,
         KC_CAPS, KC_MINUS, KC_UNDS, KC_EQL, KC_PLUS, KC_LCBR, KC_NO,   G(KC_LCBR),   KC_GRV, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT, KC_NO, KC_TRNS,
         _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,  KC_RCBR, KC_NO,  G(KC_RCBR),   KC_TILDE,   KC_QUOT, KC_DQUO, KC_GRV, KC_TILDE, KC_NO, KC_NO,
         _______, _______, _______, _______, _______,_______, _______,   _______,KC_NO, _______, _______, _______, KC_NO, KC_NO, KC_NO
    ),

    [_L2] = LAYOUT_ortho_5x15(
        C(A(KC_DEL)),        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_DEL,
        KC_NO,  KC_TAB,         KC_NO,         KC_NO,         KC_NO,          KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO,    KC_UP,    KC_NO,   KC_NO, KC_NO, KC_NO,
         KC_NO, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD,  KC_NO, KC_VOLU,   KC_F15,   KC_BSPC,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL, KC_NO, KC_ENT,
         _______, C(A(G(S(KC_LEFT)))), C(A(G(S(KC_RIGHT)))),  KC_NO,         KC_NO,          KC_NO, KC_VOLD,   KC_F14,   KC_NO,   KC_NO, G(KC_DOWN), KC_NO, KC_NO, KC_NO, KC_NO,
         _______, _______, _______, _______, _______,_______, KC_NO,   KC_NO,KC_NO, _______, _______, _______, KC_NO, KC_NO, KC_NO
    ),


    [_L3] = LAYOUT_ortho_5x15(
        RESET,  AG_SWAP, AG_NORM, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  C(G(KC_Q)),
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO, KC_NO, _______,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO, KC_NO,   KC_NO,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

uint16_t os_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool a, b, c, d;

  a = update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
  b = update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
  c = update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
  d = update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);
  return a && b && c && d;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LGUI:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}
