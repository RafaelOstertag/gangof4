#ifndef __BOARDRENDERER_HH
#define __BOARDRENDERER_HH

#include "board.hh"
#include "color.hh"
#include "minotexturestore.hh"
#include "renderable.hh"

#include <memory>

class BoardRenderer : public Renderable {
  public:
    BoardRenderer(std::shared_ptr<Board> board,
                  const MinoTextureStore& minoTextureStore);
    virtual ~BoardRenderer() {}

    virtual void render(const Renderer& renderer);

  private:
    static constexpr int referenceX = 100;
    static constexpr int referenceY = 10;
    std::shared_ptr<Board> board;
    MinoTextureStore minoTextureStore;
    SDL_Rect boardOutline;
};

#endif
