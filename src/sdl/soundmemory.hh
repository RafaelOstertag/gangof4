#ifndef __SOUNDMEMORY_HH
#define __SOUNDMEMORY_HH

#include "soundeffect.hh"

class SoundMemory : public SoundEffect {
  public:
    SoundMemory(void* ptr, int size);
    virtual ~SoundMemory();

    SoundMemory(const SoundMemory&) = delete;
    SoundMemory& operator=(const SoundMemory&) = delete;

    SoundMemory(SoundMemory&& o);
    SoundMemory& operator=(SoundMemory&& o);

    virtual Mix_Chunk* getMixChunk() const { return chunk; }

  private:
    Mix_Chunk* chunk;

    void destroyChunk();
};

#endif
