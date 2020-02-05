#ifndef _HARDGAMEFACTORY_HH
#define _HARDGAMEFACTORY_HH

#include "gamefactory.hh"

class HardGameFactory : public GameFactory {
  public:
    HardGameFactory(const Window& window, FontFactory& fontFactory);
    virtual ~HardGameFactory() = default;
    virtual GamePtr create();

  private:
    const Window& window;
    FontFactory& fontFactory;
};

#endif
