#include "texturememory.hh"
#include "memoryrwops.hh"

#include <sstream>
#include <stdexcept>

TextureMemory::TextureMemory(void* ptr, int size, const Renderer& renderer)
    : texture{nullptr} {

    MemoryRWOps memoryRWOps{ptr, size};

    auto bitmapSurface = SDL_LoadBMP_RW(memoryRWOps.getRWOps(), 0);
    if (bitmapSurface == nullptr) {
        std::ostringstream errorMessage;
        errorMessage << "Error loading bitmap from memory: " << SDL_GetError();

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

TextureMemory::TextureMemory(TextureMemory&& other) : texture{other.texture} {
    other.texture = nullptr;
}

TextureMemory& TextureMemory::operator=(TextureMemory&& other) {
    destroyTexture();

    texture = other.texture;
    other.texture = nullptr;

    return *this;
}

TextureMemory::~TextureMemory() { destroyTexture(); }

void TextureMemory::destroyTexture() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
