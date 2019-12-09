#include "tetriminorenderer.hh"
#include "minorenderer.hh"

#include <cassert>

void TetriminoRenderer::render(const Renderer& renderer) {
    for (auto mino : tetrimino->getMinos()) {
        MinoRenderer minoRenderer{referenceX, referenceY, width, mino,
                                  minoTextureStore};
        minoRenderer.render(renderer);
    }
}
