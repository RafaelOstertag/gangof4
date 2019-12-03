#include "minorenderer.hh"
#include "sdl.hh"
#include "window.hh"

int main() {
    if (!init_sdl()) {
        return 1;
    }
    atexit(quit_sdl);

    Color windowColor(0xff, 0xff, 0xff, 0x0);
    Window window{"Mino Renderer", 640, 480, windowColor};

    Mino mino{0, 0};
    Color minoColor{0x7f, 0x7f, 0x7f, 0x0};

    MinoRenderer minoRenderer{100, 100, 20, minoColor, mino};

    window.clear();
    window.render(minoRenderer);
    window.update();

    SDL_Delay(1000);
}
