#include "pausetext.hh"
#include "veramonobold.hh"

PauseText::PauseText()
    : font25{new Font{veraMonoBoldTTF.data, veraMonoBoldTTF.size, 25}},
      message{font25, 156, 200, white, "Paused"}, rendered{false} {}

void PauseText::render(const Renderer& renderer) {
    if (rendered)
        return;

    message.render(renderer);
    rendered = true;
}
