#include "normaltetriminostock.hh"

#include <cassert>
#include <ctime>
#ifndef NDEBUG
#include <iomanip>
#include <iostream>
#endif

NormalTetriminoStock::NormalTetriminoStock()
    : factories{}, prefetch{nullptr}, random {
    std::bind(std::normal_distribution<double>{3.5, 1},
              std::default_random_engine(std::time(nullptr)))
}
#ifndef NDEBUG
, distribution {}
#endif
{
    factories[0] = createITetrimino;
    factories[1] = createJTetrimino;
    factories[2] = createLTetrimino;
    factories[3] = createSTetrimino;
    factories[4] = createZTetrimino;
    factories[5] = createTTetrimino;
    factories[6] = createOTetrimino;

    prefetch = randomTetrimino();
}

#ifndef NDEBUG
NormalTetriminoStock::~NormalTetriminoStock() {
    std::cout << "\nTetrimino Distribution:\n";
    for (auto item : distribution) {
        std::cout << item.first << ": " << item.second << "\n";
    }
    std::cout << "\n";
}
#endif

std::shared_ptr<Tetrimino> NormalTetriminoStock::draw() {
    auto tetrimino = prefetch;
    prefetch = randomTetrimino();
    return tetrimino;
}

std::shared_ptr<Tetrimino> NormalTetriminoStock::preview() { return prefetch; }

std::shared_ptr<Tetrimino> NormalTetriminoStock::randomTetrimino() {
    auto factoryNumber = random();
    if (factoryNumber < 0) {
        factoryNumber *= -1;
    }
    if (factoryNumber >= NUMBER_OF_TETRIMINOS) {
        factoryNumber %= NUMBER_OF_TETRIMINOS;
    }

    assert(factoryNumber >= 0 && factoryNumber < NUMBER_OF_TETRIMINOS);
#ifndef NDEBUG
    std::cout << "Drew Tetrimino #" << factoryNumber << "\n";
#endif

#ifndef NDEBUG
    distribution[factoryNumber]++;
#endif

    return factories[factoryNumber]();
}
