#include QMK_KEYBOARD_H

#define COMBO_COUNT 7
#define LT_COUNT 3
#define MT_COUNT 5

#include "engine.c"
#include "custom.c"

Combo combos[COMBO_COUNT] = {
    { KC_S, KC_D, KC_UNDS },
    { KC_X, KC_H, KC_PIPE },
    { KC_X, KC_I, KC_GRV },
    { KC_X, KC_J, KC_CIRC },
    { KC_X, KC_K, KC_DLR },
    { KC_X, KC_L, KC_AMPR },
    { KC_X, KC_U, KC_TILD },
};

LayerTap layer_taps[LT_COUNT] = {
    { 2, KC_ENT },
    { 3, KC_MINS },
    { 4, KC_TAB },
};

ModTap mod_taps[MT_COUNT] = {
    { KC_LSFT, KC_SLSH },
    { KC_RSFT, KC_BSLS },
    { KC_LCTL, KC_ESC },
    { KC_LCTL, KC_QUOT },
    { KC_RALT, KC_PSCR },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        TG(1),   KC_1,    KC_2,    KC_3,    KC_4,  KC_5, KC_MAIL,
        LT(2),   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, KC_BRIU,
        MT(2),   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,
        MT(0),   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_BRID,
        KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, LT(0),

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        MO(5),   XXXXXXX, XXXXXXX,

        KC_MUTE, KC_6,  KC_7,   KC_8,    KC_9,    KC_0,       KC_LBRC,
        KC_VOLU, KC_Y,  KC_U,   KC_I,    KC_O,    KC_P,       KC_RBRC,
                 LT(1), KC_H,   KC_J,    KC_K,    KC_L,       MT(3),
        KC_VOLD, KC_N,  KC_M,   KC_COMM, KC_DOT,  S(KC_QUOT), MT(1),
                        KC_SPC, MT(4),   KC_LSFT, KC_LALT,    KC_LCTL,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,  KC_UP,
        KC_LEFT, KC_RIGHT, KC_DOWN
    ),

    [1] = LAYOUT_ergodox_80(
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [2] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, KC_LBRC, KC_RBRC, _______, _______, XXXXXXX,
        XXXXXXX, KC_HASH, KC_LPRN, KC_RPRN, _______, _______,
        XXXXXXX, KC_ASTR, KC_LCBR, KC_RCBR, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  KC_TRNS,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,    XXXXXXX, CK_2CLN, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______,    KC_PERC, KC_EXLM, KC_QUES, _______, KC_DEL,
                 _______,    KC_PPLS, KC_PMNS, KC_PAST, KC_SCLN, KC_BSPC,
        XXXXXXX, S(KC_SCLN), KC_PSLS, KC_LT,   KC_GT,   _______, XXXXXXX,
                             KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [3] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, KC_PGUP, _______, _______, _______, XXXXXXX,
        XXXXXXX, KC_HOME, KC_PGDN, KC_END,  _______, _______,
        XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
                 KC_TRNS, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [4] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______,
        XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, CK_FROWN, CK_SMILE, _______, _______, XXXXXXX,
                 _______, CK_XD,    CK_HEART, _______, _______, XXXXXXX,
        XXXXXXX, _______, _______,  _______,  _______, _______, XXXXXXX,
                          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [5] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_WH_U,
        XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_WH_D, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
                          KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_BTN3
    ),
};
