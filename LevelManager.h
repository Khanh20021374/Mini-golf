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
        bool gameOver;

        float current;
        float elapsedTime;

        int countDown;

        Texture* levelText;
        Texture* levelNumber;
        Texture* clock;

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

        bool isOver();

        void Update();
        void Render();
};

#endif
