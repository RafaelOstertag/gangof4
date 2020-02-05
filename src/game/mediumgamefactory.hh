#ifndef _MEDIUMGAMEFACTORY_HH
#define _MEDIUMGAMEFACTORY_HH

#include "gamefactory.hh"

class MediumGameFactory : public GameFactory {
  public:
    MediumGameFactory(const Window& window, FontFactory& fontFactory);
    virtual ~MediumGameFactory() = default;
    virtual GamePtr create();

  private:
    const Window& window;
    FontFactory& fontFactory;
};

#endif
