#include "boardrenderer.hh"
#include "tetriminorenderer.hh"

#include <cassert>

BoardRenderer::BoardRenderer(std::shared_ptr<Board> board)
    : board{board}, tetriminoColor{0x7f, 0x7f, 0x7f, 0x0} {
    boardOutline = SDL_Rect{referenceX, referenceY,
                            TetriminoRenderer::width * Board::width,
                            TetriminoRenderer::width * Board::height};
}

void BoardRenderer::render(const Renderer& renderer) {
    assert(board->currentTetrimino);

    TetriminoRenderer tetriminoRenderer{referenceX, referenceY, tetriminoColor,
                                        board->currentTetrimino};
    tetriminoRenderer.render(renderer);

    for (auto tetrimino : board->tetrimios) {
        TetriminoRenderer tetriminoRenderer{referenceX, referenceY,
                                            tetriminoColor, tetrimino};
        tetriminoRenderer.render(renderer);
    }

#ifndef NDEBUG
    auto result =
#endif
        SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
    assert(result == 0);

#ifndef NDEBUG
    result =
#endif
        SDL_RenderDrawRect(renderer, &boardOutline);
    assert(result == 0);
}
