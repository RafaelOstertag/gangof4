#ifndef __PREVIEW_HH
#define __PREVIEW_HH

#include "../sdl/color.hh"
#include "../sdl/renderable.hh"
#include "../tetrimino/minotexturestore.hh"
#include "../tetrimino/tetriminostock.hh"

class Preview : public Renderable {
  public:
    Preview(int x, int y, std::shared_ptr<TetriminoStock> tetriminoStock,
            const MinoTextureStore& minoTextureStore, const Color& color);
    virtual ~Preview(){};

    virtual void render(const Renderer& renderer);

  private:
    std::shared_ptr<TetriminoStock> tetriminoStock;
    MinoTextureStore minoTextureStore;
    Color color;
    SDL_Rect outline;
    int x;
    int y;
};

#endif
