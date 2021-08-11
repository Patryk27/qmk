bool is_mod_tap(uint16_t keycode) {
    return keycode >= MT_SAFE_RANGE && keycode < (MT_SAFE_RANGE + MT_COUNT);
}

ModTap* get_mod_tap(uint16_t keycode) {
    return &mod_taps[keycode - MT_SAFE_RANGE];
}

void process_mod_tap(bool *handled, uint16_t keycode, keyrecord_t *record) {
    // Currently pressed MT key
    static const ModTap *_active = NULL;

    // Whether any key was pressed after MT was activated
    static bool _interrupted;

    // Which second key is pressed, if any
    static uint16_t _overlapped_key;

    if (!is_mod_tap(keycode)) {
        if (_active && !_interrupted && record->event.pressed) {
            _interrupted = true;
            register_code16(_active->mod);
        }

        return;
    }

    if (*handled) {
        return;
    }

    const ModTap *current = get_mod_tap(keycode);

    if (_active) {
        if (current == _active) {
            if (record->event.pressed) {
                // Unreachable
            } else {
                if (_interrupted) {
                    unregister_code16(_active->mod);
                } else {
                    tap_code16(_active->tap);
                }

                if (_overlapped_key) {
                    unregister_code16(_overlapped_key);
                }

                _active = NULL;
                _mod_tap_active = false;
            }
        } else {
            if (record->event.pressed) {
                if (!_interrupted) {
                    _interrupted = true;
                    register_code16(_active->mod);
                }

                keycode = current->tap;

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
        _mod_tap_active = true;
    }

    *handled = true;
}
