#include "randomtetriminostock.hh"

#include <ctime>

RandomTetriminoStock::RandomTetriminoStock()
    : factories{}, prefetch{nullptr}, random{std::bind(
                                          std::uniform_int_distribution<>{
                                              0, NUMBER_OF_TETRIMINOS - 1},
                                          std::mt19937(std::time(nullptr)))},
      previousTetriminoFactoryIndex{-1} {
    factories[0] = createITetrimino;
    factories[1] = createJTetrimino;
    factories[2] = createLTetrimino;
    factories[3] = createOTetrimino;
    factories[4] = createTTetrimino;
    factories[5] = createSTetrimino;
    factories[6] = createZTetrimino;

    prefetch = randomTetrimino();
}

TetriminoPtr RandomTetriminoStock::draw() {
    auto tetrimino = prefetch;
    prefetch = randomTetrimino();
    return tetrimino;
}

TetriminoPtr RandomTetriminoStock::preview() { return prefetch; }

TetriminoPtr RandomTetriminoStock::randomTetrimino() {
    auto factoryIndex = random();

    while (previousTetriminoFactoryIndex == factoryIndex) {
        factoryIndex = random();
    }

    previousTetriminoFactoryIndex = factoryIndex;
    return factories[factoryIndex]();
}
