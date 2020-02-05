#ifndef __TETRIMINORENDERER_HH
#define __TETRIMINORENDERER_HH

#include "../sdl/renderable.hh"
#include "minotexturestore.hh"
#include "tetrimino.hh"

class TetriminoRenderer : public Renderable {
  public:
    static constexpr int width = 20;

    TetriminoRenderer(int referenceX, int referenceY,
                      const MinoTextureStore& minoTextureStore,
                      TetriminoPtr tetrimino)
        : referenceX{referenceX}, referenceY{referenceY},
          minoTextureStore{minoTextureStore}, tetrimino{tetrimino} {}
    virtual ~TetriminoRenderer() = default;

    virtual void render(const Renderer& renderer);

  private:
    int referenceX;
    int referenceY;
    MinoTextureStore minoTextureStore;
    TetriminoPtr tetrimino;
};

#endif
