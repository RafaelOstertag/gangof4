#ifndef __TETRIMINOSTOCK_HH
#define __TETRIMINOSTOCK_HH

#include "tetrimino.hh"
#include <memory>

class TetriminoStock {
  public:
    virtual ~TetriminoStock(){};
    virtual TetriminoPtr draw() = 0;
    virtual TetriminoPtr preview() = 0;
};

using TetriminoStockPtr = std::shared_ptr<TetriminoStock>;

#endif
