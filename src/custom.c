enum custom_keys {
    _ = CUSTOM_SAFE_RANGE,

    CK_2CLN,
    CK_FROWN,
    CK_HEART,
    CK_SMILE,
    CK_XD,
};

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

    switch (keycode) {
        case RESET:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            return;

        case CK_2CLN:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            *handled = true;
            return;

        case CK_FROWN:
            if (record->event.pressed) {
                SEND_STRING(":-//");
            }
            *handled = true;
            return;

        case CK_HEART:
            if (record->event.pressed) {
                SEND_STRING("<3");
            }
            *handled = true;
            return;

        case CK_SMILE:
            if (record->event.pressed) {
                SEND_STRING(":-)");
            }
            *handled = true;
            return;

        case CK_TRNS:
            keycode = keymap_key_to_keycode(0, record->event.key);

            if (is_layer_tap(keycode)) {
                keycode = get_layer_tap(keycode)->tap;
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
