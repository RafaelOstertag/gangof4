#ifndef __FONT_HH
#define __FONT_HH

#include <SDL_ttf.h>
#include <memory>
#include <string>

class Font {
  public:
    Font(const std::string& ttfFilepath, int size);
    ~Font();
    Font(const Font&) = delete;
    Font& operator=(const Font&) = delete;

    Font(Font&& other);
    Font& operator=(Font&& other);

    constexpr TTF_Font* getFont() const { return ttfFont; }

  private:
    TTF_Font* ttfFont;
};

using FontPtr = std::shared_ptr<Font>;

#endif
