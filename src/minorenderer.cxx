#include "minorenderer.hh"

#include <cassert>

void MinoRenderer::render(const Renderer& renderer) {
    auto x = referenceX + mino.getX() * width;
    auto y = referenceY + mino.getY() * width;

    SDL_Rect rectangle{x, y, width, width};

#ifndef NDEBUG
    auto result =
#endif
        SDL_SetRenderDrawColor(renderer, color.red(), color.green(),
                               color.blue(), color.alpha());
#ifndef NDEBUG
    assert(result == 0);
#endif

#ifndef NDEBUG
    result =
#endif
        SDL_RenderFillRect(renderer, &rectangle);
#ifndef NDEBUG
    assert(result == 0);
#endif
}
