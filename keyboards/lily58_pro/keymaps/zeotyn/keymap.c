// Copyright 2024 zeotyn
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

#ifdef OLED_ENABLE
#    include "layers_img.h"
#    include "spaceship.h"
#endif

// ---------------------------------------------------------------------------
// Combos (Umlaute via RAlt + Buchstabe)
// ---------------------------------------------------------------------------
enum combos { UML_A, UML_U, UML_O };

const uint16_t PROGMEM uml_a_combo[] = {KC_RALT, KC_A, COMBO_END};
const uint16_t PROGMEM uml_u_combo[] = {KC_RALT, KC_U, COMBO_END};
const uint16_t PROGMEM uml_o_combo[] = {KC_RALT, KC_O, COMBO_END};

__attribute__((weak)) combo_t key_combos[VIAL_COMBO_ENTRIES] = {
    [UML_A] = COMBO(uml_a_combo, DE_ADIA),
    [UML_U] = COMBO(uml_u_combo, DE_UDIA),
    [UML_O] = COMBO(uml_o_combo, DE_ODIA),
};

// ---------------------------------------------------------------------------
// Layer-Definitionen
// ---------------------------------------------------------------------------
enum layers { _COLEMAK = 0, _QWERTY, _LOWER, _RAISE, _ADJUST };

enum custom_keycodes { KC_COLEMAK = QK_KB_0, KC_QWERTY };

/* ┌─────────────────────────────────────────────────────────────────────────┐
 * │  Lily58 LAYOUT — 58 Tasten                                              │
 * │                                                                         │
 * │  Zeile 0 (12): k00  k01  k02  k03  k04  k05  k06  k07  k08  k09  k0a  k0b │
 * │  Zeile 1 (12): k10  k11  k12  k13  k14  k15  k16  k17  k18  k19  k1a  k1b │
 * │  Zeile 2 (12): k20  k21  k22  k23  k24  k25  k26  k27  k28  k29  k2a  k2b │
 * │  Zeile 3 (14): k30  k31  k32  k33  k34  k35 [k36  k37] k38  k39  k3a  k3b  k3c  k3d │
 * │  Daumen (8):        k40  k41  k42  k43       k44  k45  k46  k47         │
 * └─────────────────────────────────────────────────────────────────────────┘ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ┌──────────────────────────────────────────────────────────────────────────────┐
 * │  COLEMAK DH — Layer 0                                                        │
 * ├──────┬──────┬──────┬──────┬──────┬──────┐          ┌──────┬──────┬──────┬──────┬──────┬──────┤
 * │ ESC  │  1   │  2   │  3   │  4   │  5   │          │  6   │  7   │  8   │  9   │  0   │ BSPC │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ TAB  │  Q   │  W   │  F   │  P   │  B   │          │  J   │  L   │  U   │  Y   │  ;   │ DEL  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ LCTL │SFT(A)│ALT(R)│GUI(S)│CTL(T)│  G   │          │  M   │CTL(N)│GUI(E)│ALT(I)│SFT(O)│  '   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ LSFT │  Z   │  X   │  C   │  D   │  V   │  [   │  │  ]   │  K   │  H   │  ,   │  .   │  /   │ RSFT │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┘  └──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │ LOWR │ LGUI │ LALT │  SPC │  │ ENT  │ BSPC │ RGUI │ RISE │
 *                      └──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┘
 */
[_COLEMAK] = LAYOUT(
    KC_ESC,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                         KC_6,    KC_7,         KC_8,         KC_9,         KC_0,         KC_BSPC,
    KC_TAB,  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_DEL,
    KC_LCTL, SFT_T(KC_A),  ALT_T(KC_R),  GUI_T(KC_S),  CTL_T(KC_T),  KC_G,                         KC_M,    CTL_T(KC_N),  GUI_T(KC_E),  ALT_T(KC_I),  SFT_T(KC_O),  KC_QUOT,
    KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,    KC_LBRC,   KC_RBRC,  KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,
                                         TL_LOWR,      KC_LGUI,      KC_LALT, KC_SPC,    KC_ENT,   KC_BSPC, KC_RGUI,      TL_UPPR
),

/* ┌──────────────────────────────────────────────────────────────────────────────┐
 * │  QWERTY — Layer 1  (via KC_QWERTY persistenter Wechsel)                     │
 * └──────────────────────────────────────────────────────────────────────────────┘ */
[_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               TL_LOWR, KC_LGUI, KC_LALT, KC_SPC,  KC_ENT,  KC_BSPC, KC_RGUI, TL_UPPR
),

/* ┌──────────────────────────────────────────────────────────────────────────────┐
 * │  LOWER — Layer 2  (Zahlen / Symbole)                                        │
 * ├──────┬──────┬──────┬──────┬──────┬──────┐          ┌──────┬──────┬──────┬──────┬──────┬──────┤
 * │ ESC  │      │      │      │      │      │          │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  1   │  2   │  3   │  4   │  5   │          │  {   │  }   │  (   │  )   │  |   │ BSPC │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  6   │  7   │  8   │  9   │  0   │          │  [   │  ]   │  <   │  >   │  \   │  `   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │  -   │  =   │  +   │  *   │  /   │  ~   │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┘  └──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │ LGUI │ ENT  │  SPC │  │ ENT  │  SPC │ RGUI │      │
 *                      └──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┘
 */
[_LOWER] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PIPE, KC_BSPC,
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   KC_BSLS, KC_GRV,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_MINS, KC_EQL,  KC_PLUS, KC_ASTR, KC_SLSH, KC_TILD,
                               _______, KC_LGUI, KC_ENT,  KC_SPC,  KC_ENT,  KC_SPC,  KC_RGUI, _______
),

