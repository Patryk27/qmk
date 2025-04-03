#include QMK_KEYBOARD_H

#define LTA LT(2, KC_SCLN)
#define LTB LT(3, KC_MINS)
#define LTC LT(4, KC_SLSH)
#define LTD LT(5, XXXXXXX)

#define MTA MT(MOD_LSFT, KC_ESC)
#define MTB MT(MOD_RSFT, KC_ENTER)
#define MTC MT(MOD_LCTL, KC_TAB)
#define MTD MT(MOD_RCTL, XXXXXXX)
#define MTE MT(MOD_RALT, KC_RALT)
#define MTF MT(MOD_LALT, KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        KC_DEL,  KC_EXLM, KC_PEQL, KC_QUES, KC_DLR, KC_PERC, KC_AT,
        MTC,     KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_HOME,
        MTA,     KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
        LTC,     KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_END,
        KC_LSFT, KC_LALT, KC_LCTL, MTF,     LTB,

                KC_BRID, KC_BRIU,
        OSL(6), KC_PSCR, XXXXXXX,
        KC_SPC, KC_LGUI, TG(5),

        XXXXXXX, XXXXXXX, KC_TILD, KC_LPRN, KC_RPRN, XXXXXXX,    KC_BSPC,
        KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       MTD,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,    MTB,
        KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  S(KC_QUOT), KC_BSLS,
                          LTA,     MTE,     KC_RCTL, KC_LALT,    KC_RSFT,

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

                 XXXXXXX, XXXXXXX,
        XXXXXXX, KC_TRNS, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

        XXXXXXX, XXXXXXX,
        QK_BOOT, KC_TRNS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [2] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, KC_PEQL, S(KC_SCLN), XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_1,    KC_2,    KC_3,       KC_PPLS, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_4,    KC_5,    KC_6,       KC_PMNS, KC_PERC,
        XXXXXXX, KC_7,    KC_8,    KC_9,       KC_PAST, KC_PSLS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,     KC_0,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SPC,  XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, C(KC_Y), C(KC_U), C(KC_I), C(KC_O), C(KC_P), XXXXXXX,
                 C(KC_H), C(KC_J), C(KC_K), C(KC_L), XXXXXXX, XXXXXXX,
        XXXXXXX, C(KC_N), C(KC_M), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [3] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, C(KC_Q), C(KC_W), C(KC_E), C(KC_R), C(KC_T), XXXXXXX,
        XXXXXXX, C(KC_A), C(KC_S), C(KC_D), C(KC_F), C(KC_G),
        XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B), XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, KC_HASH, KC_ASTR, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_AMPR, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX,
                 XXXXXXX, KC_CIRC, KC_DLR,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
                          KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

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
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
