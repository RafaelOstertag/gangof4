#include "boardrenderer.hh"
#include "../tetrimino/minorenderer.hh"
#include "../tetrimino/tetriminorenderer.hh"

#include <cassert>

BoardRenderer::BoardRenderer(int referenceX, int referenceY,
                             std::shared_ptr<Board> board,
                             const MinoTextureStore& minoTextureStore)
    : board{board}, minoTextureStore{minoTextureStore}, boardOutline{},
      referenceX{referenceX}, referenceY{referenceY} {
    boardOutline = SDL_Rect{referenceX, referenceY,
                            TetriminoRenderer::width * Board::WIDTH_IN_MINOS,
                            TetriminoRenderer::width * Board::HEIGHT_IN_MINOS};
}

void BoardRenderer::render(const Renderer& renderer) {
    assert(board->currentTetrimino);

#ifndef NDEBUG
    auto result =
#endif
        SDL_SetRenderDrawColor(renderer, board->color.red(),
                               board->color.green(), board->color.blue(),
                               board->color.alpha());
    assert(result == 0);

#ifndef NDEBUG
    result =
#endif
        SDL_RenderDrawRect(renderer, &boardOutline);
    assert(result == 0);

    TetriminoRenderer tetriminoRenderer{
        referenceX, referenceY, minoTextureStore, board->currentTetrimino};
    tetriminoRenderer.render(renderer);

    for (auto mino : board->minos) {
        MinoRenderer minoRenderer{referenceX, referenceY,
                                  TetriminoRenderer::width, *mino,
                                  minoTextureStore};

        minoRenderer.render(renderer);
    }
}
