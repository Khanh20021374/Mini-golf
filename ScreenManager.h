#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H

#include "StartScreen.h"
#include "PlayScreen.h"
#include "EndScreen.h"
#include "InputManager.h"

class ScreenManager {
    private:
        enum SCREENS {start, play, over};

        SCREENS currentScreen;

        static ScreenManager* instance;

        InputManager* inputManager;
        StartScreen* startScreen;
        PlayScreen* playScreen;
        EndScreen* endScreen;

        bool gameOver;

        ScreenManager();
        ~ScreenManager();

    public:
        static ScreenManager* getInstance();
        static void Free();

        bool isOver();

        void Update();
        void Render();

};

#endif
