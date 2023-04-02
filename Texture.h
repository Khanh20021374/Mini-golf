#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Entity.h"
#include "AssetManager.h"
#include <string>

class Texture : public Entity {
    protected:
        SDL_Texture* texture;

        Graphics* graphics;

        int width, height;

        bool clipped;

        SDL_Rect renderRect;
        SDL_Rect clipRect;

    public:
        Texture(std::string filename);
        Texture(std::string filename, int x, int y, int w, int h);
        Texture(std::string text, std::string fontPath, int size, SDL_Color color);
        ~Texture();

        virtual void Render();
};

#endif
