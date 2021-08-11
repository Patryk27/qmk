#undef LT
#define LT(id) (LT_SAFE_RANGE + (id))

typedef struct {
    uint16_t layer;
    uint16_t tap;
} LayerTap;

extern LayerTap layer_taps[LT_COUNT];

bool is_layer_tap(uint16_t keycode);

LayerTap* get_layer_tap(uint16_t keycode);
