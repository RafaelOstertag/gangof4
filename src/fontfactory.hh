#ifndef __FONTFACTORY_HH
#define __FONTFACTORY_HH

#include "font.hh"

#include <unordered_map>

class FontFactory {
  public:
    FontFactory();

    FontFactory(const FontFactory&) = delete;
    FontFactory& operator=(const FontFactory&) = delete;

    FontFactory(FontFactory&& o);
    FontFactory& operator=(FontFactory&& o);

    FontPtr createFont(int size);

  private:
    std::unordered_map<int, FontPtr> cache;
};

#endif
