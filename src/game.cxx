#include "game.hh"

#include <SDL_mixer.h>
#include <iostream>

Game::Game(const Window& window)
    : tetriminoStock{new NormalTetriminoStock{}},
      scorer{new Scorer{Board::width}}, board{new Board{tetriminoStock,
                                                        lightGrey, scorer}},
      font18{new Font{"resources/lucidasansdemibold.ttf", 18}},
      font25{new Font{"resources/lucidasansdemibold.ttf", 25}},
      scoreLabel{font18, 320, 200, white, "Score"},
      scoreText{font18, 320, 230, white, std::to_string(scorer->getScore())},
      levelLabel{font18, 320, 270, white, "Level"},
      levelText{font18, 320, 300, white, std::to_string(scorer->getLevel())},
      nextTetrimino{font18, 320, 10, white, "Next"}, gameOverText{font25, 130,
                                                                  200, white,
                                                                  "Game Over"},
      minoTextureStore{createMinoTextureStore(window.getRenderer())},
      boardRenderer{100, 10, board, minoTextureStore}, preview{320, 40,
                                                               tetriminoStock,
                                                               minoTextureStore,
                                                               lightGrey},
      moveSound{"resources/move.wav"}, rotateSound{"resources/rotate.wav"} {
#ifndef NDEBUG
    std::cout << "Initialized game" << std::endl;
#endif
}

Game::~Game() {
#ifndef NDEBUG
    std::cout << "Destroyed game" << std::endl;
#endif
}

void Game::rotateCurrentTetrimino() {
    board->rotateCurrentTetrimino();
    Mix_PlayChannel(1, rotateSound.getMixChunk(), 0);
}

void Game::moveCurrentTetriminoLeft() {
    board->moveCurrentTetriminoLeft();
    Mix_PlayChannel(0, moveSound.getMixChunk(), 0);
}
void Game::moveCurrentTetriminoRight() {
    board->moveCurrentTetriminoRight();
    Mix_PlayChannel(0, moveSound.getMixChunk(), 0);
}

void Game::nextMove() {
    board->nextMove();
    scoreText.setText(std::to_string(scorer->getScore()));
    levelText.setText(std::to_string(scorer->getLevel()));
    Mix_PlayChannel(0, moveSound.getMixChunk(), 0);
}

void Game::render(const Renderer& renderer) {
    boardRenderer.render(renderer);
    preview.render(renderer);
    scoreLabel.render(renderer);
    scoreText.render(renderer);
    levelLabel.render(renderer);
    levelText.render(renderer);
    nextTetrimino.render(renderer);

    if (board->isGameOver()) {
        gameOverText.render(renderer);
    }
}
