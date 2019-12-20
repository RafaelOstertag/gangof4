#ifndef __TETRIMINOSTOCK_HH
#define __TETRIMINOSTOCK_HH

#include "tetrimino.hh"
#include <memory>

class TetriminoStock {
  public:
    virtual ~TetriminoStock(){};
    virtual std::shared_ptr<Tetrimino> draw() = 0;
    virtual std::shared_ptr<Tetrimino> preview() = 0;
};

using TetriminoStockPtr = std::shared_ptr<TetriminoStock>;

#endif
