#ifndef __HARDTETRIMINOSTOCK_HH
#define __HARDTETRIMINOSTOCK_HH

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
class HardTetriminoStock : public TetriminoStock {
  public:
    HardTetriminoStock();
    virtual ~HardTetriminoStock() = default;

    virtual TetriminoPtr draw();
    virtual TetriminoPtr preview();

  private:
    static constexpr int I_TETRIMINO_AT_LEAST_EVERY = 10;
    static constexpr int NUMBER_OF_TETRIMINOS = 7;
    std::array<TetriminoPtr (*)(), NUMBER_OF_TETRIMINOS> factories;
    TetriminoPtr prefetch;
    std::function<int()> random;
    TetriminoPtr randomTetrimino();
    int lastFactoryNumber;
    int drawsSinceITetrimino;
};

#endif
