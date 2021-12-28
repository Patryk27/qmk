enum custom_keys {
    _ = CUSTOM_SAFE_RANGE,
    CK_SLSH,
    CK_ARROW,
    CK_EMACS,
};

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

    switch (keycode) {
        case CK_SLSH: {
            bool shift = get_mods() & MOD_MASK_SHIFT;
            keycode = shift ? KC_BSLS : KC_SLSH;

            if (record->event.pressed) {
                if (shift) {
                    unregister_code(KC_LSFT);
                }

                register_code(keycode);

                if (shift) {
                    register_code(KC_LSFT);
                }
            } else {
                unregister_code(keycode);
            }

            *handled = true;
            break;
        }

        case CK_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }

            *handled = true;
            break;

        case CK_EMACS:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_X);
                unregister_code(KC_X);
                unregister_code(KC_LALT);
            }

            *handled = true;
            return;
    }
}
