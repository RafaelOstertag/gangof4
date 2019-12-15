#include "memoryrwops.hh"

#include <sstream>

MemoryRWOps::MemoryRWOps(void* ptr, int size) : memRWOps{nullptr} {
    memRWOps = SDL_RWFromMem(ptr, size);
    if (memRWOps == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Cannot create RWOps from memory: " << SDL_GetError();
        throw std::runtime_error(errorMessage.str());
    }
}

MemoryRWOps::~MemoryRWOps() {
    if (memRWOps != nullptr) {
        SDL_FreeRW(memRWOps);
    }
}

MemoryRWOps::MemoryRWOps(MemoryRWOps&& o) : memRWOps{o.memRWOps} {
    o.memRWOps = nullptr;
}

MemoryRWOps& MemoryRWOps::operator=(MemoryRWOps&& o) {
    if (memRWOps != nullptr) {
        SDL_FreeRW(memRWOps);
    }

    memRWOps = o.memRWOps;
    o.memRWOps = nullptr;

    return *this;
}
