#include QMK_KEYBOARD_H

void process_record_user_lt(bool *handled, uint16_t keycode, keyrecord_t *record);
void process_record_user_mt(bool *handled, uint16_t keycode, keyrecord_t *record);
void process_record_user_ck(bool *handled, uint16_t keycode, keyrecord_t *record);

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

    CK_TRNS,

    LT_1,
    LT_2,
    LT_3,
    LT_4,
    LT_5,
    LT_6,

    MT_LCTL,
    MT_LSFT,
    MT_RSFT,

    CK_VIM,
    CK_SMILE,
    CK_XD,
    CK_SAD,
    CK_FROWN,
};

#undef _______
#define _______ CK_TRNS

#undef XXXXXXX
#define OOOOOOO KC_NO

#define CK_EMACS A(KC_X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        RESET,   OOOOOOO, A(KC_SCLN), OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO,
        KC_TAB,  KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_BRIU,
        KC_ESC,  KC_A,    LT_4,       LT_5,    KC_F,    KC_G,
        MT_LSFT, KC_Z,    LT_6,       KC_C,    KC_V,    KC_B,    KC_BRID,
        KC_RALT, OOOOOOO, OOOOOOO,    KC_LGUI, LT_1,

                 OOOOOOO,    KC_MAIL,
        OOOOOOO, OOOOOOO,    OOOOOOO,
        LT_3,    C(KC_LALT), C(KC_LSFT),

        OOOOOOO,     OOOOOOO, C(KC_C), C(KC_L), KC_LBRC, KC_RBRC, OOOOOOO,
        TD(TD_VOLU), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CK_VIM,
                     KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, CK_EMACS,
        TD(TD_VOLD), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_GRV,  MT_RSFT,
                              LT_2,    OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO,

        CK_SAD,   CK_SMILE,
        CK_FROWN, CK_XD,    KC_PSCR,
        OOOOOOO,  KC_LALT,  MT_LCTL
    ),

    [1] = LAYOUT_ergodox_80(
        _______, _______, _______, _______, _______, _______, _______,
        _______, OOOOOOO, KC_HOME, KC_END,  _______, _______, _______,
        _______, _______, KC_BSPC, KC_DEL,  _______, _______,
        _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______,
        _______, _______, _______, _______, KC_TRNS,

                 OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,

        OOOOOOO, OOOOOOO,     KC_LT, KC_EXLM, KC_GT,   OOOOOOO,        OOOOOOO,
        OOOOOOO, KC_KP_PLUS,  KC_1,  KC_2,    KC_3,    KC_KP_ASTERISK, OOOOOOO,
                 KC_KP_MINUS, KC_4,  KC_5,    KC_6,    KC_KP_SLASH,    OOOOOOO,
        OOOOOOO, KC_EQL,      KC_7,  KC_8,    KC_9,    OOOOOOO,        OOOOOOO,
                              KC_0,  KC_DOT,  OOOOOOO, OOOOOOO,        OOOOOOO,

        OOOOOOO, OOOOOOO,
        KC_A,    KC_B,    KC_C,
        KC_D,    KC_E,    KC_F
    ),

    [2] = LAYOUT_ergodox_80(
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_PIPE, _______, _______, _______, _______,
        _______, KC_EXLM, KC_QUES, KC_AMPR, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,

                 OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,

        _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          KC_TRNS, _______, _______, _______, _______,

        OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO
    ),

    [3] = LAYOUT_ergodox_80(
        OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO,
        KC_LALT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_WH_U,
        KC_LSFT, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_WH_D, OOOOOOO,
        KC_LCTL, KC_F9,   KC_F10,  KC_F11,  KC_F12,

                 OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        KC_TRNS, OOOOOOO, OOOOOOO,

        OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, OOOOOOO, OOOOOOO,
        OOOOOOO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, OOOOOOO, OOOOOOO,
                          KC_BTN2, OOOOOOO, OOOOOOO, OOOOOOO, OOOOOOO,

        OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, KC_BTN3, KC_BTN1
    ),

    [4] = LAYOUT_ergodox_80(
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_TRNS, KC_UNDS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,

                 OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,

        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_TILD, KC_AT,   _______, _______, _______,
                 KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,

        OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO
    ),

    [5] = LAYOUT_ergodox_80(
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_TRNS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,

                 OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,

        _______, _______, _______,    _______, _______, _______, _______,
        _______, _______, _______,    _______, _______, _______, _______,
                 KC_LBRC, S(KC_SCLN), KC_SCLN, KC_RBRC, _______, _______,
        _______, _______, _______,    _______, _______, _______, _______,
                          _______,    _______, _______, _______, _______,

        OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO
    ),

    [6] = LAYOUT_ergodox_80(
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, KC_TRNS, KC_MINS, _______, _______, _______,
        _______, _______, _______, _______, _______,

                 OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,

        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,

        OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO,
        OOOOOOO, OOOOOOO, OOOOOOO
    ),
};

