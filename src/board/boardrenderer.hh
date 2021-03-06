#ifndef __BOARDRENDERER_HH
#define __BOARDRENDERER_HH

#include "../sdl/color.hh"
#include "../sdl/renderable.hh"
#include "../tetrimino/minotexturestore.hh"
#include "board.hh"

#include <memory>

class BoardRenderer : public Renderable {
  public:
    BoardRenderer(int referenceX, int referenceY, std::shared_ptr<Board> board,
                  const MinoTextureStore& minoTextureStore);
    virtual ~BoardRenderer() = default;

    virtual void render(const Renderer& renderer);

  private:
    std::shared_ptr<Board> board;
    MinoTextureStore minoTextureStore;
    SDL_Rect boardOutline;
    int referenceX;
    int referenceY;
};

#endif
