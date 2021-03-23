#include QMK_KEYBOARD_H

void process_td_scln(qk_tap_dance_state_t *state, void *user_data);
bool process_record_user_lt(uint16_t keycode, keyrecord_t *record);
bool process_record_user_ck(uint16_t keycode, keyrecord_t *record);

enum tap_dance_combos {
    TD_VOLD,
    TD_VOLU,
    TD_SCLN,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_VOLD] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
    [TD_VOLU] = ACTION_TAP_DANCE_DOUBLE(KC_VOLU, KC_MUTE),
};

enum custom_keycodes {
    _CK = SAFE_RANGE,

    LT_1,
    LT_2,
    LT_3,

    CK_VIM,
    CK_VIM_SL,

    CK_SMILE,
    CK_XD,
    CK_SAD,
    CK_FROWN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        KC_MAIL, C(KC_TAB), KC_BSPC, KC_UNDS, KC_NO, KC_NO, KC_NO,
        KC_TAB,  KC_Q,      KC_W,    KC_E,    KC_R,  KC_T,  KC_BRIU,
        KC_ESC,  KC_A,      KC_S,    KC_D,    KC_F,  KC_G,
        KC_LSFT, KC_Z,      KC_X,    KC_C,    KC_V,  KC_B,  KC_BRID,
        KC_LCTL, KC_NO,     KC_NO,   LT_2,    LT_1,

                   KC_NO,   KC_NO,
        CK_VIM_SL, KC_NO,   KC_NO,
        KC_LALT,   KC_LCTL, KC_NO,

        KC_NO,       KC_NO, KC_NO, KC_MINS, KC_DEL,  KC_NO,   RESET,
        TD(TD_VOLU), KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_NO,
                     KC_H,  KC_J,  KC_K,    KC_L,    KC_QUOT, CK_VIM,
        TD(TD_VOLD), KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SCLN, KC_NO,
                            LT_3,  KC_RALT, KC_NO,   KC_NO,   KC_NO,

        CK_SAD,   CK_SMILE,
        CK_FROWN, CK_XD,      KC_DEL,
        KC_PSCR,  S(KC_LCTL), KC_LGUI
    ),

    [1] = LAYOUT_ergodox_80(
        KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_SLSH,   KC_LPRN, KC_RPRN, KC_A,    KC_B,  KC_NO,
        KC_NO, KC_BSLS,   KC_LCBR, KC_RCBR, KC_C,    KC_D,
        KC_NO, S(KC_GRV), KC_NO,   KC_NO,   KC_E,    KC_F,  KC_NO,
        KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_TRNS,

               KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO,       KC_LT, KC_EQL, KC_GT, KC_EXLM,        KC_NO,
        KC_NO, KC_KP_PLUS,  KC_1,  KC_2,   KC_3,  KC_KP_ASTERISK, KC_NO,
               KC_KP_MINUS, KC_4,  KC_5,   KC_6,  KC_KP_SLASH,    KC_NO,
        KC_NO, KC_SPC,      KC_7,  KC_8,   KC_9,  KC_COMM,        KC_NO,
                            KC_0,  KC_DOT, KC_NO, KC_NO,          KC_NO,

        KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO
    ),

    [2] = LAYOUT_ergodox_80(
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

    [3] = LAYOUT_ergodox_80(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_PERC, KC_EXLM, KC_QUES, KC_CIRC, KC_NO, KC_NO,
        KC_NO, KC_HASH, KC_AMPR, KC_PIPE, KC_NO,   KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,

               KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_AT,   KC_LBRC, KC_RBRC, KC_NO, KC_NO,
               KC_NO, KC_NO,   KC_DLR,  KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
                      KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO,

        KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_user_lt(keycode, record)
        && process_record_user_ck(keycode, record);
}

bool process_record_user_lt(uint16_t keycode, keyrecord_t *record) {
    static bool lt_interrupted = false;

    uint8_t layer = 0;
    uint8_t alt_keycode;

    switch (keycode) {
        case LT_1:
            layer = 1;
            alt_keycode = KC_SPC;
            break;

        case LT_2:
            layer = 2;
            alt_keycode = KC_GRV;
            break;

        case LT_3:
            layer = 3;
            alt_keycode = KC_ENT;
            break;

        default:
            if (record->event.pressed) {
                lt_interrupted = true;
            }
            return true;
    }

    if (record->event.pressed) {
        lt_interrupted = false;
        layer_on(layer);
    } else {
        if (!lt_interrupted) {
            tap_code(alt_keycode);
        }

        layer_off(layer);
    }

    return false;
}

bool process_record_user_ck(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_VIM:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) SS_LSFT(";"));
            }
            return false;

        case CK_VIM_SL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) "0yg_");
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
    }

    return true;
}
