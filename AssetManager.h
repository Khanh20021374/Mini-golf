#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include <SDL_mixer.h>

#include "Graphics.h"
#include <map>


class AssetManager {
    private:
        static AssetManager* instance;

        std::map<std::string, SDL_Texture*> textures;
        std::map<std::string, SDL_Texture*> textTextures;
        std::map<std::string, TTF_Font*> fonts;
        std::map<std::string, Mix_Music*> music;
        std::map<std::string, Mix_Chunk*> SFX;

        TTF_Font* loadFont(std::string filename, int size);

        AssetManager();
        ~AssetManager();

    public:
        static AssetManager* getInstance();
        static void Free();

        SDL_Texture* getTexture(std::string filename);
        SDL_Texture* getText(std::string text, std::string filename, int size, SDL_Color color);

        Mix_Music* getMusic(std::string filename);
        Mix_Chunk* getSFX(std::string filename);
};

#endif
