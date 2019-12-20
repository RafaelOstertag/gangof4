#ifndef __RENDERER_HH
#define __RENDERER_HH

#include <SDL.h>

class Renderer {
  public:
    Renderer(SDL_Renderer* renderer = nullptr);
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&&);
    Renderer& operator=(Renderer&& o);

    constexpr operator SDL_Renderer*() const { return sdlRenderer; }

  private:
    SDL_Renderer* sdlRenderer;

    void destroyRenderer();
};

#endif
