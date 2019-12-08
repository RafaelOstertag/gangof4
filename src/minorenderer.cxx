#include "minorenderer.hh"

#include <cassert>

void MinoRenderer::render(const Renderer& renderer) {
    auto x = referenceX + mino.x * width;
    auto y = referenceY + mino.y * width;

    SDL_Rect rectangle{x, y, width, width};

#ifndef NDEBUG
    auto result =
#endif
        SDL_SetRenderDrawColor(renderer, mino.color.red(), mino.color.green(),
                               mino.color.blue(), mino.color.alpha());
    assert(result == 0);

#ifndef NDEBUG
    result =
#endif
        SDL_RenderFillRect(renderer, &rectangle);
    assert(result == 0);
}
