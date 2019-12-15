#include "soundfile.hh"

#include <sstream>
#include <stdexcept>

SoundFile::SoundFile(const std::string& filename) : chunk{nullptr} {
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

SoundFile::~SoundFile() {
    if (chunk != nullptr) {
        Mix_FreeChunk(chunk);
    }
}

SoundFile::SoundFile(SoundFile&& o) : chunk{o.chunk} { o.chunk = nullptr; }

SoundFile& SoundFile::operator=(SoundFile&& o) {
    if (chunk != nullptr) {
        Mix_FreeChunk(chunk);
    }
    
    chunk = o.chunk;
    o.chunk = nullptr;

    return *this;
}
