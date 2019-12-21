#ifndef __FONT_HH
#define __FONT_HH

#include "memoryrwops.hh"

#include <SDL_ttf.h>
#include <memory>
#include <string>

class Font {
  public:
    Font(void* ptr, int memsize, int size);
    ~Font();
    Font(const Font&) = delete;
    Font& operator=(const Font&) = delete;

    Font(Font&& other);
    Font& operator=(Font&& other);

    constexpr TTF_Font* getFont() const { return ttfFont; }

  private:
    MemoryRWOps memoryFont;
    TTF_Font* ttfFont;

    void destroyFont();
};

using FontPtr = std::shared_ptr<Font>;

#endif
