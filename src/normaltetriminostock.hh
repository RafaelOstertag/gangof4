#ifndef __NORMALTETRIMINOSTOCK_HH
#define __NORMALTETRIMINOSTOCK_HH

#include "tetriminostock.hh"

#include <array>
#include <functional>
#include <random>

class NormalTetriminoStock : public TetriminoStock {
  public:
    NormalTetriminoStock();
    virtual ~NormalTetriminoStock(){};
    virtual std::shared_ptr<Tetrimino> draw();
    virtual std::shared_ptr<Tetrimino> preview();

  private:
    static constexpr int numberOfTetriminos = 7;
    std::array<std::shared_ptr<Tetrimino> (*)(), numberOfTetriminos> factories;
    std::shared_ptr<Tetrimino> prefetch;
    std::function<int()> random;

    std::shared_ptr<Tetrimino> randomTetrimino();
};


#endif
