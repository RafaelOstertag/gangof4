#include "font.hh"

#include <SDL.h>
#include <stdexcept>

Font::Font(const std::string& ttfFilepath, int size) : ttfFont{nullptr} {
    ttfFont = TTF_OpenFont(ttfFilepath.c_str(), size);
    if (ttfFont == nullptr) {
        std::string errmsg{"Cannot load font: "};
        throw std::invalid_argument(errmsg + SDL_GetError());
    }
}

Font::~Font() {
    if (ttfFont != nullptr) {
        TTF_CloseFont(ttfFont);
    }
}

Font::Font(Font&& o) : ttfFont{o.ttfFont} { o.ttfFont = nullptr; }

Font& Font::operator=(Font&& o) {
    ttfFont = o.ttfFont;
    o.ttfFont = nullptr;

    return *this;
}
