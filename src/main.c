#define KIT_IMPL
#include "include/kit.h"

#define KIT_RECT kit_rect(0, 0, 50, 50)

int vol = 128;

int main(int argc, char **argv) {

    kit_Context *ctx = kit_create("HELLO", 256, 192, KIT_SCALE2X | KIT_HIDECURSOR | KIT_FPS30);
    double *dt;
    while (kit_step(ctx, dt)) {
        if (kit_key_pressed(ctx, SDLK_ESCAPE)) { break; }
          kit_clear(ctx, KIT_BLUE);
          kit_draw_text(ctx, KIT_WHITE, "hello!", 10, 10);
          kit_draw_text(ctx, KIT_WHITE, "this is hello from kit.h!", 10, 20);
          // Draw the score
        char watchvol[32];
        sprintf(watchvol, "VOL:%d", vol);
        kit_draw_text(ctx, KIT_WHITE, watchvol, 10, 30);
         kit_play_audio(ctx, "assets/loop.wav", vol, false);
             // Example: Increase volume
            if (kit_key_pressed(ctx, SDLK_UP)) {
            vol += 8;
            }

            // Example: Decrease volume
            if (kit_key_pressed(ctx, SDLK_DOWN)) {
            vol -= 8;
            }
        }
      /* Clean up */
    kit_destroy(ctx);
    return 0;
}
