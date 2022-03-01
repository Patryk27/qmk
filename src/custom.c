enum custom_keys {
    _ = CUSTOM_SAFE_RANGE,
    CK_ARROW,
};

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

    switch (keycode) {
        case CK_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }

            *handled = true;
            break;
    }
}
