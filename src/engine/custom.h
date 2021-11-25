void process_custom_key(bool *handled, uint16_t keycode, keyrecord_t *record);

void register_code16_ex(uint16_t keycode) {
    if (keycode >= CUSTOM_SAFE_RANGE) {
        bool handled = false;

        keyrecord_t record;
        record.event.pressed = true;

        process_custom_key(&handled, keycode, &record);
    } else {
        register_code16(keycode);
    }
}

void unregister_code16_ex(uint16_t keycode) {
    if (keycode >= CUSTOM_SAFE_RANGE) {
        bool handled = false;

        keyrecord_t record;
        record.event.pressed = false;

        process_custom_key(&handled, keycode, &record);
    } else {
        unregister_code16(keycode);
    }
}

void tap_code16_ex(uint16_t keycode) {
    register_code16_ex(keycode);
    unregister_code16_ex(keycode);
}
