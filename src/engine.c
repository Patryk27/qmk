#define CK_TRNS (SAFE_RANGE)
#define LT_SAFE_RANGE (CK_TRNS + 1)
#define MT_SAFE_RANGE (LT_SAFE_RANGE + LT_COUNT + 1)
#define CUSTOM_SAFE_RANGE (MT_SAFE_RANGE + MT_COUNT + 1)

#undef _______
#define _______ CK_TRNS

#include "engine/custom.h"
#include "engine/combo.h"
#include "engine/layer_tap.h"
#include "engine/mod_tap.h"

#include "engine/combo.c"
#include "engine/layer_tap.c"
#include "engine/mod_tap.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool handled = false;

    process_combo(&handled, keycode, record);
    process_layer_tap(&handled, keycode, record);
    process_mod_tap(&handled, keycode, record);
    process_custom_key(&handled, keycode, record);

    return !handled;
}
