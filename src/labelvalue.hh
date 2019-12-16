#ifndef __LABELVALUE_HH
#define __LABELVALUE_HH

#include "color.hh"
#include "fontfactory.hh"
#include "renderable.hh"
#include "text.hh"

#include <string>

class LabelValue : public Renderable {
  public:
    LabelValue(const std::string& label, const std::string& initialValue,
               const Color& color, int x, int y, FontFactory& fontFactory);

    LabelValue(const LabelValue&) = delete;
    LabelValue& operator=(const LabelValue&) = delete;

    LabelValue(LabelValue&&) = delete;
    LabelValue& operator=(LabelValue&&) = delete;

    void setValue(const std::string& v) { value.setText(v); }

    virtual void render(const Renderer& renderer);

  private:
    Color color;
    Text label;
    Text value;
    SDL_Rect rectangle;
};

#endif
