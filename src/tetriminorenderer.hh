#ifndef __TETRIMINORENDERER_HH
#define __TETRIMINORENDERER_HH

#include "color.hh"
#include "renderable.hh"
#include "tetrimino.hh"

class TetriminoRenderer : public Renderable {
  public:
    TetriminoRenderer(int referenceX, int referenceY, const Color& color,
                      std::shared_ptr<Tetrimino> tetrimino)
        : referenceX{referenceX},
          referenceY{referenceY}, color{color}, tetrimino{tetrimino} {}
    virtual ~TetriminoRenderer() {}

    virtual void render(const Renderer& renderer);

  private:
    int referenceX;
    int referenceY;
    Color color;
    std::shared_ptr<Tetrimino> tetrimino;
    static constexpr int width = 20;
};

#endif
