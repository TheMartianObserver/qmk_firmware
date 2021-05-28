#include QMK_KEYBOARD_H

#include "oneshot.h"

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define LA_SYM OSL(LAYER_SYM)
#define LA_NAV OSL(LAYER_NAV)
#define MSPL C(A(G(S(KC_LEFT))))
#define MSPR C(A(G(S(KC_RIGHT))))
#define ____ KC_TRNS
#define _____ KC_TRNS
#define XXXX KC_NO

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

enum layer_names {
    LAYER_BASE,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_SETTINGS,
    LAYER_SYM2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = {
    {KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LCBR, KC_RCBR, KC_6, KC_7, KC_8, KC_9, KC_0, G(KC_BSPC), KC_BSPC},
    {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, A(KC_BSPC), LT(LAYER_SETTINGS, KC_DEL)},
    {LCTL_T(KC_ESC), KC_A, KC_S, KC_D, LSFT_T(KC_F), KC_G, KC_MINUS, KC_EQL, KC_H, RSFT_T(KC_J), KC_K, KC_L, LT(LAYER_SYM2, KC_SCLN), KC_QUOT, KC_ENT},
    {KC_LGUI, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UNDS, KC_PLUS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, KC_BSLS},
    {OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, LA_NAV, LSFT_T(KC_SPC), G(KC_SPC), KC_BSPC, LT(LAYER_SYM, KC_SPC), LA_SYM, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT},
  },


  [LAYER_SYM] = {
    {C(A(KC_DEL)), XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,   XXXX, XXXX, XXXX, XXXX, XXXX},
    {____, KC_ESC, KC_LBRC, KC_LCBR, KC_LPRN, KC_TILDE, XXXX, XXXX, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV, XXXX, XXXX},
    {XXXX, KC_MINS, KC_ASTR, KC_EQL, KC_UNDS, KC_DLR, XXXX, XXXX, KC_HASH, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT, XXXX, XXXX},
    {XXXX, KC_PLUS, KC_PIPE, KC_AT, KC_SLASH, KC_PERC, XXXX, XXXX, XXXX, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM, XXXX, XXXX},
    {____, ____, ____, ____, ____,____, ____, ____, ____, ____, ____, ____, XXXX, XXXX, XXXX},
  },

  [LAYER_NAV] = {
    {XXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, XXXX,XXXX, KC_6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12},
    {XXXX, KC_TAB,  G(KC_GRV), TAB_L, TAB_R, KC_VOLU, KC_MUTE, XXXX, XXXX, KC_PGUP, KC_UP, KC_PGDN, KC_DEL, XXXX, XXXX},
    {KC_CAPS, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, KC_VOLD, XXXX, XXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC, XXXX, XXXX},
    {XXXX, MSPL, MSPR, KC_MPRV, KC_MPLY, KC_MNXT, KC_F14, KC_F15, XXXX, KC_HOME, XXXX, KC_END, KC_ENT, XXXX, XXXX},
    {____, ____, ____, ____, ____,____, XXXX, XXXX,XXXX, ____, ____, ____, XXXX, XXXX, XXXX},
  },


  [LAYER_SETTINGS] = {
    {RESET,  AG_SWAP, AG_NORM, XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX,   XXXX,   XXXX,   XXXX,  XXXX,  C(G(KC_Q))},
    {XXXX,  XXXX, XXXX, XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX,    XXXX,    XXXX,    XXXX,   XXXX, XXXX, ____},
    {XXXX, XXXX, XXXX, XXXX, XXXX,  XXXX, XXXX, XXXX,   XXXX,   XXXX, XXXX, XXXX, XXXX,   XXXX,XXXX},
    {XXXX, XXXX, XXXX, XXXX, XXXX,  XXXX, XXXX, XXXX,   XXXX,   XXXX, XXXX, XXXX, XXXX, XXXX, XXXX},
    {XXXX, XXXX, XXXX, XXXX, XXXX,XXXX, XXXX,   XXXX,XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX},
  },

  [LAYER_SYM2] = {
    {XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX},
    {XXXX, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX},
    {XXXX, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, XXXX, XXXX, XXXX, XXXX, KC_MINUS, KC_EQL, XXXX, _____, XXXX, XXXX},
    {XXXX, XXXX, XXXX, KC_LCBR, KC_RCBR, XXXX, XXXX, XXXX, XXXX, KC_UNDS, KC_PLUS, XXXX, XXXX, XXXX, XXXX},
    {____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, XXXX, XXXX, XXXX},
  },
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
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

#if 0
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LALT_T(KC_D):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LGUI_T(KC_F):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RCTL_T(KC_J):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(KC_K):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RGUI_T(KC_L):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}
#endif
