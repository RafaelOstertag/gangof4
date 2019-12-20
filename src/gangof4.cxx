#include "consts.hh"
#include "easygamefactory.hh"
#include "gof_version.h"
#include "intro.hh"
#include "pausetext.hh"
#include "sdl.hh"
#include "window.hh"

#include <iostream>

constexpr int baseRetardingValue = 78;

bool showIntro(Window& window, FontFactory& fontFactory) {

    window.clear();
    Intro intro{fontFactory};
    window.render(intro);
    window.update();

    SDL_Event event;
    while (true) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                return false;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_q:
                    return false;
                case SDLK_RETURN:
                case SDLK_RETURN2:
                case SDLK_KP_ENTER:
                    return true;
                }
            }
        }

        SDL_Delay(250);
    }
}

void showPauseText(Window& window, PauseText& pauseText) {
    window.render(pauseText);
    window.update();
}

void run() {
    Window window{PROJECT_NAME, WINDOW_WIDTH_PX, WINDOW_HEIGHT_PX, DARK_GRAY};
    FontFactory fontFactory;
    EasyGameFactory easyGameFactory{window, fontFactory};
    GamePtr game = easyGameFactory.create();

    int counter = 0;
    int retardingValue = baseRetardingValue;
    SDL_Event event;
    bool pause{false};
    PauseText pauseText{fontFactory};

    // Pressing 'q' in the intro must quit
    bool run = showIntro(window, fontFactory);
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
                    game = easyGameFactory.create();
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
            SDL_Delay(150);
            showPauseText(window, pauseText);
            continue;
        } else {
            pauseText.reset();
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

void printYadaYada() {
    std::cout << PROJECT_NAME << " " << VERSION_MAJOR << "." << VERSION_MINOR
              << "." << VERSION_PATCH << "\n\n"
              << "Copyright (c) 2019 Rafael Ostertag <rafi@guengel.ch>\n"
              << "Fonts Copyright (c) 2003 by Bitstream, Inc\n\n";
}

int main() {
    printYadaYada();

    SDL::initialize();
    if (!SDL::isInitialized()) {
        return 1;
    }

    try {
        run();
        return 0;
    } catch (std::exception& e) {
        std::cerr << "Ooops! " << e.what() << "\n";
        return 2;
    }

    SDL::shutdown();
}
