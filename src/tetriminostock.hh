#ifndef __TETRIMINOSTOCK_HH
#define __TETRIMINOSTOCK_HH

#include "tetrimino.hh"
#include <array>

class TetriminoStock {
  public:
    TetriminoStock();
    std::shared_ptr<Tetrimino> draw();

  private:
    static constexpr int numberOfTetriminos = 7;
    std::array<std::shared_ptr<Tetrimino> (*)(), numberOfTetriminos> factories;
    int selectedFactory;
};

#endif
