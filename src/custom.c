enum custom_keys {
    _ = CUSTOM_SAFE_RANGE,
};

void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record) {
    if (*handled) {
        return;
    }

    switch (keycode) {
            break;
    }
}
