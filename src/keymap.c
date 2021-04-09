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

    LT_A,
    LT_B,
    LT_C,

    MT_A,
    MT_B,
    MT_C,
    MT_D,
    MT_E,

    CK_FROWN,
    CK_SMILE,
    CK_XD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        RESET,   XXXXXXX, A(KC_SCLN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_BRIU,
        KC_ESC,  KC_A,    KC_S,       KC_D,    KC_F,    KC_G,
        MT_A,    KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,    KC_BRID,
        KC_RALT, XXXXXXX, KC_PSCR,    KC_LGUI, LT_A,

                 XXXXXXX,    KC_MAIL,
        XXXXXXX, XXXXXXX,    XXXXXXX,
        LT_C,    C(KC_LALT), C(KC_LSFT),

        XXXXXXX,     XXXXXXX, C(KC_C), C(KC_L), KC_LBRC, KC_RBRC, CK_FROWN,
        TD(TD_VOLU), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CK_SMILE,
                     KC_H,    KC_J,    KC_K,    KC_L,    MT_D,    CK_XD,
        TD(TD_VOLD), KC_N,    KC_M,    KC_COMM, KC_DOT,  MT_E,    MT_B,
                              LT_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LALT, MT_C
    ),

    [1] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,     KC_LT, KC_EXLM, KC_GT,   XXXXXXX,        XXXXXXX,
        XXXXXXX, KC_KP_PLUS,  KC_1,  KC_2,    KC_3,    KC_KP_ASTERISK, XXXXXXX,
                 KC_KP_MINUS, KC_4,  KC_5,    KC_6,    KC_KP_SLASH,    XXXXXXX,
        XXXXXXX, KC_EQL,      KC_7,  KC_8,    KC_9,    XXXXXXX,        XXXXXXX,
                              KC_0,  KC_DOT,  XXXXXXX, XXXXXXX,        XXXXXXX,

        XXXXXXX, XXXXXXX,
        KC_A,    KC_B,    KC_C,
        KC_D,    KC_E,    KC_F
    ),

    [2] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_HOME, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [3] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LALT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_WH_U,
        KC_LSFT, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_WH_D, XXXXXXX,
        KC_LCTL, KC_F9,   KC_F10,  KC_F11,  KC_F12,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
                          KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BTN3, KC_BTN1
    ),
};

struct LayerTap {
    uint16_t layer;
    uint16_t tap;
};

const struct LayerTap layer_taps[] = {
    // LT_A
    { 1, KC_SPC },

    // LT_B
    { 2, KC_ENT },

    // LT_C
    { 3, KC_UP },
};

struct ModTap {
    uint16_t mod;
    uint16_t tap;
};

const struct ModTap mod_taps[] = {
    // MT_A
    { KC_LSFT, KC_SLSH },

    // MT_B
    { KC_RSFT, KC_BSLS },

    // MT_C
    { KC_LCTL, KC_DOWN },

    // MT_D
    { KC_LCTL, KC_QUOT },

    // MT_E
    { KC_LALT, KC_GRV },
};

struct Bigram {
    uint16_t fst;
    uint16_t snd;
    uint16_t alt;
};

const struct Bigram bigrams[] = {
    // W
    { KC_W, KC_H, KC_QUES },
    { KC_W, KC_J, KC_EXLM },

    // A
    { KC_A, KC_H, KC_RPRN },
    { KC_A, KC_J, KC_RCBR },
    { KC_A, KC_K, KC_RBRC },

    // S
    { KC_S, KC_D, KC_UNDS },
    { KC_S, KC_J, KC_SCLN },
    { KC_S, KC_K, S(KC_SCLN) },

    // D
    { KC_D, KC_H, KC_LPRN },
    { KC_D, KC_J, KC_LCBR },
    { KC_D, KC_K, KC_LBRC },

    // X
    { KC_X, KC_C, KC_MINS },
    { KC_X, KC_H, KC_HASH },
    { KC_X, KC_J, KC_PERC },
    { KC_X, KC_K, KC_AT },
    { KC_X, KC_L, KC_TILD },

    // C
    { KC_C, KC_J, KC_PIPE },
    { KC_C, KC_K, KC_AMPR },
    { KC_C, KC_COMM, KC_DLR },
    { KC_C, KC_DOT, KC_CIRC },
};

