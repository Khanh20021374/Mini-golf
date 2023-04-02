#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "Texture.h"
#include "InputManager.h"
#include "Timer.h"
#include "AudioManager.h"
#include "ScreenManager.h"

class GameManager {
    private:
        static GameManager* instance;

        const int FRAME_RATE = 60;

        bool quit;

        Graphics* graphics;
        Timer* timer;
        AssetManager* AssetManager;
        InputManager* inputManager;
        AudioManager* audioManager;

        ScreenManager* screenManager;

        SDL_Event event;

        GameManager();
        ~GameManager();

    public:
        static GameManager* getInstance();
        static void Free();

        void Update();
        void lateUpdate();
        void Render();

        void Run();


};

#endif
