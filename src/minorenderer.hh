#ifndef __MINORENDERER_HH
#define __MINORENDERER_HH

#include "color.hh"
#include "mino.hh"
#include "renderable.hh"

class MinoRenderer : public Renderable {
  public:
    MinoRenderer(int referenceX, int referenceY, int width, const Mino& mino)
        : referenceX{referenceX},
          referenceY{referenceY}, width{width}, mino{mino} {}
    virtual ~MinoRenderer(){};

    virtual void render(const Renderer& renderer);

  private:
    int referenceX;
    int referenceY;
    int width;
    Mino mino;
};

#endif
