#include "pausetext.hh"

PauseText::PauseText(FontFactory& fontFactory)
    : message{fontFactory.createFont(BIG), 255, 200, WHITE, "PAUSED"},
      rendered{false} {}

void PauseText::render(const Renderer& renderer) {
    if (rendered)
        return;

    message.render(renderer);
    rendered = true;
}
