#ifndef __WINDOW_HH
#define __WINDOW_HH

#include "color.hh"
#include "renderable.hh"
#include "renderer.hh"

#include <SDL.h>
#include <memory>
#include <string>

class Window {
  public:
    Window(const std::string& name, int width, int heigh, const Color& bgColor);
    ~Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&& o);
    Window& operator=(Window&&) = delete;

    void clear();
    void render(Renderable& renderable) const;
    void update() const;
    constexpr const Renderer& getRenderer() const { return renderer; }

  private:
    SDL_Window* sdlWindow;
    Renderer renderer;
    const Color& bgColor;
};

using WindowPtr = std::shared_ptr<Window>;

#endif
