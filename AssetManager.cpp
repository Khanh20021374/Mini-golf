#include "AssetManager.h"

AssetManager* AssetManager::instance = NULL;

AssetManager* AssetManager::getInstance() {
    if (instance == NULL)
        instance = new AssetManager();

    return instance;
}

void AssetManager::Free() {
    delete instance;
}

AssetManager::AssetManager() {

}

AssetManager::~AssetManager() {
    for (auto texture : textures) {
        if (texture.second != NULL) {
            SDL_DestroyTexture(texture.second);
        }
    }

    textures.clear();

    for (auto text : textTextures) {
        if (text.second != NULL) {
            SDL_DestroyTexture(text.second);
        }
    }

    textTextures.clear();

    for (auto font : fonts) {
        if (font.second != NULL) {
            TTF_CloseFont(font.second);
        }
    }

    fonts.clear();

    for (auto mus : music) {
        if (mus.second != NULL) {
            Mix_FreeMusic(mus.second);
        }
    }

    music.clear();

    for (auto sfx : SFX) {
        if (sfx.second != NULL) {
            Mix_FreeChunk(sfx.second);
        }
    }

    SFX.clear();
}


SDL_Texture* AssetManager::getTexture(std::string filename) {
    if (textures[filename] == nullptr)
        textures[filename] = Graphics::getInstance() -> loadTexture(filename);

    return textures[filename];
}

TTF_Font* AssetManager::loadFont(std::string filename, int size) {
    std::string key = filename + (char)size;

    if (fonts[key] == nullptr) {
        fonts[key] = TTF_OpenFont(filename.c_str(), size);

        if (fonts[key] == nullptr)
            printf("Font Loading Error: Font-%s Error-%s:", filename.c_str(), TTF_GetError());
    }

    return fonts[key];
}

SDL_Texture* AssetManager::getText(std::string text, std::string filename, int size, SDL_Color color) {
    TTF_Font* font = loadFont(filename, size);

    std::string key = text + filename + (char)size + (char)color.r + (char)color.g + (char)color.b;

    if (textTextures[key] == nullptr)
        textTextures[key] = Graphics::getInstance()->loadFontTexture(font, text, color);

    return textTextures[key];
}

Mix_Music* AssetManager::getMusic(std::string filename) {
    if (music[filename] == nullptr) {
        music[filename] = Mix_LoadMUS(filename.c_str());

        if (music[filename] == NULL)
            printf("Music Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
    }

    return music[filename];
}

Mix_Chunk* AssetManager::getSFX(std::string filename) {
    if (SFX[filename] == nullptr) {
        SFX[filename] = Mix_LoadWAV(filename.c_str());

        if (SFX[filename] == NULL)
            printf("SFX Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
    }

    return SFX[filename];
}
