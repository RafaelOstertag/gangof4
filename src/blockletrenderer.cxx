#include "blockletrenderer.hh"

#include <cassert>

void BlockletRenderer::render(const Renderer& renderer) {
    auto x = referenceX + blocklet.getX() * width;
    auto y = referenceY + blocklet.getY() * width;

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
