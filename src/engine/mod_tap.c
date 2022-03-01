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

    if (*handled) {
        return;
    }

    if (!is_mod_tap(keycode)) {
        if (_active) {
            if (is_layer_tap(keycode)) {
                keycode = get_layer_tap(keycode)->tap;
            }

            if (_interrupted) {
                //
            } else {
                if (record->event.pressed) {
                    _interrupted = true;
                    register_code16(_active->mod);
                    register_code16_ex(keycode);
                    *handled = true;
                }
            }
        }

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
                    tap_code16_ex(_active->tap);
                }

                _active = NULL;
                _mod_tap_active = false;
            }
        } else {
            _interrupted = true;
            register_code16(_active->mod);

            if (record->event.pressed) {
                register_code16_ex(current->tap);
            } else {
                unregister_code16_ex(current->tap);
            }
        }
    } else {
        if (record->event.pressed) {
            _active = current;
            _interrupted = false;
            _mod_tap_active = true;
        } else {
            unregister_code16_ex(current->tap);
        }
    }

    *handled = true;
}
