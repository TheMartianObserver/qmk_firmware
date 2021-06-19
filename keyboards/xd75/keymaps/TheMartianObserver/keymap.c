#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

#include <stdbool.h>

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
#define XXXX KC_NO


// Left-hand home row mods
/* #define HOME_A LSFT_T(KC_A) */
/* #define HOME_S LCTL_T(KC_S) */
/* #define HOME_D LALT_T(KC_D) */
/* #define HOME_F LGUI_T(KC_F) */

/* #define HOME_A LCTL_T(KC_A) */
/* #define HOME_S LALT_T(KC_S) */
/* #define HOME_D LGUI_T(KC_D) */
#define HOME_F LSFT_T(KC_F)

/* // Right-hand home row mods */
#define HOME_J RSFT_T(KC_J)
/* #define HOME_K RGUI_T(KC_K) */
/* #define HOME_L RALT_T(KC_L) */
/* #define HOME_SCLN RCTL_T(KC_SCLN) */

#define HOME_A KC_A
#define HOME_S KC_S
#define HOME_D KC_D
/* #define HOME_F KC_F */

/* #define HOME_J KC_J */
#define HOME_K KC_K
#define HOME_L KC_L
#define HOME_SCLN KC_SCLN


enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    SW_WIN,
    SW_APP
};

enum layer_names {
    LAYER_BASE,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_SETTINGS,
    LAYER_NUM,
};

#if 0
// Tap Dance declarations
enum {
    TD_SFT_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(OS_SHFT, KC_CAPS),
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = {
    {KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LCBR, KC_RCBR, KC_6, KC_7, KC_8, KC_9, KC_0, G(KC_BSPC), KC_BSPC},
    {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, A(KC_BSPC), LT(LAYER_SETTINGS, KC_DEL)},
    {LCTL_T(KC_ESC), HOME_A, HOME_S, HOME_D, HOME_F, KC_G, KC_MINUS, KC_EQL, KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, KC_QUOT, KC_ENT},
    {KC_GRV, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UNDS, KC_PLUS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, KC_BSLS},
    {G(KC_SPC), OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, LT(LAYER_NAV, KC_SPC), MO(LAYER_NUM), KC_BSPC, LT(LAYER_SYM, KC_SPC), OS_SHFT, OS_CMD, OS_ALT, KC_LEFT, KC_DOWN, KC_RGHT},
  },

  [LAYER_SYM] = {
    {C(A(KC_DEL)), XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,   XXXX, XXXX, XXXX, XXXX, XXXX},
    {KC_TAB, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, XXXX, XXXX, XXXX, XXXX, KC_LPRN, KC_RPRN, KC_LT, KC_GT, XXXX, XXXX},
    {XXXX, KC_MINS, KC_UNDS, KC_EQL, KC_PLUS, KC_PIPE, XXXX, XXXX, KC_BSLS, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT, XXXX, XXXX},
    {KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, XXXX, XXXX, KC_CIRC, KC_AMPR, KC_ASTR, XXXX, XXXX, ____, ____},
    {____, ____, ____, ____, ____, KC_BSPC, ____, ____, ____, ____, ____, ____, ____, ____, ____},
  },

  [LAYER_NAV] = {
    {XXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, XXXX,XXXX, KC_6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12},
    {KC_TAB, S(KC_TAB), SW_WIN, TAB_L, TAB_R, S(KC_TAB), KC_MUTE, XXXX, KC_DEL, KC_PGUP, XXXX, KC_PGDN, KC_BSPC, XXXX, XXXX},
    {KC_CAPS, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, KC_TAB, KC_VOLD, KC_VOLU, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENT, XXXX, XXXX},
    {KC_GRV, MSPL, MSPR, KC_MPRV, KC_MPLY, KC_MNXT, KC_F14, KC_F15, XXXX, KC_HOME, SW_APP, KC_END, KC_DEL, ____, ____},
    {____, ____, ____, ____, ____,____, ____, ____, KC_BSPC, KC_DEL, ____, ____, ____, ____, ____},
  },


  [LAYER_SETTINGS] = {
    {RESET,  AG_SWAP, AG_NORM, XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX,   XXXX,   XXXX,   XXXX,  A(KC_DEL),  C(G(KC_Q))},
    {____,  XXXX, XXXX, XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX,    XXXX,    XXXX,    XXXX,   XXXX, KC_DEL, ____},
    {____, XXXX, XXXX, XXXX, XXXX,  XXXX, XXXX, XXXX,   XXXX,   XXXX, XXXX, XXXX, XXXX,   XXXX,XXXX},
    {____, XXXX, XXXX, XXXX, XXXX,  XXXX, XXXX, XXXX,   XXXX,   XXXX, XXXX, XXXX, XXXX, XXXX, XXXX},
    {____, ____, ____, ____, ____,____, ____,   ____,____, ____, ____, ____, XXXX, XXXX, XXXX},
  },

  [LAYER_NUM] = {
    {XXXX, XXXX, XXXX, XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX},
    {KC_MINUS, KC_1, KC_2, KC_3, KC_4, KC_5, XXXX, XXXX, KC_6, KC_7, KC_8, KC_9, KC_0, XXXX, XXXX},
    {KC_UNDS, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, XXXX, XXXX, XXXX, XXXX, OS_CMD, OS_ALT, OS_CTRL, OS_SHFT, XXXX, XXXX},
    {XXXX, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, XXXX, XXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXX, XXXX},
    {____, ____, ____, ____, ____,____, ____,  ____,____, ____, ____, ____, XXXX, XXXX, XXXX},
  },
};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
bool sw_win_active = false;
bool sw_app_active = false;

uint16_t os_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool a, b, c, d;

  update_swapper(
      &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
      keycode, record
      );

  update_swapper(
      &sw_app_active, KC_LGUI, KC_GRV, SW_APP,
      keycode, record
      );

  a = update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
  b = update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
  c = update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
  d = update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

  return a && b && c && d;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case KC_LGUI:
    case KC_ESC:
        return true;
    default:
        return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(LAYER_SYM, KC_SPC):
        case LT(LAYER_NAV, KC_SPC):
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
      case LT(LAYER_SYM, KC_SPC):
      case LT(LAYER_NAV, KC_SPC):
      case MO(LAYER_NAV):
      case MO(LAYER_SYM):
      case MO(LAYER_NUM):
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



