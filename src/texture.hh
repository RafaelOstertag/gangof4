#ifndef __TEXTURE_HH
#define __TEXTURE_HH

#include "renderer.hh"
#include <SDL.h>
#include <string>

class Texture {
  public:
    Texture(const std::string& filename, const Renderer& renderer);
    ~Texture();

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    Texture(Texture&& other);
    Texture& operator=(Texture&& other);

    constexpr SDL_Texture* get() const { return texture; }

  private:
    SDL_Texture* texture;
};

#endif
