#include "game.hh"
#include "collision.hh"
#include "gameover.hh"
#include "move.hh"
#include "rotate.hh"
#include "rowfull.hh"
#include "veramonobold.hh"

#include <cassert>
#include <iostream>

Game::Game(const Window& window)
    : tetriminoStock{new NormalTetriminoStock{}},
      scorer{new Scorer{Board::width}}, board{new Board{tetriminoStock, white,
                                                        scorer}},
      font18{new Font{veraMonoBoldTTF.data, veraMonoBoldTTF.size, 18}},
      font25{new Font{veraMonoBoldTTF.data, veraMonoBoldTTF.size, 25}},
      score{"Score", std::to_string(scorer->getScore()), white, 10, 10},
      level{"Level", std::to_string(scorer->getLevel()), white, 10, 390},
      nextTetrimino{font18, 490, 170, white, "Next"}, gameOverText{font25, 232,
                                                                   200, white,
                                                                   "Game Over"},
      minoTextureStore{createMinoTextureStore(window.getRenderer())},
      boardRenderer{200, 10, board, minoTextureStore}, preview{490, 200,
                                                               tetriminoStock,
                                                               minoTextureStore,
                                                               white},
      moveSound{moveWAV.data, moveWAV.size}, rotateSound{rotateWAV.data,
                                                         rotateWAV.size},
      collisionSound{collisionWAV.data, collisionWAV.size},
      rowFullSound{rowFullWAV.data, rowFullWAV.size}, gameOverSound{
                                                          gameOverWAV.data,
                                                          gameOverWAV.size} {
#ifndef NDEBUG
    std::cout << "Initialized game" << std::endl;
#endif
    BoardCallbackPtr rotateCallback{new SoundCallback{ROTATE, rotateSound, 1}};
    board->registerBoardCallback(rotateCallback);

    BoardCallbackPtr moveDownCallback{
        new SoundCallback{MOVE_DOWN, moveSound, 0}};
    board->registerBoardCallback(moveDownCallback);

    BoardCallbackPtr moveRightCallback{
        new SoundCallback{MOVE_RIGHT, moveSound, 0}};
    board->registerBoardCallback(moveRightCallback);

    BoardCallbackPtr moveLeftCallback{
        new SoundCallback{MOVE_LEFT, moveSound, 0}};
    board->registerBoardCallback(moveLeftCallback);

    BoardCallbackPtr collisionCallback{
        new SoundCallback{COLLISION, collisionSound, 2}};
    board->registerBoardCallback(collisionCallback);

    BoardCallbackPtr rowFullCallback{
        new SoundCallback{FULL_ROW, rowFullSound, 2}};
    board->registerBoardCallback(rowFullCallback);

    BoardCallbackPtr gameOverCallback{
        new SoundCallback{GAME_OVER, gameOverSound, 3}};
    board->registerBoardCallback(gameOverCallback);
}

Game::~Game() {
#ifndef NDEBUG
    std::cout << "Destroyed game" << std::endl;
#endif
}

void Game::nextMove() {
    board->nextMove();
    score.setValue(std::to_string(scorer->getScore()));
    level.setValue(std::to_string(scorer->getLevel()));
}

void Game::render(const Renderer& renderer) {
    boardRenderer.render(renderer);
    preview.render(renderer);
    score.render(renderer);
    level.render(renderer);
    nextTetrimino.render(renderer);

    if (board->isGameOver()) {
        gameOverText.render(renderer);
    }

#ifndef NDEBUG
    auto result = SDL_SetRenderDrawColor(renderer, white.red(), white.green(),
                                         white.blue(), white.alpha());
#endif
    assert(result == 0);

#ifndef NDEBUG
    result =
#endif
        SDL_RenderDrawLine(renderer, 110, 109, 200, 109);
    assert(result == 0);

#ifndef NDEBUG
    result =
#endif
        SDL_RenderDrawLine(renderer, 110, 390, 200, 390);
    assert(result == 0);

#ifndef NDEBUG
    result =
#endif
        SDL_RenderDrawLine(renderer, 400, 250, 490, 250);
    assert(result == 0);
}
