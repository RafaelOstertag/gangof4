#ifndef __MINOTEXTURESTORE_HH
#define __MINOTEXTURESTORE_HH

#include "../sdl/renderer.hh"
#include "../sdl/texture.hh"
#include "minotexture.hh"

#include <memory>
#include <string>
#include <unordered_map>

class MinoTextureStore {
  public:
    MinoTextureStore() : store{} {}

    void loadTexture(MinoTexture minoTexture, const std::string& filename,
                     const Renderer& renderer);
    void loadTexture(MinoTexture minoTexture, void* ptr, int size,
                     const Renderer& renderer);

    std::shared_ptr<Texture> getTexture(MinoTexture minoTexture) {
        return store[minoTexture];
    }

  private:
    std::unordered_map<MinoTexture, std::shared_ptr<Texture>> store;
};

MinoTextureStore createMinoTextureStore(const Renderer& renderer);

#endif
