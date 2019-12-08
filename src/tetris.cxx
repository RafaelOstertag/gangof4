#include "board.hh"
#include "boardrenderer.hh"
#include "sdl.hh"
#include "window.hh"

#include <cassert>
#include <iostream>

int main() {
    if (!init_sdl()) {
        std::cerr << SDL_GetError() << std::endl;
        return 1;
    }
    atexit(quit_sdl);

    TetriminoStock tetriminoStock{};
    std::shared_ptr<Board> board{new Board{tetriminoStock}};

    BoardRenderer boardRenderer{board};

    Window window{"Tetris", 480, 640, white};

    int counter = 0;
    int speed = 60;

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

                case SDLK_UP:
                    board->rotateCurrentTetrimino();
                    break;

                case SDLK_DOWN:
                    board->nextMove();
                    break;

                case SDLK_LEFT:
                    board->moveCurrentTetriminoLeft();
                    break;

                case SDLK_RIGHT:
                    board->moveCurrentTetriminoRight();
                    break;
                }
            }
        }

        if (pause) {
            SDL_Delay(500);
            continue;
        }

        if (counter % speed == 0) {
            board->nextMove();
            counter = 0;
        }
        if (board->isGameOver()) {
            std::cout << "Game Over" << std::endl;
            return 0;
        }
        counter++;

        window.clear();

        window.render(boardRenderer);

        window.update();

        SDL_Delay(16);
    }
}
