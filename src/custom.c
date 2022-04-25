enum custom_keys {
    _ = CUSTOM_SAFE_RANGE,
    CK_ARROW,
    CK_ARROW2,
};

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

    switch (keycode) {
        case CK_ARROW:
        case CK_ARROW2:
            if (record->event.pressed) {
                switch (keycode) {
                    case CK_ARROW:
                        SEND_STRING("->");
                        break;

                    case CK_ARROW2:
                        SEND_STRING("=>");
                        break;
                }
            }

            *handled = true;
            break;
    }
}
