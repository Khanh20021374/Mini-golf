#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H

#include <stdio.h>
#include "AssetManager.h"


class AudioManager {
    private:
        static AudioManager* instance;

        AssetManager* assetManager;

        AudioManager();
        ~AudioManager();

    public:
        static AudioManager* getInstance();
        static void Free();

        void playMusic(std::string filename, int loops = -1);
        void pauseMusic();
        void resumeMusic();

        void playSFX(std::string filename, int loops = 0, int channel = 0);

};

#endif

