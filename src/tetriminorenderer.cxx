#include "tetriminorenderer.hh"
#include "blockletrenderer.hh"

void TetriminoRenderer::render(const Renderer& renderer) {
    for (auto blocklet : tetrimino->getBlocklets()) {
        BlockletRenderer blockletRenderer{referenceX, referenceY, width, color,
                                          blocklet};
        blockletRenderer.render(renderer);
    }
}
