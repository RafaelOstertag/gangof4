#include "game.hh"
#include "sdl.hh"
#include "window.hh"

#include <iostream>

constexpr int baseRetardingValue = 78;

int main() {
    if (!init_sdl()) {
        std::cerr << SDL_GetError() << std::endl;
        return 1;
    }
    atexit(quit_sdl);

    Window window{"Tetris", 520, 500, darkGrey};
    GamePtr game{new Game{window}};

    int counter = 0;
    int retardingValue = baseRetardingValue;

    SDL_Event event;
    bool run{true};
    bool pause{false};
    while (run) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                run = false;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_q:
                    run = false;
                    break;

                case SDLK_p:
                    pause = !pause;
                    break;
                case SDLK_r:
                    counter = 0;
                    retardingValue = baseRetardingValue;
                    pause = false;
                    game = GamePtr{new Game{window}};
                    break;

                case SDLK_UP:
                    game->rotateCurrentTetrimino();
                    break;

                case SDLK_DOWN:
                    game->nextMove();
                    break;

                case SDLK_LEFT:
                    game->moveCurrentTetriminoLeft();
                    break;

                case SDLK_RIGHT:
                    game->moveCurrentTetriminoRight();
                    break;
                }
            }
        }

        if (pause) {
            SDL_Delay(500);
            continue;
        }

        counter %= retardingValue;
        if (counter == 0) {
            game->nextMove();
            retardingValue =
                baseRetardingValue - 4 * game->getScorer()->getLevel();
        }

        counter++;

        window.clear();
        window.render(*game);
        window.update();

        SDL_Delay(10);
    }
}
