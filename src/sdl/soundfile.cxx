#include "soundfile.hh"
#include "sdl.hh"

#include <sstream>
#include <stdexcept>

SoundFile::SoundFile(const std::string& filename) : chunk{nullptr} {
    if (!SDL::hasSound()) {
        return;
    }

    chunk = Mix_LoadWAV(filename.c_str());
    if (chunk == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Cannot load WAV ";
        errorMessage << filename;
        errorMessage << ": ";
        errorMessage << Mix_GetError();

        throw std::invalid_argument(errorMessage.str());
    }
}

SoundFile::~SoundFile() { destroyChunk(); }

SoundFile::SoundFile(SoundFile&& o) : chunk{o.chunk} { o.chunk = nullptr; }

SoundFile& SoundFile::operator=(SoundFile&& o) {
    destroyChunk();

    chunk = o.chunk;
    o.chunk = nullptr;

    return *this;
}

void SoundFile::destroyChunk() {
    if (chunk != nullptr) {
        Mix_FreeChunk(chunk);
        chunk = nullptr;
    }
}
