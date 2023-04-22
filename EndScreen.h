#ifndef _ENDSCREEN_H
#define _ENDSCREEN_H

#include "Entity.h"
#include "Texture.h"
#include "InputManager.h"


class EndScreen : public Entity {
    private:
        InputManager* inputManager;

        Texture* bg;

        Texture* gameOverMessage;
        Texture* restartPrompt;
        Texture* quitPrompt;

        Texture* gameOverShading;
        Texture* restartPromptShading;
        Texture* quitPromptShading;


    public:
        EndScreen();
        ~EndScreen();

        void Update();
        void Render();

};

#endif
