#ifndef __BOARDCALLBACK_HH
#define __BOARDCALLBACK_HH

#include "boardevent.hh"

#include <memory>

class Board;

class BoardCallback {
  public:
    virtual ~BoardCallback() = default;
    virtual void call(BoardEvent event, const Board& board) = 0;
};

using BoardCallbackPtr = std::shared_ptr<BoardCallback>;

#endif
