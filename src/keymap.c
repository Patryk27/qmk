#include QMK_KEYBOARD_H

#define COMBO_COUNT 26
#define LT_COUNT 2
#define MT_COUNT 6

#include "engine.c"
#include "custom.c"

Combo combos[COMBO_COUNT] = {
    { KC_1, KC_H, KC_MS_L },
    { KC_1, KC_I, KC_WH_U },
    { KC_1, KC_J, KC_MS_D },
    { KC_1, KC_K, KC_MS_U },
    { KC_1, KC_L, KC_MS_R },
    { KC_1, KC_N, KC_WH_D },
    { KC_1, KC_SPC, KC_BTN1 },
    { KC_COMM, KC_A, KC_LEFT },
    { KC_COMM, KC_D, KC_RIGHT },
    { KC_COMM, KC_S, KC_DOWN },
    { KC_COMM, KC_W, KC_UP },
    { KC_DOT, KC_A, KC_PGUP },
    { KC_DOT, KC_D, KC_PGDN },
    { KC_DOT, KC_S, KC_END },
    { KC_DOT, KC_W, KC_HOME },
    { KC_Q, KC_J, KC_BSPC },
    { KC_Q, KC_K, KC_DEL },
    { KC_QUOT, KC_S, A(KC_DOWN) },
    { KC_QUOT, KC_W, A(KC_UP) },
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
    { 3, KC_TAB },
};

ModTap mod_taps[MT_COUNT] = {
    { KC_LSFT, KC_SLSH },
    { KC_RSFT, KC_BSLS },
    { KC_LCTL, KC_ESC },
    { KC_RALT, KC_PSCR },
    { KC_LALT, KC_LGUI },
    { KC_LCTL, KC_AT },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        TG(4),   KC_1,  KC_2,    KC_3,  KC_4,  KC_5, KC_MAIL,
        LT(1),   KC_Q,  KC_W,    KC_E,  KC_R,  KC_T, KC_BRIU,
        MT(2),   KC_A,  KC_S,    KC_D,  KC_F,  KC_G,
        MT(0),   KC_Z,  KC_X,    KC_C,  KC_V,  KC_B, KC_BRID,
        XXXXXXX, KC_UP, KC_DOWN, MT(4), LT(0),

                    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,
        C(KC_LALT), C(KC_LSFT), XXXXXXX,

        KC_MUTE, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,       KC_LBRC,
        KC_VOLU, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,       KC_RBRC,
                 KC_QUOT, KC_H,   KC_J,    KC_K,    KC_L,       MT(5),
        KC_VOLD, KC_N,    KC_M,   KC_COMM, KC_DOT,  S(KC_QUOT), MT(1),
                          KC_SPC, MT(3),   KC_LEFT, KC_RIGHT,   TG(1),

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, OSM(MOD_LSFT),
        XXXXXXX, XXXXXXX, A(C(KC_LSFT))
    ),

    [1] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [2] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_HASH, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_ASTR, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  KC_TRNS,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,    XXXXXXX, CK_2CLN, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,    KC_PERC, KC_EXLM, KC_QUES, XXXXXXX, XXXXXXX,
                 XXXXXXX,    KC_PPLS, KC_PMNS, KC_PAST, KC_SCLN, XXXXXXX,
        XXXXXXX, S(KC_SCLN), KC_PSLS, KC_LT,   KC_GT,   XXXXXXX, XXXXXXX,
                             KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [3] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______,
        XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        XXXXXXX, _______, _______,  _______,  _______, _______,  XXXXXXX,
                 _______, CK_SMILE, CK_FROWN, CK_XD,   CK_HEART, XXXXXXX,
        XXXXXXX, _______, _______,  _______,  _______, _______,  XXXXXXX,
                          XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [4] = LAYOUT_ergodox_80(
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_WH_U,
        KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_WH_D, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, KC_LCTRL,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

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

void matrix_scan_user(void) {
    if (biton32(layer_state) == 1) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }

    if (biton32(layer_state) == 4) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }
}
