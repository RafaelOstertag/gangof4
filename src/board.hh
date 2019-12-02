#ifndef __BOARD_HH
#define __BOARD_HH

#include "blocklet.hh"
#include <array>

class Board {
  private:
    static constexpr int height = 24;
    static constexpr int width = 10;
    std::array<std::array<Blocklet*, 10>, 24> board;
};

#endif
