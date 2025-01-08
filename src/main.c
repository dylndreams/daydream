#define KIT_IMPL
#include "include/kit.h"

#define KIT_RECT kit_rect(0, 0, 50, 50)

int vol = 0.5;
cm_Source* audio;

int main(int argc, char **argv) {

    kit_Context *ctx = kit_create("HELLO", 256, 192, KIT_SCALE2X | KIT_HIDECURSOR | KIT_FPS30);
    audio = kit_load_audio("assets/loop.wav");
            kit_play_audio(audio, 1, 0);
    double *dt;
    while (kit_step(ctx, dt)) {
         if (kit_audio_state(audio) == CM_STATE_STOPPED) { break; }
        // fullscreen pressed
        if (kit_key_pressed(ctx, SDLK_f)) {
         SDL_SetWindowFullscreen(ctx->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        }
          kit_clear(ctx, KIT_BLUE);
          kit_draw_text(ctx, KIT_WHITE, "hello!", 10, 10);
          kit_draw_text(ctx, KIT_WHITE, "welcome to kit.h!", 10, 20);
        }
      /* Clean up */
    kit_free_audio(audio);
    kit_destroy(ctx);
    return 0;
}
