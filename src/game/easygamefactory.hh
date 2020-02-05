#ifndef _EASYGAMEFACTORY_HH
#define _EASYGAMEFACTORY_HH

#include "gamefactory.hh"

class EasyGameFactory : public GameFactory {
  public:
    EasyGameFactory(const Window& window, FontFactory& fontFactory);
    virtual ~EasyGameFactory() = default;
    virtual GamePtr create();

  private:
    const Window& window;
    FontFactory& fontFactory;
};

#endif
