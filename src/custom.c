enum custom_keys {
    _ = CUSTOM_SAFE_RANGE,
    CK_EMACS,
};

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

    static bool _del_active = false;

    switch (keycode) {
        case CK_EMACS:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_X);
                unregister_code(KC_X);
                unregister_code(KC_LALT);
            }

            *handled = true;
            return;

        case RESET:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            return;

        case KC_BSPC:
            if (record->event.pressed) {
                if (get_mods() & MOD_LSFT) {
                    unregister_code(KC_LSFT);
                    register_code(KC_DEL);

                    _del_active = true;
                    *handled = true;
                }
            } else {
                if (_del_active) {
                    unregister_code(KC_DEL);
                    register_code(KC_LSFT);

                    _del_active = false;
                    *handled = true;
                }
            }

            return;
    }
}
