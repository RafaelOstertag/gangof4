#include "renderer.hh"

Renderer::Renderer(SDL_Renderer* renderer) : sdlRenderer{renderer} {}

Renderer::~Renderer() { destroyRenderer(); }

Renderer::Renderer(Renderer&& o) : sdlRenderer{o.sdlRenderer} {
    o.sdlRenderer = nullptr;
}

Renderer& Renderer::operator=(Renderer&& o) {
    destroyRenderer();

    sdlRenderer = o.sdlRenderer;
    o.sdlRenderer = nullptr;

    return *this;
}

void Renderer::destroyRenderer() {
    if (sdlRenderer != nullptr) {
        SDL_DestroyRenderer(sdlRenderer);
        sdlRenderer = nullptr;
    }
}
