#ifndef __TEXTUREMEMORY_HH
#define __TEXTUREMEMORY_HH

#include "renderer.hh"
#include "texture.hh"

class TextureMemory : public Texture {
  public:
    TextureMemory(void* ptr, int size, const Renderer& renderer);
    virtual ~TextureMemory();

    TextureMemory(const TextureMemory&) = delete;
    TextureMemory& operator=(const TextureMemory&) = delete;

    TextureMemory(TextureMemory&& other);
    TextureMemory& operator=(TextureMemory&& other);

    virtual SDL_Texture* getTexture() { return texture; }

  private:
    SDL_Texture* texture;

    void destroyTexture();
};

#endif
