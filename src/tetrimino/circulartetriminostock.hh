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
    static constexpr int NUMBER_OF_TETRIMINOS = 7;
    std::array<std::shared_ptr<Tetrimino> (*)(), NUMBER_OF_TETRIMINOS>
        factories;
    int selectedFactory;
};

#endif
