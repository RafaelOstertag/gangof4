#ifndef __SOUNDEFFECT_HH
#define __SOUNDEFFECT_HH

#include <SDL_mixer.h>

class SoundEffect {
  public:
    virtual ~SoundEffect(){};

    virtual Mix_Chunk* getMixChunk() const = 0;
};

#endif
