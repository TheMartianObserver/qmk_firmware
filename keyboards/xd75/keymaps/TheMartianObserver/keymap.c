/* Copyright 2017 Wunder
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

enum layer_names {
    _QW,
    _L1,
    _L2,
    _L3,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_ortho_5x15(
        KC_GRV,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_UNDS, KC_PLUS,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_DEL,  KC_BSPC,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_MINUS, KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_LBRC, KC_RBRC,
        LCTL_T(KC_ESC),   LCTL_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    LSFT_T(KC_F),    KC_G,    KC_HOME, KC_PGUP,   KC_H,    RSFT_T(KC_J),    RGUI_T(KC_K),    RALT_T(KC_L),   RCTL_T(KC_SCLN),          KC_QUOT, KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN,   KC_N,    KC_M,    KC_COMM, KC_DOT,  LGUI_T(KC_SLSH), KC_UP, RSFT_T(KC_BSLS),
        OSM(MOD_HYPR), OSM(MOD_MEH), KC_LCTL, KC_LALT, KC_LGUI,  LSFT_T(KC_SPC),  KC_DEL, LT(2, KC_BSPC), LT(1, KC_SPC), OSM(MOD_RGUI), OSM(MOD_RALT), OSM(MOD_RCTL), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_L1] = LAYOUT_ortho_5x15(
        RESET,        KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,KC_NO, KC_6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        C(A(KC_DEL)), KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_NO, KC_NO, KC_6,    KC_7,    KC_8,    KC_9,   KC_0, KC_NO, KC_NO,
         KC_CAPS, KC_MINUS, KC_UNDS, KC_EQL, KC_PLUS, KC_NO, KC_NO,   KC_NO,   KC_NO,   OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL),   KC_NO,KC_NO,
         KC_NO, KC_LBRC, KC_RBRC, KC_LCBR,  KC_RCBR, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO, KC_NO,   KC_NO,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_L2] = LAYOUT_ortho_5x15(
        KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_UP,    KC_NO,   KC_NO, KC_NO, KC_NO,
         KC_NO, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,   KC_NO,KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO, KC_NO,   KC_NO,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
};
