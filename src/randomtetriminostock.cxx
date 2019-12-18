#include "randomtetriminostock.hh"

#include <ctime>

RandomTetriminoStock::RandomTetriminoStock()
    : factories{}, prefetch{nullptr},
      random{
          std::bind(std::uniform_int_distribution<>{0, NUMBER_OF_TETRIMINOS - 1},
                    std::default_random_engine(std::time(nullptr)))} {
    factories[0] = createITetrimino;
    factories[1] = createJTetrimino;
    factories[2] = createLTetrimino;
    factories[3] = createOTetrimino;
    factories[4] = createTTetrimino;
    factories[5] = createSTetrimino;
    factories[6] = createZTetrimino;

    prefetch = randomTetrimino();
}

std::shared_ptr<Tetrimino> RandomTetriminoStock::draw() {
    auto tetrimino = prefetch;
    prefetch = randomTetrimino();
    return tetrimino;
}

std::shared_ptr<Tetrimino> RandomTetriminoStock::preview() { return prefetch; }

std::shared_ptr<Tetrimino> RandomTetriminoStock::randomTetrimino() {
    auto factoryNumber = random();
    return factories[factoryNumber]();
}
