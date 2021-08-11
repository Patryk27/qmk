#undef MT
#define MT(id) (MT_SAFE_RANGE + (id))

typedef struct {
    uint16_t mod;
    uint16_t tap;
} ModTap;

extern ModTap mod_taps[MT_COUNT];

bool _mod_tap_active = false;

bool is_mod_tap(uint16_t keycode);

ModTap* get_mod_tap(uint16_t keycode);
