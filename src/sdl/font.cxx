#include "font.hh"

#include <SDL.h>
#include <stdexcept>
#include <string>

Font::Font(void* ptr, int memsize, int size)
    : memoryFont{ptr, memsize}, ttfFont{nullptr} {
    ttfFont = TTF_OpenFontRW(memoryFont.getRWOps(), 0, size);
    if (ttfFont == nullptr) {
        std::string errmsg{"Cannot load font: "};
        throw std::invalid_argument(errmsg + SDL_GetError());
    }
}

Font::~Font() { destroyFont(); }

Font::Font(Font&& o) : memoryFont{std::move(o.memoryFont)}, ttfFont{o.ttfFont} {
    o.ttfFont = nullptr;
}

Font& Font::operator=(Font&& o) {
    memoryFont = std::move(o.memoryFont);

    destroyFont();

    ttfFont = o.ttfFont;
    o.ttfFont = nullptr;

    return *this;
}

void Font::destroyFont() {
    if (ttfFont != nullptr) {
        TTF_CloseFont(ttfFont);
        ttfFont = nullptr;
    }
}
