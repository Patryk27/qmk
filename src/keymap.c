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
    _CK = SAFE_RANGE,

    LT_1,
    LT_2,

    CK_VIM,
    CK_TMUX,
    CK_SMILE,
    CK_XD,
    CK_SAD,
    CK_FROWN,
    CK_RARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        KC_GRV,  KC_BSPC, KC_SLSH, KC_BSLS, CK_RARROW, KC_NO, KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,  KC_BRIU,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,  KC_BRID,
        KC_LCTL, KC_NO,   KC_NO,   MO(3),   LT_1,

                 CK_SMILE, KC_NO,
        KC_NO,   CK_XD,    KC_NO,
        KC_LALT, KC_LCTL,  KC_NO,

        KC_NO,       KC_NO, KC_NO, KC_UNDS, KC_MINS, KC_DEL,  RESET,
        TD(TD_VOLU), KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    CK_TMUX,
                     KC_H,  KC_J,  KC_K,    KC_L,    KC_QUOT, CK_VIM,
        TD(TD_VOLD), KC_N,  KC_M,  KC_LBRC, KC_RBRC, KC_NO,   KC_NO,
                            LT_2,  KC_RALT, KC_NO,   KC_NO,   KC_RCTL,

        KC_NO, CK_SAD,
        KC_NO, CK_FROWN,   KC_PSCR,
        KC_NO, S(KC_LCTL), KC_LGUI
    ),

    [1] = LAYOUT_ergodox_80(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_NO,
        KC_NO,   KC_COMM, KC_DOT,  KC_SCLN, S(KC_SCLN), KC_NO, KC_NO,
        KC_NO,   KC_LT,   KC_LPRN, KC_LCBR, KC_NO,      KC_NO,
        KC_TRNS, KC_GT,   KC_RPRN, KC_RCBR, KC_NO,      KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,

               KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_1,  KC_2,  KC_3,  KC_COMM, KC_NO,
               KC_NO, KC_4,  KC_5,  KC_6,  KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_7,  KC_8,  KC_9,  KC_NO,   KC_NO,
                      KC_0,  KC_NO, KC_NO, KC_NO,   KC_NO,

        KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO
    ),

    [2] = LAYOUT_ergodox_80(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_PERC, KC_EQL,  KC_PLUS, KC_ASTR, KC_NO, KC_NO,
        KC_NO, KC_DLR,  KC_QUES, KC_EXLM, KC_HASH, KC_NO,
        KC_NO, KC_CIRC, KC_AMPR, KC_PIPE, KC_AT,   KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,

               KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
               KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO
    ),

    [3] = LAYOUT_ergodox_80(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5, KC_F6,
        KC_NO,   KC_PGUP, KC_HOME, KC_WH_U, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_PGDN, KC_END,  KC_WH_D, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
        KC_LCTL, KC_NO,   KC_NO,   KC_TRNS, KC_NO,

               KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,

        KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  KC_NO,
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,  KC_NO,
                        KC_BTN2, KC_NO,   KC_NO,   KC_NO,  KC_NO,

        KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,
        KC_NO, KC_BTN3, KC_BTN1
    ),
};

bool lt1_interrupted = false;
bool lt2_interrupted = false;

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
        case LT_1:
            if (record->event.pressed) {
                lt1_interrupted = false;
                layer_on(1);
            } else {
                if (!lt1_interrupted) {
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
                layer_off(1);
            }
            return false;

        case LT_2:
            if (record->event.pressed) {
                lt2_interrupted = false;
                layer_on(2);
            } else {
                if (!lt2_interrupted) {
                    register_code(KC_ENT);
                    unregister_code(KC_ENT);
                }
                layer_off(2);
            }
            return false;

        case CK_VIM:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) SS_LSFT(";"));
            }
            return false;

        case CK_TMUX:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a"));
            }
            return false;

        case CK_SMILE:
            if (record->event.pressed) {
                SEND_STRING(":-)");
            }
            return false;

        case CK_XD:
            if (record->event.pressed) {
                SEND_STRING("xD");
            }
            return false;

        case CK_SAD:
            if (record->event.pressed) {
                SEND_STRING(":-(");
            }
            return false;

        case CK_FROWN:
            if (record->event.pressed) {
                SEND_STRING(":-//");
            }
            return false;

        case CK_RARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;

        default:
            if (record->event.pressed) {
                lt1_interrupted = true;
                lt2_interrupted = true;
            }
    }

    return true;
}