const uint16_t lt_alt_keycodes[] = {
    // LT_1
    KC_SPC,

    // LT_2
    KC_ENT,

    // LT_3
    KC_UP,

    // LT_4
    KC_S,

    // LT_5
    KC_D,

    // LT_6
    KC_X,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool handled = false;

    process_record_user_lt(&handled, keycode, record);
    process_record_user_mt(&handled, keycode, record);
    process_record_user_ck(&handled, keycode, record);

    return !handled;
}

void process_record_user_lt(bool *handled, uint16_t keycode, keyrecord_t *record) {
    // Whether an LT_* key is pressed at the moment
    static bool pending = false;

    // Whether `shift` was active _back when_ `pending` was toggled on
    //
    // # Abstract
    //
    // Let's consider following scenario:
    //
    // ```
    // + KC_LSFT
    // + LT_1
    // - KC_LSFT
    // - LT_1
    // ````
    //
    // If we weren't tracking `shift`, we'd print e.g. `d` instead of `D`, which
    // ends up in poor experience when typing fast
    static bool pending_with_shift = false;

    // Whether any key was pressed _after_ `pending` was toggled on
    static bool interrupted = false;

    // Keycode to send after LT_* gets down without being interrupted
    static uint16_t alt_keycode = 0;

    bool shift_active = get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {
        case CK_TRNS:
            if (pending) {
                tap_code(alt_keycode);
                pending = false;
            }
            return;

        case LT_1...LT_6:
            break;

        default:
            if (record->event.pressed) {
                interrupted = true;
            }
            return;
    }

    if (*handled) {
        return;
    }

    uint8_t idx = keycode - LT_1;
    uint8_t layer = 1 + idx;

    alt_keycode = lt_alt_keycodes[idx];

    if (record->event.pressed) {
        layer_on(layer);

        pending = true;
        pending_with_shift = shift_active;
        interrupted = false;
    } else {
        layer_off(layer);

        if (pending && !interrupted) {
            if (pending_with_shift && !shift_active) {
                register_code(KC_LSFT);
            }

            tap_code(alt_keycode);

            if (pending_with_shift && !shift_active) {
                unregister_code(KC_LSFT);
            }
        }
    }

    *handled = true;
}

void process_record_user_mt(bool *handled, uint16_t keycode, keyrecord_t *record) {
    static bool pressed = false;
    static bool interrupted = false;

    uint16_t tap_keycode;
    uint16_t mod_keycode;

    switch (keycode) {
        case MT_LCTL:
            mod_keycode = KC_LCTL;
            tap_keycode = KC_DOWN;
            break;

        case MT_LSFT:
            mod_keycode = KC_LSFT;
            tap_keycode = KC_SLSH;
            break;

        case MT_RSFT:
            mod_keycode = KC_RSFT;
            tap_keycode = KC_BSLS;
            break;

        default:
            interrupted |= pressed && record->event.pressed;
            return;
    }

    if (*handled) {
        return;
    }

    if (record->event.pressed) {
        register_code(mod_keycode);

        pressed = true;
        interrupted = false;
    } else {
        unregister_code(mod_keycode);

        if (!interrupted) {
            tap_code(tap_keycode);
        }

        pressed = false;
        interrupted = false;
    }

    *handled = true;
}

void process_record_user_ck(bool *handled, uint16_t keycode, keyrecord_t *record) {
    uint16_t fallthrough;

    switch (keycode) {
        case CK_TRNS:
            fallthrough = keymap_key_to_keycode(0, record->event.key);

            if (fallthrough >= LT_1 && fallthrough <= LT_6) {
                fallthrough = lt_alt_keycodes[fallthrough - LT_1];
            }

            if (record->event.pressed) {
                register_code(fallthrough);
            } else {
                unregister_code(fallthrough);
            }

            *handled = true;
            return;

        case CK_VIM:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) SS_LSFT(";"));
            }
            *handled = true;
            return;

        case CK_SMILE:
            if (record->event.pressed) {
                SEND_STRING(":-)");
            }
            *handled = true;
            return;

        case CK_XD:
            if (record->event.pressed) {
                SEND_STRING("xD");
            }
            *handled = true;
            return;

        case CK_SAD:
            if (record->event.pressed) {
                SEND_STRING(":-(");
            }
            *handled = true;
            return;

        case CK_FROWN:
            if (record->event.pressed) {
                SEND_STRING(":-//");
            }
            *handled = true;
            return;
    }
}
