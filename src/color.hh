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

const Color magenta{0xff, 0x0, 0xff, 0x80};
const Color blue{0x0, 0x0, 0xff, 0x80};
const Color orange{0xff, 0xa5, 0x0, 0x80};
const Color yellow{0xff, 0xff, 0x0, 0x80};
const Color green{0x0, 0xff, 0x0, 0x80};
const Color purple{0x80, 0x0, 0x80, 0x80};
const Color red{0xff, 0x0, 0x0, 0x80};
const Color black{0x0, 0x0, 0x0, 0x80};
const Color white{0xff, 0xff, 0xff, 0x80};
const Color grey{0x70, 0x70, 0x70, 0x30};

#endif
