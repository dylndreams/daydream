#define KIT_IMPL
#include "kit.h"

#define KIT_RECT kit_rect(0, 0, 50, 50)

int main(void) {
    kit_Context *ctx = kit_create("HELLO", 320, 240, KIT_SCALE2X | KIT_HIDECURSOR | KIT_FPS30);
    while (kit_step(ctx, NULL)) {
      if (kit_key_pressed(ctx, SDLK_ESCAPE)) { break; }
        kit_draw_rect(ctx, KIT_GREEN, KIT_RECT);
    }
    kit_destroy(ctx);
    return 0;
}
