#include "minotexturestore.hh"
#include "../sdl/texturefile.hh"
#include "../sdl/texturememory.hh"
#include "bluemino.hh"
#include "cyanmino.hh"
#include "greenmino.hh"
#include "orangemino.hh"
#include "purplemino.hh"
#include "redmino.hh"
#include "yellowmino.hh"

void MinoTextureStore::loadTexture(MinoTexture minoTexture,
                                   const std::string& filename,
                                   const Renderer& renderer) {
    std::shared_ptr<Texture> texture{new TextureFile{filename, renderer}};

    store[minoTexture] = texture;
}

void MinoTextureStore::loadTexture(MinoTexture minoTexture, void* ptr, int size,
                                   const Renderer& renderer) {
    std::shared_ptr<Texture> texture{new TextureMemory(ptr, size, renderer)};

    store[minoTexture] = texture;
}

//
// Factory
//

MinoTextureStore createMinoTextureStore(const Renderer& renderer) {
    MinoTextureStore textureStore{};

    textureStore.loadTexture(CYAN, cyanMinoBMP.data, cyanMinoBMP.size,
                             renderer);
    textureStore.loadTexture(RED, redMinoBMP.data, redMinoBMP.size, renderer);
    textureStore.loadTexture(YELLOW, yellowMinoBMP.data, yellowMinoBMP.size,
                             renderer);
    textureStore.loadTexture(PURPLE, purpleMinoBMP.data, purpleMinoBMP.size,
                             renderer);
    textureStore.loadTexture(BLUE, blueMinoBMP.data, blueMinoBMP.size,
                             renderer);
    textureStore.loadTexture(GREEN, greenMinoBMP.data, greenMinoBMP.size,
                             renderer);
    textureStore.loadTexture(ORANGE, orangeMinoBMP.data, orangeMinoBMP.size,
                             renderer);

    return textureStore;
}
