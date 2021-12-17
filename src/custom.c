enum custom_keys {
    _ = CUSTOM_SAFE_RANGE,
    CK_EMACS,
};

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

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
    }
}
