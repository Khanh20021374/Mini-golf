#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H

#include "StartScreen.h"
#include "InputManager.h"

class ScreenManager {
    private:
        enum SCREENS {start, play};

        SCREENS currentScreen;

        static ScreenManager* instance;

        InputManager* inputManager;
        StartScreen* startScreen;

        ScreenManager();
        ~ScreenManager();

    public:
        static ScreenManager* getInstance();
        static void Free();

        void Update();
        void Render();

};

#endif
