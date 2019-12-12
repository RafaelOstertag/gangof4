#include "minotexturestore.hh"

void MinoTextureStore::loadTexture(MinoTexture minoTexture,
                                   const std::string& filename,
                                   const Renderer& renderer) {
    std::shared_ptr<Texture> texture{new Texture{filename, renderer}};

    store[minoTexture] = texture;
}

//
// Factory
//

MinoTextureStore createMinoTextureStore(const Renderer& renderer) {
    MinoTextureStore textureStore{};

    textureStore.loadTexture(CYAN, "resources/cyanmino.bmp", renderer);
    textureStore.loadTexture(RED, "resources/redmino.bmp", renderer);
    textureStore.loadTexture(YELLOW, "resources/yellowmino.bmp", renderer);
    textureStore.loadTexture(PURPLE, "resources/purplemino.bmp", renderer);
    textureStore.loadTexture(BLUE, "resources/bluemino.bmp", renderer);
    textureStore.loadTexture(GREEN, "resources/greenmino.bmp", renderer);
    textureStore.loadTexture(ORANGE, "resources/orangemino.bmp", renderer);

    return textureStore;
}
