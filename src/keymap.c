#include QMK_KEYBOARD_H

#define COMBO_COUNT 0
#define LT_COUNT 4
#define MT_COUNT 7

#include "engine.c"
#include "custom.c"

Combo combos[COMBO_COUNT] = {
    //
};

LayerTap layer_taps[LT_COUNT] = {
    { 2, KC_MINS },
    { 3, S(KC_MINS) },
    { 4, KC_SLSH },
    { 5, XXXXXXX },
};

ModTap mod_taps[MT_COUNT] = {
    { KC_LSFT, KC_ESC },
    { KC_RSFT, KC_ENTER },
    { KC_LCTL, KC_TAB },
    { KC_RCTL, XXXXXXX },
    { KC_RALT, KC_RALT },
    { KC_LALT, KC_PSCR },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        KC_DEL,  KC_EXLM, KC_QUES, KC_HASH, KC_DLR, KC_PERC, KC_AT,
        MT(2),   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_HOME,
        MT(0),   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
        LT(2),   KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_END,
        KC_LSFT, KC_LALT, KC_LCTL, MT(5),   LT(1),

                KC_BRID, KC_BRIU,
        OSL(6), XXXXXXX, XXXXXXX,
        KC_SPC, KC_LGUI, TG(5),

        XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MT(3),
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, MT(1),
        KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_GRV,  KC_BSLS,
                          LT(0),   MT(4),   KC_RCTL, KC_LALT, KC_RSFT,

        KC_VOLD, KC_VOLU,
        XXXXXXX, TG(1),   OSL(6),
        TG(5),   KC_LGUI, KC_SPC
    ),

    [1] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, RESET,
        XXXXXXX, KC_TRNS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

        RESET,   XXXXXXX,
        XXXXXXX, KC_TRNS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [2] = LAYOUT_ergodox_80(
        XXXXXXX,   S(KC_SCLN), KC_PEQL, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX,
        CK_ARROW2, KC_1,       KC_2,    KC_3,   KC_PPLS, XXXXXXX, XXXXXXX,
        CK_ARROW,  KC_4,       KC_5,    KC_6,   KC_PMNS, XXXXXXX,
        XXXXXXX,   KC_7,       KC_8,    KC_9,   KC_PAST, KC_PSLS, XXXXXXX,
        XXXXXXX,   XXXXXXX,    XXXXXXX, KC_DOT, KC_0,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SPC,  XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, G(KC_Y), G(KC_U), G(KC_I), G(KC_O), G(KC_P), XXXXXXX,
                 G(KC_H), G(KC_J), G(KC_K), G(KC_L), XXXXXXX, XXXXXXX,
        XXXXXXX, G(KC_N), G(KC_M), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [3] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), G(KC_T), XXXXXXX,
        XXXXXXX, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),
        XXXXXXX, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, S(KC_SCLN), KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_CIRC,    KC_DLR,  KC_ASTR, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_PIPE,    KC_AMPR, XXXXXXX, XXXXXXX, XXXXXXX,
                          KC_SCLN,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [4] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LSFT, KC_LALT, XXXXXXX, XXXXXXX,
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, XXXXXXX,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [5] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LSFT, KC_LALT, KC_ACL1, KC_ACL0,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ACL2, XXXXXXX, KC_TRNS,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
                          KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, XXXXXXX, KC_BTN1
    ),

    [6] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,
        XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        XXXXXXX, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, XXXXXXX,
        KC_TRNS, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_TRNS,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

void matrix_scan_user(void) {
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    if (biton32(layer_state) == 5) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }

    if (biton32(layer_state) == 1) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
}
