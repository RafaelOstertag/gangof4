#ifndef __NORMALTETRIMINOSTOCK_HH
#define __NORMALTETRIMINOSTOCK_HH

#include "tetriminostock.hh"

#include <array>
#include <functional>
#include <random>
#ifndef NDEBUG
#include <map>
#endif

/**
 * Produce Tetriminos randomly with normal distribution.
 */
class NormalTetriminoStock : public TetriminoStock {
  public:
    NormalTetriminoStock();
    virtual ~NormalTetriminoStock() {}

    virtual std::shared_ptr<Tetrimino> draw();
    virtual std::shared_ptr<Tetrimino> preview();

  private:
    static constexpr int I_TETRIMINO_AT_LEAST_EVERY = 10;
    static constexpr int NUMBER_OF_TETRIMINOS = 7;
    std::array<std::shared_ptr<Tetrimino> (*)(), NUMBER_OF_TETRIMINOS>
        factories;
    std::shared_ptr<Tetrimino> prefetch;
    std::function<int()> random;
    std::shared_ptr<Tetrimino> randomTetrimino();
    int lastFactoryNumber;
    int drawsSinceITetrimino;
};

#endif
