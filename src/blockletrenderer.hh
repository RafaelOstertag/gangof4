#ifndef __BLOCKLETRENDERER_HH
#define __BLOCKLETRENDERER_HH

#include "blocklet.hh"
#include "color.hh"
#include "renderable.hh"

class BlockletRenderer : public Renderable {
  public:
    BlockletRenderer(int referenceX, int referenceY, int width,
                     const Color& color, const Blocklet& blocklet)
        : referenceX{referenceX}, referenceY{referenceY}, width{width},
          color{color}, blocklet{blocklet} {}
    virtual ~BlockletRenderer(){};

    virtual void render(const Renderer& renderer);

  private:
    int referenceX;
    int referenceY;
    int width;
    Color color;
    Blocklet blocklet;
};

#endif
