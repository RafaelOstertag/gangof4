#ifndef __CIRCULARTETRIMINOSTOCK_HH
#define __CIRCULARTETRIMINOSTOCK_HH

#include "tetriminostock.hh"
#include <array>

class CircularTetriminoStock : public TetriminoStock {
  public:
    CircularTetriminoStock();
    virtual ~CircularTetriminoStock() = default;

    virtual TetriminoPtr draw();
    virtual TetriminoPtr preview();

  private:
    static constexpr int NUMBER_OF_TETRIMINOS = 7;
    std::array<TetriminoPtr (*)(), NUMBER_OF_TETRIMINOS> factories;
    int selectedFactory;
};

#endif
