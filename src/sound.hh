#ifndef __SOUND_HH
#define __SOUND_HH

#include <SDL_mixer.h>

class Sound {
  public:
    virtual ~Sound(){};

    virtual Mix_Chunk* getMixChunk() const = 0;
};

#endif
