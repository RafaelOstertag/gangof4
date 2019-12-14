#include "texturefile.hh"

#include <sstream>
#include <stdexcept>

TextureFile::TextureFile(const std::string& filename, const Renderer& renderer)
    : texture{nullptr} {
    auto bitmapSurface = SDL_LoadBMP(filename.c_str());
    if (bitmapSurface == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Error loading " << filename << ": " << SDL_GetError();

        throw std::invalid_argument(errorMessage.str());
    }

    texture = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    if (texture == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Cannot convert surface to texture: " << SDL_GetError();

        throw std::invalid_argument(errorMessage.str());
    }

    SDL_FreeSurface(bitmapSurface);
}

TextureFile::TextureFile(TextureFile&& other) : texture{other.texture} {
    other.texture = nullptr;
}

TextureFile& TextureFile::operator=(TextureFile&& other) {
    texture = other.texture;
    other.texture = nullptr;

    return *this;
}

TextureFile::~TextureFile() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}
