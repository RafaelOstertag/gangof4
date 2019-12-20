#include "difficultyselector.hh"
#include "sdl/color.hh"
#include "tetrimino/minotexturestore.hh"
#include "tetrimino/tetriminorenderer.hh"

namespace {
constexpr int TEXT_X = 240;
constexpr int TEXT_Y_START = 120;
constexpr int TEXT_SPACING = 120;
constexpr int SELECTOR_X = 180;
constexpr int SELECTOR_Y_START = 105;
} // namespace

DifficultySelector::DifficultySelector(const Window& window,
                                       FontFactory& fontFactory)
    : difficulty{EASY}, minoTextureStore{createMinoTextureStore(
                            window.getRenderer())},
      selected{createTTetrimino()}, easyText{fontFactory.createFont(BIG),
                                             TEXT_X, TEXT_Y_START, WHITE,
                                             "EASY"},
      mediumText{fontFactory.createFont(BIG), TEXT_X,
                 TEXT_Y_START + TEXT_SPACING, WHITE, "MEDIUM"},
      hardText{fontFactory.createFont(BIG), TEXT_X,
               TEXT_Y_START + 2 * TEXT_SPACING, WHITE, "HARD"} {
    orientSelected();
}

void DifficultySelector::selectNextDifficulty() {
    switch (difficulty) {
    case EASY:
        difficulty = MEDIUM;
        break;
    case MEDIUM:
        difficulty = HARD;
        break;
    case HARD:
        difficulty = EASY;
        break;
    }
}

void DifficultySelector::selectPreviousDifficulty() {
    switch (difficulty) {
    case EASY:
        difficulty = HARD;
        break;
    case MEDIUM:
        difficulty = EASY;
        break;
    case HARD:
        difficulty = MEDIUM;
        break;
    }
}

void DifficultySelector::render(const Renderer& renderer) {
    easyText.render(renderer);
    mediumText.render(renderer);
    hardText.render(renderer);

    TetriminoRenderer tetriminoRenderer{
        SELECTOR_X, SELECTOR_Y_START + (difficulty * TEXT_SPACING),
        minoTextureStore, selected};
    tetriminoRenderer.render(renderer);
}

void DifficultySelector::orientSelected() { selected->rotateClockwise(); }
