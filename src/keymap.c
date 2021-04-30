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

    CK_TRNS,
    CK_XD,
};

#undef _______
#define _______ CK_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_80(
        RESET,   XXXXXXX, KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BRIU,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        MT_A,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BRID,
        KC_RALT, XXXXXXX, KC_PSCR, KC_LGUI, LT_A,

                 XXXXXXX, KC_MAIL,
        XXXXXXX, XXXXXXX, XXXXXXX,
        LT_C,    XXXXXXX, XXXXXXX,

        XXXXXXX,     XXXXXXX, XXXXXXX, CK_XD,   KC_LBRC, KC_RBRC, XXXXXXX,
        TD(TD_VOLU), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
                     KC_H,    KC_J,    KC_K,    KC_L,    MT_D,    XXXXXXX,
        TD(TD_VOLD), KC_N,    KC_M,    KC_COMM, KC_DOT,  MT_E,    MT_B,
                              LT_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, MT_C
    ),

    [1] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______,
        XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LPRN, KC_RPRN, KC_PAST, KC_PSLS, KC_PERC, XXXXXXX,
                 KC_LCBR, KC_RCBR, KC_PPLS, KC_PMNS, KC_EXLM, XXXXXXX,
        XXXXXXX, KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   XXXXXXX, XXXXXXX,
                          KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [2] = LAYOUT_ergodox_80(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_A,    KC_B,    XXXXXXX,
        XXXXXXX, KC_4,    KC_5,    KC_6,    KC_C,    KC_D,
        XXXXXXX, KC_7,    KC_8,    KC_9,    KC_E,    KC_F,    XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_0,

                 XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX,
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
    { 3, KC_DOWN },
};

const uint8_t layer_taps_count = sizeof(layer_taps) / sizeof(layer_taps[0]);

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
    { S(KC_LCTL), KC_UP },

    // MT_D
    { KC_LCTL, KC_QUOT },

    // MT_E
    { C(KC_LALT), KC_GRV },
};

const uint8_t mod_taps_count = sizeof(mod_taps) / sizeof(mod_taps[0]);

struct Bigram {
    uint16_t fst;
    uint16_t snd;
    uint16_t alt;
};

const struct Bigram bigrams[] = {
    // W
    { KC_W, KC_H, KC_CIRC },
    { KC_W, KC_J, KC_DLR },
    { KC_W, KC_K, KC_TILD },

    // A
    { KC_A, KC_H, KC_QUES },
    { KC_A, KC_J, KC_EXLM },

    // S
    { KC_S, KC_D, KC_UNDS },
    { KC_S, KC_J, KC_SCLN },
    { KC_S, KC_K, S(KC_SCLN) },
    { KC_S, KC_N, A(KC_SCLN) },

    // D
    { KC_D, KC_H, KC_PIPE },
    { KC_D, KC_J, KC_AMPR },

    // X
    { KC_X, KC_C, KC_MINS },
    { KC_X, KC_H, KC_HASH },
    { KC_X, KC_J, KC_AT },
};

const uint8_t bigrams_count = sizeof(bigrams) / sizeof(bigrams[0]);

