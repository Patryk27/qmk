#include QMK_KEYBOARD_H

enum tap_dance_combos {
    TD_VOLD,
    TD_VOLU,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_VOLD] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
    [TD_VOLU] = ACTION_TAP_DANCE_DOUBLE(KC_VOLU, KC_MUTE),
};

enum custom_keycodes {
    CK_VIM = SAFE_RANGE,
    CK_TMUX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        KC_ESC,  KC_NO, KC_NO,  KC_NO,  KC_NO,        KC_NO, KC_NO,
        KC_NO,   KC_Q,  KC_W,   KC_E,   KC_R,         KC_T,  TD(TD_VOLU),
        KC_TAB,  KC_A,  KC_S,   KC_D,   KC_F,         KC_G,
        KC_LSFT, KC_Z,  KC_X,   KC_C,   KC_V,         KC_B,  TD(TD_VOLD),
        KC_BSPC, KC_NO, KC_DEL, KC_ESC, LT(1,KC_SPC),

                 KC_NO,   KC_PGUP,
        KC_NO,   KC_NO,   KC_PGDN,
        KC_LCTL, KC_LALT, TT(1),

        KC_NO,   KC_NO, KC_NO,          KC_UNDS,       KC_NO,  KC_NO,   KC_NO,
        KC_BRIU, KC_Y,  KC_U,           KC_I,          KC_O,   KC_P,    CK_TMUX,
                 KC_H,  KC_J,           KC_K,          KC_L,   KC_SCLN, CK_VIM,
        KC_BRID, KC_N,  KC_M,           KC_COMM,       KC_DOT, KC_SLSH, KC_NO,
                        LT(2,KC_ENTER), LT(3,KC_LGUI), KC_NO,  KC_GRV,  KC_DEL,

        KC_HOME, KC_NO,
        KC_END,  KC_PSCR, KC_NO,
        KC_NO,   KC_RCTL, KC_RALT
    ),

    [1] = LAYOUT_ergodox_80(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,
        KC_NO,   KC_PGUP, KC_HOME, KC_WH_U, KC_NO,   KC_NO, KC_NO,
        KC_NO,   KC_PGDN, KC_END,  KC_WH_D, KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,

                 KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  KC_NO,
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,  KC_TRNS,
                        KC_BTN2, KC_NO,   KC_NO,   KC_NO,  KC_TRNS,

        KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_BTN1
    ),

    [2] = LAYOUT_ergodox_80(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_PLUS, KC_MINS, KC_EQL,  KC_PERC, KC_NO, KC_NO,
        KC_NO, KC_ASTR, KC_BSLS, KC_AMPR, KC_CIRC, KC_NO,
        KC_NO, KC_EXLM, KC_QUES, KC_PIPE, KC_HASH, KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_DLR,

               KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_LCBR, KC_LBRC, KC_RBRC, KC_NO, KC_NO,
               KC_NO, KC_RCBR, KC_LPRN, KC_RPRN, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_QUOT, KC_DQUO, KC_NO,   KC_NO, KC_NO,
                      KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO,

        KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO
    ),

    [3] = LAYOUT_ergodox_80(
        KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,
        KC_NO, KC_1,  KC_2,    KC_3,   KC_NO, KC_NO, KC_NO,
        KC_NO, KC_4,  KC_5,    KC_6,   KC_NO, KC_NO,
        KC_NO, KC_7,  KC_8,    KC_9,   KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_COMM, KC_DOT, KC_0,

               KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_A,  KC_B,  KC_C,  KC_NO,
               KC_NO, KC_NO, KC_D,  KC_E,  KC_F,  KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_TRNS
    )
};

void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if (layer_state > 0) {
        ergodox_right_led_1_on();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_VIM:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) SS_LSFT(";"));
            }
            break;

        case CK_TMUX:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a"));
            }
            break;
    }

    return true;
}
