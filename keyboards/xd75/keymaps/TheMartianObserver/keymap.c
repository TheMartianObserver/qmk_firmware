#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _L1,
    _L2,
    _L3,
};

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))
#define LA_SYM MO(_L1)
#define LA_NAV MO(_L2)

// One shot implementation from callum-oakley
// Represents the four states a oneshot key can be in
typedef enum {
    os_up_unqueued,
    os_up_queued,
    os_down_unused,
    os_down_used,
} oneshot_state;

// Custom oneshot mod implementation that doesn't rely on timers. If a mod is
// used while it is held it will be unregistered on keyup as normal, otherwise
// it will be queued and only released after the next non-mod keyup.
void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
);

// To be implemented by the consumer. Defines keys to cancel oneshot mods.
bool is_oneshot_cancel_key(uint16_t keycode);

// To be implemented by the consumer. Defines keys to ignore when determining
// whether a oneshot mod has been used. Setting this to modifiers and layer
// change keys allows stacking multiple oneshot modifiers, and carrying them
// between layers.
bool is_oneshot_ignored_key(uint16_t keycode);

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
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



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_ortho_5x15(
        KC_ESC,               KC_1,         KC_2,    KC_3,    KC_4,    KC_5, KC_MINUS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   G(KC_BSPC), KC_BSPC,
        KC_TAB,               KC_Q,         KC_W,    KC_E,    KC_R,    KC_T, KC_UNDS, KC_PLUS,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  A(KC_BSPC), LT(3, KC_DEL),
        LCTL_T(KC_ESC), KC_A,         KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
        KC_LGUI,        KC_Z,         KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN,   KC_N,    KC_M,    KC_COMM, KC_DOT,  LGUI_T(KC_SLSH), KC_UP, RSFT_T(KC_BSLS),
        OSM(MOD_LSFT), OSM(MOD_LCTL), KC_NO, OSM(MOD_LALT), OS_CMD, LSFT_T(KC_SPC),  KC_DEL, KC_BSPC, LT(1, KC_SPC), OSL(2), KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_L1] = LAYOUT_ortho_5x15(
        C(A(KC_DEL)),        KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,KC_NO, KC_6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TAB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_NO, KC_NO, KC_6,    KC_7,    KC_8,    KC_9,   KC_0, KC_NO, KC_NO,
         KC_CAPS, KC_MINUS, KC_UNDS, KC_EQL, KC_PLUS, KC_LCBR, KC_NO,   KC_NO,   KC_GRV, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_NO, KC_TRNS,
         _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,  KC_RCBR, KC_NO,   KC_NO,   KC_TILDE,   KC_QUOT, KC_DQUO, KC_NO, KC_NO, KC_NO, KC_NO,
         _______, _______, _______, _______, _______,_______, _______,   _______,KC_NO, _______, _______, _______, KC_NO, KC_NO, KC_NO
    ),

    [_L2] = LAYOUT_ortho_5x15(
        C(A(KC_DEL)),        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_DEL,
        KC_NO,  KC_TAB,         KC_NO,         KC_NO,         KC_NO,          KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO,    KC_UP,    KC_NO,   KC_NO, KC_NO, KC_NO,
         KC_NO, OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI),  KC_NO, KC_VOLU,   KC_F15,   KC_BSPC,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL, KC_NO, KC_ENT,
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

/* static uint16_t os_cmd_timer; */

void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
          // Disable mod if it is pressed again
          if (*state == os_up_queued) {
            *state = os_up_unqueued;
            unregister_code(mod);
            return;
          }

            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = os_up_unqueued;
                unregister_code(mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

