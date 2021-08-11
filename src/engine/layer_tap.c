bool is_layer_tap(uint16_t keycode) {
    return keycode >= LT_SAFE_RANGE && keycode < (LT_SAFE_RANGE + LT_COUNT);
}

LayerTap* get_layer_tap(uint16_t keycode) {
    return &layer_taps[keycode - LT_SAFE_RANGE];
}

void process_layer_tap(bool *handled, uint16_t keycode, keyrecord_t *record) {
    // Currently pressed LT key
    static const LayerTap *_active = NULL;

    // Whether any key was pressed after LT was activated
    static bool _interrupted;

    if (keycode == CK_TRNS && record->event.pressed && _active) {
        tap_code16(_active->tap);
    }

    if (!is_layer_tap(keycode)) {
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

            _active = NULL;
        }
    } else {
        const LayerTap *current = get_layer_tap(keycode);

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
