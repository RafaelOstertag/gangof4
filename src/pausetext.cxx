#include "pausetext.hh"

PauseText::PauseText()
    : font25{new Font{"resources/lucidasansdemibold.ttf", 25}},
      message{font25, 154, 200, white, "Paused"}, rendered{false} {}

void PauseText::render(const Renderer& renderer) {
    if (rendered)
        return;

    message.render(renderer);
    rendered = true;
}
