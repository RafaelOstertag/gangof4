#ifndef __SOUNDFILE_HH
#define __SOUNDFILE_HH

#include <SDL_mixer.h>
#include <string>

class SoundFile {
  public:
    SoundFile(const std::string& filename);
    ~SoundFile();

    SoundFile(const SoundFile&) = delete;
    SoundFile& operator=(const SoundFile&) = delete;

    SoundFile(SoundFile&& o);
    SoundFile& operator=(SoundFile&& o);

    Mix_Chunk* getMixChunk() { return chunk; }

  private:
    Mix_Chunk* chunk;
};

#endif
