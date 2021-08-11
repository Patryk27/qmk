void process_combo(bool *handled, uint16_t keycode, keyrecord_t *record) {
    // Currently pressed combo
    static const Combo *_active = NULL;

    // Whether any combo combo was registered
    static bool _interrupted;

    // Whether any non-combo combo was registered
    static bool _split;

    // Which mods were active when combo was initiated
    static uint8_t _mods;

    // Which second key is pressed, if any
    static uint16_t _overlapped_key;

    static bool _pressed[KC_Z - KC_A + 1] = { false };

    if (_mod_tap_active || *handled) {
        return;
    }

    if (keycode < KC_A || keycode > KC_Z) {
        return;
    }

    if (is_mod_tap(keycode)) {
        keycode = get_mod_tap(keycode)->tap;
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

                _active = NULL;
            }
        } else {
            bool matched = false;

            for (uint8_t i = 0; i < COMBO_COUNT; i += 1) {
                const Combo *cb = &combos[i];

                if (cb->fst == _active->fst && cb->snd == keycode) {
                    keycode = cb->alt;
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
            for (uint8_t i = 0; i < COMBO_COUNT; i += 1) {
                const Combo *cb = &combos[i];

                if (cb->fst == keycode) {
                    _active = cb;
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