void process_bigram(bool *handled, uint16_t keycode, keyrecord_t *record) {
    const uint8_t count = sizeof(bigrams) / sizeof(bigrams[0]);

    // Whether a bigram-able key is pressed at the moment
    static bool pending = false;

    // After bigram became active, whether any bigram combination was registered
    // (e.g. KC_S + KC_J)
    static bool interrupted = false;

    // After bigram became active, whether any non-bigram combination was
    // registered (e.g. KC_S + KC_A)
    static bool split = false;

    static uint16_t fst_keycode = 0;
    static uint8_t fst_mods = 0;
    static uint16_t snd_keycode = 0;

    if (*handled) {
        return;
    }

    if (keycode < KC_A || keycode > KC_Z) {
        return;
    }

    if (pending) {
        if (keycode == fst_keycode) {
            pending = false;

            if (!interrupted && !split) {
                uint8_t mods = get_mods();
                set_mods(fst_mods);
                tap_code(fst_keycode);
                set_mods(mods);
            }

            if (snd_keycode) {
                unregister_code16(snd_keycode);
            }
        } else {
            bool matched = false;

            for (uint8_t i = 0; i < count; i += 1) {
                const struct Bigram *bg = &bigrams[i];

                if (bg->fst == fst_keycode && bg->snd == keycode) {
                    keycode = bg->alt;
                    matched = true;
                    break;
                }
            }

            if (matched) {
                interrupted = true;
            } else if (!split) {
                register_code(fst_keycode);
            }

            if (record->event.pressed) {
                snd_keycode = keycode;
                register_code16(keycode);
            } else {
                snd_keycode = 0;
                unregister_code16(keycode);
            }

            if (!matched && !split) {
                split = true;
                unregister_code(fst_keycode);
            }
        }

        *handled = true;
    } else {
        if (record->event.pressed) {
            bool matched = false;

            for (uint8_t i = 0; i < count; i += 1) {
                const struct Bigram *bg = &bigrams[i];

                if (bg->fst == keycode) {
                    matched = true;
                    break;
                }
            }

            if (matched) {
                pending = true;
                interrupted = false;
                split = false;
                fst_keycode = keycode;
                fst_mods = get_mods();
                snd_keycode = 0;

                *handled = true;
            }
        }
    }
}

void process_layer_tap(bool *handled, uint16_t keycode, keyrecord_t *record) {
    const uint8_t count = sizeof(layer_taps) / sizeof(layer_taps[0]);

    // Whether an LT_* key is pressed at the moment
    static bool pending = false;

    // Whether any key was pressed _after_ `pending` was toggled on
    static bool interrupted = false;

    if (keycode < LT_A || keycode >= LT_A + count) {
        interrupted |= record->event.pressed;
        return;
    }

    if (*handled) {
        return;
    }

    const struct LayerTap *lt = &layer_taps[keycode - LT_A];

    if (record->event.pressed) {
        layer_on(lt->layer);

        pending = true;
        interrupted = false;
    } else {
        layer_off(lt->layer);

        if (pending && !interrupted) {
            tap_code16(lt->tap);
        }
    }

    *handled = true;
}

void process_mod_tap(bool *handled, uint16_t keycode, keyrecord_t *record) {
    const uint8_t count = sizeof(mod_taps) / sizeof(mod_taps[0]);

    static bool pressed = false;
    static bool interrupted = false;

    if (keycode < MT_A || keycode >= MT_A + count) {
        interrupted |= pressed && record->event.pressed;
        return;
    }

    if (*handled) {
        return;
    }

    const struct ModTap *mt = &mod_taps[keycode - MT_A];

    if (record->event.pressed) {
        register_code(mt->mod);

        pressed = true;
        interrupted = false;
    } else {
        unregister_code(mt->mod);

        if (!interrupted) {
            tap_code16(mt->tap);
        }

        pressed = false;
        interrupted = false;
    }

    *handled = true;
}

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

    switch (keycode) {
        case CK_FROWN:
            if (record->event.pressed) {
                SEND_STRING(":-//");
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
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool handled = false;

    process_bigram(&handled, keycode, record);
    process_layer_tap(&handled, keycode, record);
    process_mod_tap(&handled, keycode, record);
    process_custom_key(&handled, keycode, record);

    return !handled;
}
