#include "fontfactory.hh"
#include "veramonobold.hh"

FontFactory::FontFactory() : cache{} {}

FontFactory::FontFactory(FontFactory&& o) : cache{std::move(o.cache)} {}

FontFactory& FontFactory::operator=(FontFactory&& o) {
    cache = std::move(o.cache);

    return *this;
}

FontPtr FontFactory::createFont(FontSize size) {
    auto font = cache[size];
    if (!font) {
        font =
            FontPtr{new Font(veraMonoBoldTTF.data, veraMonoBoldTTF.size, size)};
        cache[size] = font;
    }
    return font;
}
