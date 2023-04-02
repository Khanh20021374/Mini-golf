#include "Graphics.h"

Graphics* Graphics::instance = NULL;

bool Graphics::isInitialized = false;

Graphics* Graphics::getInstance() {
    if (instance == NULL) {
        instance = new Graphics();
    }
    return instance;
}

void Graphics::Free() {
    delete instance;

    isInitialized = false;
}

bool Graphics::Initialized() {
    return isInitialized;
}

Graphics::Graphics() {
    isInitialized = Init();
}

Graphics::~Graphics() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

bool Graphics::Init() {
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL Initialization Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        printf("Window Creation Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == NULL) {
        printf("Renderer Creation Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    int flags = IMG_INIT_PNG;
    if(!(IMG_Init(flags) & flags)) {
        printf("IMG Initialization Error: %s\n", IMG_GetError());
        return false;
    }

    if(TTF_Init() == -1) {
        printf("TTF Initialization Error: %s\n", TTF_GetError());
        return false;
    }

    return true;
}

SDL_Texture* Graphics::loadTexture(std::string path) {
    SDL_Texture* tex = NULL;

    SDL_Surface* surface = IMG_Load(path.c_str());

    if(surface == NULL) {

        printf("Image Load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
        return tex;
    }

    tex = SDL_CreateTextureFromSurface(renderer, surface);

    if(tex == NULL) {

        printf("Create Texture Error: %s\n", SDL_GetError());
        return tex;
    }

    SDL_FreeSurface(surface);

    return tex;
}

SDL_Texture* Graphics::loadFontTexture(TTF_Font* font, std::string text, SDL_Color color) {
    SDL_Texture* tex = NULL;

    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);

    if(surface == NULL) {

        printf("TTF Load Error: Error(%s)\n", TTF_GetError());
        return tex;
    }

    tex = SDL_CreateTextureFromSurface(renderer, surface);

    if(tex == NULL) {

        printf("Create Texture Error: %s\n", SDL_GetError());
        return tex;
    }

    SDL_FreeSurface(surface);

    return tex;
}

void Graphics::clearScreen() {
    SDL_RenderClear(renderer);
}

void Graphics::drawTexture(SDL_Texture* texture, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(renderer, texture, clip, rend, angle, NULL, flip);
}

void Graphics::Render() {
    SDL_RenderPresent(renderer);
}

