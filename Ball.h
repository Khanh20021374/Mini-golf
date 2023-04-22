#ifndef _BALL_H
#define _BALL_H

#include "Texture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Timer.h"


class Ball : public Entity {
    private:
        Timer* timer;
        InputManager* inputManager;
        AudioManager* audioManager;

        bool visible;
        bool canMove;

        Texture* ballTexture;
        Texture* arrow;

        float friction;

        Vector2f velocity;

        Vector2f initialMousePos;
        Vector2f finalMousePos;

        Vector2f swingDir;

        float moveSpeed;

        float rotationAngle;

        void handleMovement();

    public:
        Ball();
        ~Ball();

        void setVisible(bool visible);

        void Update();
        void Render();

        const int BALL_RADIUS = 8;

};

#endif