/* ┌──────────────────────────────────────────────────────────────────────────────┐
 * │  RAISE — Layer 3  (F-Tasten / Navigation)                                   │
 * ├──────┬──────┬──────┬──────┬──────┬──────┐          ┌──────┬──────┬──────┬──────┬──────┬──────┤
 * │ ESC  │  F1  │  F2  │  F3  │  F4  │  F5  │          │  F6  │  F7  │  F8  │  F9  │ F10  │ F11  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │          │ HOME │      │ END  │      │      │ F12  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤          ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │          │  ←   │  ↓   │  ↑   │  →   │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │ PGUP │      │ PGDN │      │      │      │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┘  └──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │ LGUI │ ENT  │  SPC │  │ ENT  │  SPC │ RGUI │      │
 *                      └──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┘
 */
[_RAISE] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX, KC_F12,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, _______,
                               _______, KC_LGUI, KC_ENT,  KC_SPC,  KC_ENT,  KC_SPC,  KC_RGUI, _______
),

/* ┌──────────────────────────────────────────────────────────────────────────────┐
 * │  ADJUST — Layer 4  (LOWER + RAISE gleichzeitig)                             │
 * │  QK_BOOT | RGB | Layer-Wechsel Colemak↔QWERTY                              │
 * └──────────────────────────────────────────────────────────────────────────────┘ */
[_ADJUST] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QWERTY, KC_COLEMAK,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______, _______
),

};

// ---------------------------------------------------------------------------
// Custom Keycodes (persistenter Layer-Wechsel)
// ---------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COLEMAK:
            if (record->event.pressed) set_single_persistent_default_layer(_COLEMAK);
            return false;
        case KC_QWERTY:
            if (record->event.pressed) set_single_persistent_default_layer(_QWERTY);
            return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// OLED
// ---------------------------------------------------------------------------
#ifdef OLED_ENABLE
#    include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;  // Slave-Display: Hochformat für Layer-Bild
    }
    return OLED_ROTATION_0;        // Master-Display: Querformat für Spaceship
}

// Slave-Seite: Layer-Bild (32×128px, rotiert)
void oled_render_layer_state(void) {
    layer_state_t state = layer_state;

    if (layer_state_cmp(state, _ADJUST)) {
        oled_write_raw_P(adjust_img, adjust_img_size);
    } else if (layer_state_cmp(state, _RAISE)) {
        oled_write_raw_P(raise_img, raise_img_size);
    } else if (layer_state_cmp(state, _LOWER)) {
        oled_write_raw_P(lower_img, lower_img_size);
    } else if (layer_state_cmp(state, _QWERTY)) {
        oled_write_raw_P(extra_img, extra_img_size);
    } else {
        oled_write_raw_P(qwerty_img, qwerty_img_size);  // Colemak → "qwerty_img" als Base-Bild
    }
}

// Master-Seite: Spaceship-Animation (WPM-basiert)
static unsigned int spaceship_state = 0;

static void render_spaceship(void) {
    uint8_t wpm = get_current_wpm();
    char    render_row[128];
    int     i;

    // Zeile 1
    oled_set_cursor(0, 0);
    for (i = 0; i < wpm / 4; i++) {
        render_row[i] = pgm_read_byte(space_row_1 + i + spaceship_state);
    }
    for (i = wpm / 4; i < 128; i++) {
        render_row[i] = (pgm_read_byte(space_row_1 + i + spaceship_state) &
                         pgm_read_byte(mask_row_1 + i - wpm / 4)) |
                        pgm_read_byte(ship_row_1 + i - wpm / 4);
    }
    oled_write_raw(render_row, 128);

    // Zeile 2
    oled_set_cursor(0, 1);
    for (i = 0; i < wpm / 4; i++) {
        render_row[i] = pgm_read_byte(space_row_2 + i + spaceship_state);
    }
    for (i = wpm / 4; i < 128; i++) {
        render_row[i] = (pgm_read_byte(space_row_2 + i + spaceship_state) &
                         pgm_read_byte(mask_row_2 + i - wpm / 4)) |
                        pgm_read_byte(ship_row_2 + i - wpm / 4);
    }
    oled_write_raw(render_row, 128);

    // Zeile 3
    oled_set_cursor(0, 2);
    for (i = 0; i < wpm / 4; i++) {
        render_row[i] = pgm_read_byte(space_row_3 + i + spaceship_state);
    }
    for (i = wpm / 4; i < 128; i++) {
        render_row[i] = (pgm_read_byte(space_row_3 + i + spaceship_state) &
                         pgm_read_byte(mask_row_3 + i - wpm / 4)) |
                        pgm_read_byte(ship_row_3 + i - wpm / 4);
    }
    oled_write_raw(render_row, 128);

    // Zeile 4
    oled_set_cursor(0, 3);
    for (i = 0; i < wpm / 4; i++) {
        render_row[i] = pgm_read_byte(space_row_4 + i + spaceship_state);
    }
    for (i = wpm / 4; i < 128; i++) {
        render_row[i] = (pgm_read_byte(space_row_4 + i + spaceship_state) &
                         pgm_read_byte(mask_row_4 + i - wpm / 4)) |
                        pgm_read_byte(ship_row_4 + i - wpm / 4);
    }
    oled_write_raw(render_row, 128);

    spaceship_state = (spaceship_state + 1 + (wpm / 15)) % (128 * 2);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_spaceship();
    } else {
        oled_render_layer_state();
    }
    return false;
}

#endif // OLED_ENABLE
