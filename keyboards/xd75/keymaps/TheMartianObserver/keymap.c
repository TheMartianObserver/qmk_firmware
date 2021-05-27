#include QMK_KEYBOARD_H

#include "oneshot.h"

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define LA_SYM MO(LAYER_L1)
#define LA_NAV MO(LAYER_L2)
#define MSPL C(A(G(S(KC_LEFT))))
#define MSPR C(A(G(S(KC_RIGHT))))
#define ____ KC_TRNS
#define _____ KC_TRNS
#define XXXXX KC_NO

#define C_S LCTL_T(KC_S)
#define A_D LALT_T(KC_D)
#define G_F LGUI_T(KC_F)
#define T_J RGUI_T(KC_J)
#define T_K RALT_T(KC_K)
#define T_L RCTL_T(KC_L)

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

enum layer_names {
    LAYER_BASE,
    LAYER_L1,
    LAYER_L2,
    LAYER_L3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = {
    {KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LCBR, KC_RCBR, KC_6, KC_7, KC_8, KC_9, KC_0, G(KC_BSPC), KC_BSPC},
    {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, A(KC_BSPC), LT(LAYER_L3, KC_DEL)},
    {LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_MINUS, KC_EQL, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT},
    {KC_LGUI, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UNDS, KC_PLUS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, RSFT_T(KC_BSLS)},
    {OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, MO(LAYER_L1), MT(MOD_LSFT, KC_SPC), MO(LAYER_L2), KC_BSPC, LT(LAYER_L1, KC_SPC), MO(LAYER_L1), KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT},
  },


  [LAYER_L1] = {
    {C(A(KC_DEL)), XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX},
    {KC_TAB, KC_PLUS, KC_UNDS, KC_EQL, KC_MINUS, KC_LCBR, XXXXX, XXXXX, KC_RCBR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, XXXXX, XXXXX},
    {KC_CAPS, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, XXXXX, TAB_L, TAB_R, KC_GRV, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT, KC_TILDE, KC_TRNS},
    {____, KC_1, KC_2, KC_3, KC_4, KC_5, XXXXX, XXXXX, KC_6, KC_7, KC_8, KC_9, KC_0, XXXXX, XXXXX},
    {____, ____, ____, ____, ____,____, ____, ____, ____, ____, ____, ____, XXXXX, XXXXX, XXXXX},
  },

  [LAYER_L2] = {
    {XXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, XXXXX,XXXXX, KC_6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12},
    {KC_TAB,  XXXXX, XXXXX, TAB_L, TAB_R, XXXXX, KC_MUTE, XXXXX, XXXXX, KC_PGUP, KC_UP, KC_PGDN, XXXXX, XXXXX, XXXXX},
    {KC_CAPS, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD,  XXXXX, KC_VOLD, KC_VOLU,   XXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, OS_SHFT, XXXXX, XXXXX},
    {_______, MSPL, MSPR,  XXXXX, XXXXX, XXXXX, KC_F14, KC_F15, XXXXX, KC_HOME, XXXXX, KC_HOME, XXXXX, XXXXX, XXXXX},
    {_______, _______, _______, _______, _______,_______, XXXXX, XXXXX,XXXXX, _______, _______, _______, XXXXX, XXXXX, XXXXX},
  },


  [LAYER_L3] = {
    {RESET,  AG_SWAP, AG_NORM, XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX,  C(G(KC_Q))},
    {XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX,    XXXXX,    XXXXX,    XXXXX,   XXXXX, XXXXX, _______},
    {XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX,   XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX,   XXXXX,XXXXX},
    {XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX,   XXXXX,   XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX},
    {XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,XXXXX, XXXXX,   XXXXX,XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX},
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
    case LT(LAYER_L1, KC_SPC):
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
