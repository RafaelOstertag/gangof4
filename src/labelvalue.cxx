#include "labelvalue.hh"
#include "fontfactory.hh"

#include <cassert>

LabelValue::LabelValue(const std::string& label,
                       const std::string& initialValue, const Color& color,
                       int x, int y, FontFactory& fontFactory)
    : color{color}, label{fontFactory.createFont(18), x + 20, y + 20,
                          color, label},
      value{fontFactory.createFont(18), x + 20, y + 50, color,
            initialValue},
      rectangle{x, y, 100, 100} {}

void LabelValue::render(const Renderer& renderer) {
#ifndef NDEBUG
    auto result =
#endif
        SDL_SetRenderDrawColor(renderer, color.red(), color.green(),
                               color.blue(), color.alpha());
    assert(result == 0);

#ifndef NDEBUG
    result =
#endif
        SDL_RenderDrawRect(renderer, &rectangle);

    label.render(renderer);
    value.render(renderer);
}
