#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <string>
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Graphics {

    public:
        static const int SCREEN_WIDTH = 850;
        static const int SCREEN_HEIGHT = 640;
        const char* WINDOW_TITLE = "SimpleSDL";

        static Graphics* getInstance();

        static void Free();

        static bool Initialized();

        SDL_Texture* loadTexture(std::string path);
        SDL_Texture* loadFontTexture(TTF_Font* font, std::string text, SDL_Color color);

        void clearScreen();

        void drawTexture(SDL_Texture* texture, SDL_Rect* clip = NULL, SDL_Rect* rend = NULL, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);

        void Render();

    private:
        static Graphics* instance;

        static bool isInitialized;

        bool Init();

        SDL_Window* window;

        SDL_Renderer* renderer;

        Graphics();
        ~Graphics();
};

#endif

