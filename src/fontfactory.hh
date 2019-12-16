#ifndef __FONTFACTORY_HH
#define __FONTFACTORY_HH

#include "font.hh"
#include "fontsize.hh"

#include <unordered_map>

class FontFactory {
  public:
    FontFactory();

    FontFactory(const FontFactory&) = delete;
    FontFactory& operator=(const FontFactory&) = delete;

    FontFactory(FontFactory&& o);
    FontFactory& operator=(FontFactory&& o);

    FontPtr createFont(FontSize size);

  private:
    std::unordered_map<FontSize, FontPtr> cache;
};

#endif
