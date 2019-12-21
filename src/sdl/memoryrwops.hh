#ifndef __MEMORYRWOPS_HH
#define __MEMORYRWOPS_HH

#include <SDL.h>

class MemoryRWOps {
  public:
    MemoryRWOps(void* ptr, int size);
    ~MemoryRWOps();

    MemoryRWOps(const MemoryRWOps&) = delete;
    MemoryRWOps& operator=(const MemoryRWOps&) = delete;

    MemoryRWOps(MemoryRWOps&& o);
    MemoryRWOps& operator=(MemoryRWOps&& o);

    constexpr SDL_RWops* getRWOps() const { return memRWOps; }

  private:
    SDL_RWops* memRWOps;

    void destroyRWOps();
};

#endif
