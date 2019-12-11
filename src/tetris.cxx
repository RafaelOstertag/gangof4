#include "board.hh"
#include "boardrenderer.hh"
#include "circulartetriminostock.hh"
#include "normaltetriminostock.hh"
#include "preview.hh"
#include "scorer.hh"
#include "sdl.hh"
#include "text.hh"
#include "window.hh"

#include <cassert>
#include <iostream>

constexpr int baseRetardingValue = 78;

int main() {
    if (!init_sdl()) {
        std::cerr << SDL_GetError() << std::endl;
        return 1;
    }
    atexit(quit_sdl);

    std::shared_ptr<TetriminoStock> tetriminoStock{new NormalTetriminoStock{}};
    scorer_ptr_t scorer{new Scorer{Board::width}};
    std::shared_ptr<Board> board{new Board{tetriminoStock, grey, scorer}};

    Text scoreLabel{
        "resources/lucidasansdemibold.ttf", 18, 320, 200, white, "Score"};
    Text scoreText{"resources/lucidasansdemibold.ttf", 18, 320, 230, white,
                   std::to_string(scorer->getScore())};
    Text levelLabel{
        "resources/lucidasansdemibold.ttf", 18, 320, 270, white, "Level"};
    Text levelText{"resources/lucidasansdemibold.ttf", 18, 320, 300, white,
                   std::to_string(scorer->getLevel())};

    Text nextTetrimino{
        "resources/lucidasansdemibold.ttf", 18, 320, 10, white, "Next"};

    Text gameOverText{
        "resources/lucidasansdemibold.ttf", 25, 130, 200, white, "Game Over"};

    Window window{"Tetris", 520, 500, black};

    auto minoTextureStore = createMinoTextureStore(window.getRenderer());
    BoardRenderer boardRenderer{100, 10, board, minoTextureStore};

    Preview preview{320, 40, tetriminoStock, minoTextureStore, grey};

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

        counter %= retardingValue;
        if (counter == 0) {
            board->nextMove();
            retardingValue = baseRetardingValue - 4 * scorer->getLevel();

            scoreText.setText(std::to_string(scorer->getScore()));
            levelText.setText(std::to_string(scorer->getLevel()));
        }

        counter++;

        window.clear();

        window.render(boardRenderer);
        window.render(preview);

        window.render(scoreLabel);
        window.render(scoreText);
        window.render(levelLabel);
        window.render(levelText);
        window.render(nextTetrimino);
        if (board->isGameOver()) {
            window.render(gameOverText);
        }

        window.update();

        SDL_Delay(10);
    }
}
