#include "boardrenderer.hh"
#include "minorenderer.hh"
#include "tetriminorenderer.hh"

#include <cassert>

BoardRenderer::BoardRenderer(std::shared_ptr<Board> board,
                             const MinoTextureStore& minoTextureStore)
    : board{board}, minoTextureStore{minoTextureStore} {
    boardOutline = SDL_Rect{referenceX, referenceY,
                            TetriminoRenderer::width * Board::width,
                            TetriminoRenderer::width * Board::height};
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
        SDL_RenderFillRect(renderer, &boardOutline);
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
