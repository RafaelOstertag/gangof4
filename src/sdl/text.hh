#ifndef __TEXT_HH
#define __TEXT_HH

#include "../sdl/color.hh"
#include "../sdl/font.hh"
#include "../sdl/renderable.hh"

#include <SDL.h>
#include <string>

class Text : public Renderable {
  public:
    Text(FontPtr font, int x, int y, const Color& color,
         const std::string& text = std ::string{});
    Text(const Text&) = delete;
    Text& operator=(const Text&) = delete;

    Text(Text&& o);
    Text& operator=(Text&& o);

    virtual ~Text();

    void setText(const std::string& text);

    virtual void render(const Renderer& renderer);

  private:
    FontPtr font;
    SDL_Texture* texture;
    Color color;
    std::string text;
    SDL_Rect rectangle;

    void destroyTexture();
    void textToTexture(const Renderer& renderer);
};

#endif
