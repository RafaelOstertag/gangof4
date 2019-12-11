#include "normaltetriminostock.hh"

#include <ctime>

NormalTetriminoStock::NormalTetriminoStock()
    : factories{}, prefetch{nullptr},
      random{std::bind(std::normal_distribution<double>{3, 3},
                       std::default_random_engine(std::time(nullptr)))} {
    factories[0] = createITetrimino;
    factories[1] = createJTetrimino;
    factories[2] = createLTetrimino;
    factories[3] = createSTetrimino;
    factories[4] = createZTetrimino;
    factories[5] = createTTetrimino;
    factories[6] = createOTetrimino;

    prefetch = randomTetrimino();
}

std::shared_ptr<Tetrimino> NormalTetriminoStock::draw() {
    auto tetrimino = prefetch;
    prefetch = randomTetrimino();
    return tetrimino;
}

std::shared_ptr<Tetrimino> NormalTetriminoStock::preview() { return prefetch; }

std::shared_ptr<Tetrimino> NormalTetriminoStock::randomTetrimino() {
    auto factoryNumber = -1;

    while (factoryNumber < 0 || factoryNumber >= numberOfTetriminos) {
        factoryNumber = random();
    }

    return factories[factoryNumber]();
}
