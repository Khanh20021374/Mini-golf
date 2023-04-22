#ifndef _LEVELMANAGER_H
#define _LEVELMANAGER_H

#include "InputManager.h"
#include "Timer.h"
#include "Ball.h"
#include "Hole.h"
#include <cstdlib>
#include <ctime>

class LevelManager : public Entity {
    private:
        Timer* timer;
        AudioManager* audioManager;

        int currentLevel;

        bool levelStarted;

        float current;

        Texture* levelText;
        Texture* levelNumber;

        float levelTextOnScreen;
        float levelTextOffScreen;

        void StartLevel();
        void StartNextLevel();

        Ball* ball;
        Hole* hole;

        bool checkCollision(Ball* ball, Hole* hole);

    public:
        LevelManager(int level);
        ~LevelManager();

        void Update();
        void Render();
};

#endif
