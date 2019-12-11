#ifndef __BOARDRENDERER_HH
#define __BOARDRENDERER_HH

#include "board.hh"
#include "color.hh"
#include "minotexturestore.hh"
#include "renderable.hh"

#include <memory>

class BoardRenderer : public Renderable {
  public:
    BoardRenderer(int referenceX, int referenceY, std::shared_ptr<Board> board,
                  const MinoTextureStore& minoTextureStore);
    virtual ~BoardRenderer() {}

    virtual void render(const Renderer& renderer);

  private:
    std::shared_ptr<Board> board;
    MinoTextureStore minoTextureStore;
    SDL_Rect boardOutline;
    int referenceX;
    int referenceY;
};

#endif
