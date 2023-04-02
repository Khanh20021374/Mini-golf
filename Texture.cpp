#include "Texture.h"

Texture::Texture(std::string filename) {
    clipped = false;

    graphics = Graphics::getInstance();

    texture = AssetManager::getInstance() -> getTexture(filename);

    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    renderRect.w = width;
    renderRect.h = height;
}

Texture::Texture(std::string filename, int x, int y, int w, int h) {
    clipped = true;

    graphics = Graphics::getInstance();

    texture = AssetManager::getInstance() -> getTexture(filename);

    width = w;
    height = h;

    renderRect.w = width;
    renderRect.h = height;

    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = width;
    clipRect.h = height;
}

Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color color) {
    graphics = Graphics::getInstance();

    texture = AssetManager::getInstance()->getText(text, fontPath, size, color);

    clipped = false;

    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    renderRect.w = width;
    renderRect.h = height;
}

Texture::~Texture() {
}

void Texture::Render() {
    renderRect.x = (int)(getPosition().x - width*0.5f);
    renderRect.y = (int)(getPosition().y - height*0.5f);

    graphics->drawTexture(texture, (clipped)? &clipRect : NULL, &renderRect);
}
