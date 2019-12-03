#ifndef __MINORENDERER_HH
#define __MINORENDERER_HH

#include "mino.hh"
#include "color.hh"
#include "renderable.hh"

class MinoRenderer : public Renderable {
  public:
    MinoRenderer(int referenceX, int referenceY, int width,
                     const Color& color, const Mino& mino)
        : referenceX{referenceX}, referenceY{referenceY}, width{width},
          color{color}, mino{mino} {}
    virtual ~MinoRenderer(){};

    virtual void render(const Renderer& renderer);

  private:
    int referenceX;
    int referenceY;
    int width;
    Color color;
    Mino mino;
};

#endif
