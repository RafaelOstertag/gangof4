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
    virtual std::shared_ptr<Tetrimino> draw();
    virtual std::shared_ptr<Tetrimino> preview();

  private:
    static constexpr int NUMBER_OF_TETRIMINOS = 7;
    std::array<std::shared_ptr<Tetrimino> (*)(), NUMBER_OF_TETRIMINOS> factories;
    std::shared_ptr<Tetrimino> prefetch;
    std::function<int()> random;

    std::shared_ptr<Tetrimino> randomTetrimino();
};

#endif
