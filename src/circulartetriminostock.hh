#ifndef __CIRCULARTETRIMINOSTOCK_HH
#define __CIRCULARTETRIMINOSTOCK_HH

#include "tetriminostock.hh"
#include <array>

class CircularTetriminoStock : public TetriminoStock {
  public:
    CircularTetriminoStock();
    virtual ~CircularTetriminoStock() {}

    virtual std::shared_ptr<Tetrimino> draw();
    virtual std::shared_ptr<Tetrimino> preview();

  private:
    static constexpr int numberOfTetriminos = 7;
    std::array<std::shared_ptr<Tetrimino> (*)(), numberOfTetriminos> factories;
    int selectedFactory;
};

#endif
