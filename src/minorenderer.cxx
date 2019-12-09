#include "minorenderer.hh"

#include <SDL.h>
#include <cassert>

void MinoRenderer::render(const Renderer& renderer) {
    auto x = referenceX + mino.x * width;
    auto y = referenceY + mino.y * width;

    SDL_Rect rectangle{x, y, width, width};
    auto minoTexture = minoTextureStore.getTexture(mino.minoTexture);

#ifndef NDEBUG
    auto result =
#endif
        SDL_RenderCopy(renderer, minoTexture->get(), nullptr, &rectangle);
    assert(result == 0);
}
