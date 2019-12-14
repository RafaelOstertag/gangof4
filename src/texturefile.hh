#ifndef __TEXTUREFILE_HH
#define __TEXTUREFILE_HH

#include "renderer.hh"
#include "texture.hh"
#include <string>

class TextureFile : public Texture {
  public:
    TextureFile(const std::string& filename, const Renderer& renderer);
    virtual ~TextureFile();

    TextureFile(const TextureFile&) = delete;
    TextureFile& operator=(const TextureFile&) = delete;

    TextureFile(TextureFile&& other);
    TextureFile& operator=(TextureFile&& other);

    virtual SDL_Texture* getTexture() { return texture; }

  private:
    SDL_Texture* texture;
};

#endif
