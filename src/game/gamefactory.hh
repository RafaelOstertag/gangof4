#ifndef __GAMEFACTORY_HH
#define __GAMEFACTORY_HH

#include "game.hh"

class GameFactory {
  public:
    virtual ~GameFactory() = default;
    virtual GamePtr create() = 0;
};

#endif
