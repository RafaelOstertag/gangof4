#include "tetriminorenderer.hh"
#include "sdl.hh"
#include "window.hh"

#include <algorithm>

int main() {

    if (!init_sdl()) {
        return 1;
    }
    atexit(quit_sdl);

    Color windowColor(0xff, 0xff, 0xff, 0x0);
    Window window{"Tetriminorenderer", 640, 480, windowColor};

    Color tetriminoColor{0x7f, 0x7f, 0x7f, 0x0};

    std::vector<std::shared_ptr<Tetrimino>> tetriminos;
    auto iTetrimino{createITetrimino()};
    tetriminos.push_back(iTetrimino);

    std::vector<TetriminoRenderer> renderers;
    TetriminoRenderer iTetriminoRenderer{100, 100, tetriminoColor, iTetrimino};
    renderers.push_back(iTetriminoRenderer);

    auto jTetrimino{createJTetrimino()};
    tetriminos.push_back(jTetrimino);
    TetriminoRenderer jTetriminoRenderer{200, 100, tetriminoColor, jTetrimino};
    renderers.push_back(jTetriminoRenderer);

    auto lTetrimino{createLTetrimino()};
    tetriminos.push_back(lTetrimino);
    TetriminoRenderer lTetriminoRenderer{300, 100, tetriminoColor, lTetrimino};
    renderers.push_back(lTetriminoRenderer);

    auto oTetrimino{createOTetrimino()};
    tetriminos.push_back(oTetrimino);
    TetriminoRenderer oTetriminoRenderer{400, 100, tetriminoColor, oTetrimino};
    renderers.push_back(oTetriminoRenderer);

    auto tTetrimino{createTTetrimino()};
    tetriminos.push_back(tTetrimino);
    TetriminoRenderer tTetriminoRenderer{100, 200, tetriminoColor, tTetrimino};
    renderers.push_back(tTetriminoRenderer);

    auto sTetrimino{createSTetrimino()};
    tetriminos.push_back(sTetrimino);
    TetriminoRenderer sTetriminoRenderer{200, 200, tetriminoColor, sTetrimino};
    renderers.push_back(sTetriminoRenderer);

    auto zTetrimino{createZTetrimino()};
    tetriminos.push_back(zTetrimino);
    TetriminoRenderer zTetriminoRenderer{300, 200, tetriminoColor, zTetrimino};
    renderers.push_back(zTetriminoRenderer);

    SDL_Event event;
    bool run{true};
    while (run) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                run = false;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_q:
                    run = false;
                    break;

                case SDLK_UP:
                    std::for_each(
                        tetriminos.begin(), tetriminos.end(),
                        [](auto tetrimino) { tetrimino->rotateClockwise(); });
                    break;

                case SDLK_DOWN:
                    std::for_each(
                        tetriminos.begin(), tetriminos.end(),
                        [](auto tetrimino) { tetrimino->moveDown(); });
                    break;

                case SDLK_LEFT:
                    std::for_each(
                        tetriminos.begin(), tetriminos.end(),
                        [](auto tetrimino) { tetrimino->moveLeft(); });
                    break;

                case SDLK_RIGHT:
                    std::for_each(
                        tetriminos.begin(), tetriminos.end(),
                        [](auto tetrimino) { tetrimino->moveRight(); });
                    break;
                }
            }
        }

        window.clear();
        std::for_each(renderers.begin(), renderers.end(),
                      [&window](auto renderer) { window.render(renderer); });
        window.update();

        SDL_Delay(30);
    }
}
