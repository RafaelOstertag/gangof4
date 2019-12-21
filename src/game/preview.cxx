#include "preview.hh"
#include "../tetrimino/tetriminorenderer.hh"

#include <cassert>

Preview::Preview(int x, int y, std::shared_ptr<TetriminoStock> tetriminoStock,
                 const MinoTextureStore& minoTextureStore, const Color& color)
    : tetriminoStock{tetriminoStock},
      minoTextureStore{minoTextureStore}, color{color}, outline{}, x{x}, y{y} {
    outline = SDL_Rect{x, y, 5 * TetriminoRenderer::width,
                       5 * TetriminoRenderer::width};
}

void Preview::render(const Renderer& renderer) {
    auto tetrimino = tetriminoStock->preview();

    // These offsets will center the preview Tetrimino
    int xOffset = (2.5 * TetriminoRenderer::width) -
                  ((tetrimino->maxX() + 1) * TetriminoRenderer::width / 2);
    int yOffset = (2.5 * TetriminoRenderer::width) -
                  ((tetrimino->maxY() + 1) * TetriminoRenderer::width / 2);

    TetriminoRenderer tetriminoRenderer{x + xOffset, y + yOffset,
                                        minoTextureStore, tetrimino};

    tetriminoRenderer.render(renderer);

#ifndef NDEBUG
    auto result =
#endif
        SDL_SetRenderDrawColor(renderer, color.red(), color.green(),
                               color.blue(), color.alpha());
    assert(result == 0);
#ifndef NDEBUG
    result =
#endif
        SDL_RenderDrawRect(renderer, &outline);
    assert(result == 0);
}
