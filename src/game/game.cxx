#include "game.hh"
#include "../sdl/fontfactory.hh"
#include "../sdl/soundchannel.hh"
#include "../sdl/soundmemory.hh"
#include "../tetrimino/tetriminostock.hh"
#include "collision.hh"
#include "gameover.hh"
#include "move.hh"
#include "rotate.hh"
#include "rowfull.hh"

#include <cassert>
#include <iostream>

Game::Game(const Window& window, FontFactory& fontFactory,
           TetriminoStockPtr tetriminoStock, ScorerPtr scorer)
    : tetriminoStock{tetriminoStock}, scorer{scorer}, board{new Board{
                                                          tetriminoStock, WHITE,
                                                          scorer}},
      score{"SCORE",    std::to_string(scorer->getScore()), WHITE, 10, 10,
            fontFactory},
      level{"LEVEL",    std::to_string(scorer->getLevel()), WHITE, 10, 390,
            fontFactory},
      nextTetrimino{fontFactory.createFont(NORMAL), 490, 170, WHITE, "NEXT"},
      gameOverText{fontFactory.createFont(BIG), 232, 200, WHITE, "GAME OVER"},
      minoTextureStore{createMinoTextureStore(window.getRenderer())},
      boardRenderer{200, 10, board, minoTextureStore}, preview{490, 200,
                                                               tetriminoStock,
                                                               minoTextureStore,
                                                               WHITE} {

    SoundEffectPtr rotateSound{new SoundMemory{rotateWAV.data, rotateWAV.size}};
    BoardCallbackPtr rotateCallback{
        new SoundCallback{ROTATE, rotateSound, TWO}};
    board->registerBoardCallback(rotateCallback);

    SoundEffectPtr moveSound{new SoundMemory{moveWAV.data, moveWAV.size}};
    BoardCallbackPtr moveDownCallback{
        new SoundCallback{MOVE_DOWN, moveSound, ONE}};
    board->registerBoardCallback(moveDownCallback);

    BoardCallbackPtr moveRightCallback{
        new SoundCallback{MOVE_RIGHT, moveSound, ONE}};
    board->registerBoardCallback(moveRightCallback);

    BoardCallbackPtr moveLeftCallback{
        new SoundCallback{MOVE_LEFT, moveSound, ONE}};
    board->registerBoardCallback(moveLeftCallback);

    SoundEffectPtr collisionSound{
        new SoundMemory{collisionWAV.data, collisionWAV.size}};
    BoardCallbackPtr collisionCallback{
        new SoundCallback{COLLISION, collisionSound, THREE}};
    board->registerBoardCallback(collisionCallback);

    SoundEffectPtr rowFullSound{
        new SoundMemory{rowFullWAV.data, rowFullWAV.size}};
    BoardCallbackPtr rowFullCallback{
        new SoundCallback{FULL_ROW, rowFullSound, THREE}};
    board->registerBoardCallback(rowFullCallback);

    SoundEffectPtr gameOverSound{
        new SoundMemory{gameOverWAV.data, gameOverWAV.size}};
    BoardCallbackPtr gameOverCallback{
        new SoundCallback{GAME_OVER, gameOverSound, FOUR}};
    board->registerBoardCallback(gameOverCallback);

#ifndef NDEBUG
    std::cout << "Initialized game" << std::endl;
#endif
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
    auto result = SDL_SetRenderDrawColor(renderer, WHITE.red(), WHITE.green(),
                                         WHITE.blue(), WHITE.alpha());
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
