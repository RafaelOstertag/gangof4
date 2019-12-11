#ifndef __TEXT_HH
#define __TEXT_HH

#include "color.hh"
#include "font.hh"
#include "renderable.hh"

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

    void freeTexture();
    void textToTexture(const Renderer& renderer);
};

#endif
