#include "soundmemory.hh"
#include "memoryrwops.hh"

#include <sstream>
#include <stdexcept>

SoundMemory::SoundMemory(void* ptr, int size) {

    MemoryRWOps memoryRWOps{ptr, size};

    chunk = Mix_LoadWAV_RW(memoryRWOps.getRWOps(), 0);
    if (chunk == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Cannot load WAV from memory: ";
        errorMessage << Mix_GetError();

        throw std::invalid_argument(errorMessage.str());
    }
}

SoundMemory::~SoundMemory() {
    if (chunk != nullptr) {
        Mix_FreeChunk(chunk);
    }
}

SoundMemory::SoundMemory(SoundMemory&& o) : chunk{o.chunk} {
    o.chunk = nullptr;
}

SoundMemory& SoundMemory::operator=(SoundMemory&& o) {
    if (chunk != nullptr) {
        Mix_FreeChunk(chunk);
    }

    chunk = o.chunk;
    o.chunk = nullptr;

    return *this;
}
