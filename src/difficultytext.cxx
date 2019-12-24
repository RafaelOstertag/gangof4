#include "difficultytext.hh"
#include <cassert>
#include <stdexcept>
#include <string>

namespace {
std::string difficultyToString(GameDifficulty gameDifficulty) {
    switch (gameDifficulty) {
    case HARD:
        return "HARD";
    case MEDIUM:
        return "MEDIUM";
    case EASY:
        return "EASY";
    }
#ifndef __clang__
    throw std::runtime_error("Unhandled switch value");
#endif
}
} // namespace

DifficultyText::DifficultyText(GameDifficulty gameDifficulty,
                               FontFactory& fontFactory)
    : message{fontFactory.createFont(NORMAL), 402, 15, WHITE,
              "DIFFICULTY " + difficultyToString(gameDifficulty)} {}

void DifficultyText::render(const Renderer& renderer) {
    message.render(renderer);

#ifndef NDEBUG
    auto result =
#endif
        SDL_SetRenderDrawColor(renderer, WHITE.red(), WHITE.green(),
                               WHITE.blue(), WHITE.alpha());
    assert(result == 0);

#ifndef NDEBUG
    result =
#endif
        SDL_RenderDrawLine(renderer, 400, 10, 590, 10);
}
