#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include "Texture.h"
#include "InputManager.h"

class StartScreen : public Entity {
    private:
        Graphics* graphics;

        Texture* backgroundImage;
        Texture* logo;

        Texture* startPrompt;
        Texture* startShading;
    public:
        StartScreen();
        ~StartScreen();

        void Update();
        void Render();
};


#endif