void process_bigram(bool *handled, uint16_t keycode, keyrecord_t *record) {
    // Currently pressed bigram
    static const struct Bigram *_active = 0;

    // Whether any bigram combo was registered
    static bool _interrupted = false;

    // Whether any non-bigram combo was registered
    static bool _split = false;

    // Mods that were active when bigram was initiated
    static uint8_t _mods = 0;

    // Which second key is pressed, if any
    static uint16_t _overlapped_key = 0;

    static bool _pressed[KC_Z - KC_A + 1] = { false };

    if (*handled) {
        return;
    }

    if (keycode < KC_A || keycode > KC_Z) {
        return;
    }

    if (_active) {
        if (keycode == _active->fst) {
            if (record->event.pressed) {
                // Unreachable
            } else {
                if (!_interrupted && !_split) {
                    uint8_t mods = get_mods();
                    set_mods(_mods);
                    tap_code(_active->fst);
                    set_mods(mods);
                }

                if (_overlapped_key) {
                    unregister_code16(_overlapped_key);
                }

                _active = 0;
            }
        } else {
            bool matched = false;

            for (uint8_t i = 0; i < bigrams_count; i += 1) {
                const struct Bigram *bg = &bigrams[i];

                if (bg->fst == _active->fst && bg->snd == keycode) {
                    keycode = bg->alt;
                    matched = true;
                    break;
                }
            }

            if (matched) {
                _interrupted |= record->event.pressed;
            } else if (!_split) {
                register_code(_active->fst);
            }

            if (record->event.pressed) {
                if (_overlapped_key) {
                    unregister_code16(_overlapped_key);
                }

                _overlapped_key = keycode;
                register_code16(keycode);
            } else {
                if (keycode == _overlapped_key) {
                    _overlapped_key = 0;
                }

                unregister_code16(keycode);
            }

            if (!matched && !_split) {
                _split = true;
                unregister_code(_active->fst);
            }
        }

        *handled = true;
    } else {
        if (record->event.pressed) {
            for (uint8_t i = 0; i < bigrams_count; i += 1) {
                const struct Bigram *bg = &bigrams[i];

                if (bg->fst == keycode) {
                    _active = bg;
                    break;
                }
            }

            if (_active) {
                for (uint8_t i = 0; i < 26; i += 1) {
                    if (_pressed[i]) {
                        unregister_code(KC_A + i);
                        _pressed[i] = false;
                    }
                }

                _interrupted = false;
                _split = false;
                _mods = get_mods();
                _overlapped_key = 0;

                *handled = true;
            } else {
                _pressed[keycode - KC_A] = true;
            }
        } else {
            _pressed[keycode - KC_A] = false;
        }
    }
}

void process_layer_tap(bool *handled, uint16_t keycode, keyrecord_t *record) {
    // Currently pressed LT key
    static const struct LayerTap *_active = 0;

    // Whether any key was pressed after LT was activated
    static bool _interrupted = false;

    if (keycode == CK_TRNS && record->event.pressed && _active) {
        tap_code16(_active->tap);
    }

    if (keycode < LT_A || keycode >= LT_A + layer_taps_count) {
        _interrupted |= record->event.pressed;
        return;
    }

    if (*handled) {
        return;
    }

    if (_active) {
        if (record->event.pressed) {
            // Unreachable
        } else {
            layer_off(_active->layer);

            if (!_interrupted) {
                tap_code16(_active->tap);
            }

            _active = 0;
        }
    } else {
        const struct LayerTap *current = &layer_taps[keycode - LT_A];

        if (record->event.pressed) {
            _active = current;
            _interrupted = false;

            layer_on(_active->layer);
        } else {
            tap_code16(current->tap);
        }
    }

    *handled = true;
}

void process_mod_tap(bool *handled, uint16_t keycode, keyrecord_t *record) {
    // Currently pressed MT key
    static const struct ModTap *_active = 0;

    // Whether any key was pressed after MT was activated
    static bool _interrupted = false;

    // Which second key is pressed, if any
    static uint16_t _overlapped_key = 0;

    if (keycode < MT_A || keycode >= MT_A + mod_taps_count) {
        _interrupted |= record->event.pressed;
        return;
    }

    if (*handled) {
        return;
    }

    const struct ModTap *current = &mod_taps[keycode - MT_A];

    if (_active) {
        if (current == _active) {
            if (record->event.pressed) {
                // Unreachable
            } else {
                unregister_code16(_active->mod);

                if (!_interrupted) {
                    tap_code16(_active->tap);
                }

                if (_overlapped_key) {
                    unregister_code16(_overlapped_key);
                }

                _active = 0;
            }
        } else {
            _interrupted = true;
            keycode = current->tap;

            if (record->event.pressed) {
                if (_overlapped_key) {
                    unregister_code16(_overlapped_key);
                }

                _overlapped_key = keycode;
                register_code16(keycode);
            } else {
                if (keycode == _overlapped_key) {
                    _overlapped_key = 0;
                }

                unregister_code16(keycode);
            }
        }
    } else if (record->event.pressed) {
        _active = current;
        _interrupted = false;
        _overlapped_key = 0;

        register_code16(_active->mod);
    }

    *handled = true;
}

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

    switch (keycode) {
        case CK_TRNS:
            keycode = keymap_key_to_keycode(0, record->event.key);

            if (keycode >= LT_A && keycode < LT_A + layer_taps_count) {
                keycode = layer_taps[keycode - LT_A].tap;
            }

            if (record->event.pressed) {
                register_code(keycode);
            } else {
                unregister_code(keycode);
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
