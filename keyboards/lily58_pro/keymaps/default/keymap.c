// Copyright 2024 zeotyn
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------|
 * | LSFT |   Z  |   X  |   C  |   V  |   B  |  [   |    |  ]   |   N  |   M  |   ,  |   .  |   /  | RSFT |
 * `-----------------------------------------------------'    '-----------------------------------------------------'
 *                        |LOWER | LGUI | LALT |  SPC |    | ENT  | BSPC | RGUI |RAISE |
 *                        `----------------------------'    '----------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               MO(_LOWER), KC_LGUI, KC_LALT, KC_SPC, KC_ENT, KC_BSPC, KC_RGUI, MO(_RAISE)
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   {  |   }  |   (  |   )  |   |  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   0  |                    |   [  |   ]  |   <  |   >  |   \  |  `   |
 * |------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |    |      |   -  |   =  |   +  |   *  |   /  |  ~   |
 * `-----------------------------------------------------'    '-----------------------------------------------------'
 *                        |      | LGUI | ENT  |  SPC |    | ENT  |  SPC | RGUI |      |
 *                        `----------------------------'    '----------------------------'
 */
[_LOWER] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, KC_BSPC,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   KC_BSLS, KC_GRV,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_MINS, KC_EQL,  KC_PLUS, KC_ASTR, KC_SLSH, KC_TILD,
                                _______, KC_LGUI, KC_ENT,  KC_SPC,  KC_ENT,  KC_SPC,  KC_RGUI, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | HOME |      | END  |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   ←  |   ↓  |   ↑  |   →  |      |      |
 * |------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |    |      | PGUP |      | PGDN |      |      |      |
 * `-----------------------------------------------------'    '-----------------------------------------------------'
 *                        |      | LGUI | ENT  |  SPC |    | ENT  |  SPC | RGUI |      |
 *                        `----------------------------'    '----------------------------'
 */
[_RAISE] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX, KC_F12,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, _______,
                                _______, KC_LGUI, KC_ENT,  KC_SPC,  KC_ENT,  KC_SPC,  KC_RGUI, _______
),

/* ADJUST (LOWER + RAISE)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QK_BOOT|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG|RGB_HUI|RGB_SAI|RGB_VAI|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_MOD|RGB_HUD|RGB_SAD|RGB_VAD|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------.    ,------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |    |      |      |      |      |      |      |      |
 * `-----------------------------------------------------'    '-----------------------------------------------------'
 *                        |      |      |      |      |    |      |      |      |      |
 *                        `----------------------------'    '----------------------------'
 */
[_ADJUST] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                _______, _______, _______, _______, _______, _______, _______, _______
),

};
