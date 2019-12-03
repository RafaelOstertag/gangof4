#include "tetriminorenderer.hh"
#include "minorenderer.hh"

void TetriminoRenderer::render(const Renderer& renderer) {
    for (auto mino : tetrimino->getMinos()) {
        MinoRenderer minoRenderer{referenceX, referenceY, width, color,
                                          mino};
        minoRenderer.render(renderer);
    }
}
