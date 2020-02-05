#ifndef __TEXTURE_HH
#define __TEXTURE_HH

#include <SDL.h>

class Texture {
  public:
    virtual ~Texture() = default;

    virtual SDL_Texture* getTexture() = 0;
};

#endif
