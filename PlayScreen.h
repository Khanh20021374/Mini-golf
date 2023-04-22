#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H

#include "Ball.h"
#include "Hole.h"
#include "LevelManager.h"

class PlayScreen : public Entity {
    private:
        Timer* timer;
        InputManager* inputManager;

        Ball* ball;
        Hole* hole;

        LevelManager* levelManager;

        bool gameStarted;
        bool levelStarted;

        int currentLevel;

        void StartNextLevel();

        Texture* background;


    public:
        PlayScreen();
        ~PlayScreen();

        void StartNewGame();

        void Update();
        void Render();
};

#endif
