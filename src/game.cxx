#include "game.hh"
#include "collision.hh"
#include "gameover.hh"
#include "move.hh"
#include "rotate.hh"
#include "rowfull.hh"
#include "veramonobold.hh"

#include <iostream>

Game::Game(const Window& window)
    : tetriminoStock{new NormalTetriminoStock{}},
      scorer{new Scorer{Board::width}}, board{new Board{tetriminoStock,
                                                        lightGrey, scorer}},
      font18{new Font{veraMonoBoldTTF.data, veraMonoBoldTTF.size, 18}},
      font25{new Font{veraMonoBoldTTF.data, veraMonoBoldTTF.size, 25}},
      scoreLabel{font18, 320, 200, white, "Score"},
      scoreText{font18, 320, 230, white, std::to_string(scorer->getScore())},
      levelLabel{font18, 320, 270, white, "Level"},
      levelText{font18, 320, 300, white, std::to_string(scorer->getLevel())},
      nextTetrimino{font18, 320, 10, white, "Next"}, gameOverText{font25, 132,
                                                                  200, white,
                                                                  "Game Over"},
      minoTextureStore{createMinoTextureStore(window.getRenderer())},
      boardRenderer{100, 10, board, minoTextureStore}, preview{320, 40,
                                                               tetriminoStock,
                                                               minoTextureStore,
                                                               lightGrey},
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
    scoreText.setText(std::to_string(scorer->getScore()));
    levelText.setText(std::to_string(scorer->getLevel()));
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
