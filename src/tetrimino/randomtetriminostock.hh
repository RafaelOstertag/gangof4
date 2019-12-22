#ifndef __RANDOMTETRIMINOSTOCK_HH
#define __RANDOMTETRIMINOSTOCK_HH

#include "tetriminostock.hh"

#include <array>
#include <functional>
#include <random>

class RandomTetriminoStock : public TetriminoStock {
  public:
    RandomTetriminoStock();
    virtual ~RandomTetriminoStock(){};
    virtual TetriminoPtr draw();
    virtual TetriminoPtr preview();

  private:
    static constexpr int NUMBER_OF_TETRIMINOS = 7;
    std::array<TetriminoPtr (*)(), NUMBER_OF_TETRIMINOS>
        factories;
    TetriminoPtr prefetch;
    std::function<int()> random;
    int previousTetriminoFactoryIndex;

    TetriminoPtr randomTetrimino();
};

#endif
