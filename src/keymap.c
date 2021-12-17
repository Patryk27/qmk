#include QMK_KEYBOARD_H

#define COMBO_COUNT 4
#define LT_COUNT 4
#define MT_COUNT 6

#include "engine.c"
#include "custom.c"

Combo combos[COMBO_COUNT] = {
    { KC_X, KC_H, KC_AMPR },
    { KC_X, KC_J, KC_CIRC },
    { KC_X, KC_K, KC_DLR },
    { KC_X, KC_L, KC_PIPE },
};

LayerTap layer_taps[LT_COUNT] = {
    { 2, KC_ENT },
    { 3, KC_SLSH },
    { 4, XXXXXXX },
    { 5, XXXXXXX },
};

ModTap mod_taps[MT_COUNT] = {
    { KC_LSFT, KC_ESC },
    { KC_RSFT, KC_GRV },
    { KC_LCTL, KC_TAB },
    { KC_RCTL, CK_EMACS },
    { KC_LALT, KC_LGUI },
    { KC_RALT, KC_PSCR },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        KC_DEL,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5, XXXXXXX,
        MT(2),   KC_Q,    KC_W,    KC_E,  KC_R,  KC_T, KC_HOME,
        MT(0),   KC_A,    KC_S,    KC_D,  KC_F,  KC_G,
        LT(1),   KC_Z,    KC_X,    KC_C,  KC_V,  KC_B, KC_END,
        KC_CAPS, XXXXXXX, XXXXXXX, MT(5), LT(0),

                       XXXXXXX,    KC_MAIL,
        C(S(KC_LALT)), C(KC_LALT), KC_BRIU,
        TG(4),         C(KC_LSFT), KC_BRID,

        XXXXXXX, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,       KC_BSPC,
        KC_PGUP, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,       MT(3),
                 KC_QUOT, KC_H,   KC_J,    KC_K,    KC_L,       MT(1),
        KC_PGDN, KC_N,    KC_M,   KC_COMM, KC_DOT,  S(KC_QUOT), KC_BSLS,
                          KC_SPC, MT(4),   XXXXXXX, XXXXXXX,    TG(1),

        KC_MUTE, XXXXXXX,
        KC_VOLU, C(KC_LALT), C(S(KC_LALT)),
        KC_VOLD, C(KC_LSFT), LT(3)
    ),

    [1] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, RESET,   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

        XXXXXXX, XXXXXXX,
        XXXXXXX, RESET,   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [2] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_HASH, KC_LCBR, KC_RCBR, KC_UNDS, XXXXXXX,
        XXXXXXX, KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,    XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,    KC_EXLM, KC_SCLN, KC_QUES, KC_PERC, XXXXXXX,
                 XXXXXXX,    KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, XXXXXXX,
        XXXXXXX, S(KC_SCLN), XXXXXXX, KC_LT,   KC_GT,   XXXXXXX, XXXXXXX,
                             KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [3] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, _______, KC_LSFT, KC_LALT, _______, _______,
        KC_TRNS, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [4] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL2, KC_ACL1,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, KC_BTN3, XXXXXXX,
                 XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
        XXXXXXX, KC_WH_D, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
                          KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_TRNS
    ),

    [5] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,
        XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        XXXXXXX, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_TRNS
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

    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
}
