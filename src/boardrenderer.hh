#ifndef __BOARDRENDERER_HH
#define __BOARDRENDERER_HH

#include "board.hh"
#include "color.hh"
#include "renderable.hh"

#include <memory>

class BoardRenderer : public Renderable {
  public:
    BoardRenderer(std::shared_ptr<Board> board);
    virtual ~BoardRenderer() {}

    virtual void render(const Renderer& renderer);

  private:
    static constexpr int referenceX = 100;
    static constexpr int referenceY = 10;
    std::shared_ptr<Board> board;
    Color tetriminoColor;
    SDL_Rect boardOutline;
};

#endif
