#include "blockletrenderer.hh"
#include "sdl.hh"
#include "window.hh"

int main() {
    if (!init_sdl()) {
        return 1;
    }
    atexit(quit_sdl);

    Color windowColor(0xff, 0xff, 0xff, 0x0);
    Window window{"Blockletrenderer", 640, 480, windowColor};

    Blocklet blocklet{0, 0};
    Color blockletColor{0x7f, 0x7f, 0x7f, 0x0};

    BlockletRenderer blockletRenderer{100, 100, 20, blockletColor, blocklet};

    window.clear();
    window.render(blockletRenderer);
    window.update();

    SDL_Delay(1000);
}
