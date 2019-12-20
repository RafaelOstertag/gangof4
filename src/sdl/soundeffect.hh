#ifndef __SOUNDEFFECT_HH
#define __SOUNDEFFECT_HH

#include <SDL_mixer.h>
#include <memory>

class SoundEffect {
  public:
    virtual ~SoundEffect(){};

    virtual Mix_Chunk* getMixChunk() const = 0;
};

using SoundEffectPtr = std::shared_ptr<SoundEffect>;

#endif
