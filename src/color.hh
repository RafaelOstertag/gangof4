#ifndef __COLOR_HH
#define __COLOR_HH

#include <SDL.h>

class Color {
  public:
    Color(unsigned char red = 0, unsigned char green = 0,
          unsigned char blue = 0, unsigned char alpha = 0)
        : sdlColor{red, green, blue, alpha} {}

    unsigned char red() const { return sdlColor.r; }
    unsigned char green() const { return sdlColor.g; }
    unsigned char blue() const { return sdlColor.b; }
    unsigned char alpha() const { return sdlColor.a; }

    operator const SDL_Color*() const { return &sdlColor; }
    operator SDL_Color() const { return sdlColor; }

  private:
    SDL_Color sdlColor;
};

const Color black{0x0, 0x0, 0x0, 0x0};
const Color white{0xff, 0xff, 0xff, 0x0};
const Color grey{0x70, 0x70, 0x70, 0x0};
const Color darkGrey{0x2d, 0x2d, 0x2d, 0x0};
const Color lightGrey{0xcc, 0xcc, 0xcc, 0x0};

#endif
