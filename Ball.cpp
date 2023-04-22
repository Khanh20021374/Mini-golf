#include "Ball.h"

Ball::Ball() {
    timer = Timer::getInstance();
    inputManager = InputManager::getInstance();
    audioManager = AudioManager::getInstance();

    friction = 0.98f;

    visible = false;
    canMove = true;

    ballTexture = new Texture("Assets/ball.png");
    arrow = new Texture("Assets/dir.png");
    arrow->setActive(false);
}

Ball::~Ball() {
    delete ballTexture;
}

void Ball::setVisible(bool vis) {
    visible = vis;
}

void Ball::handleMovement() {
    int x, y;

    if (inputManager->mouseButtonPressed(InputManager::left) && canMove) {
        SDL_GetMouseState(&x, &y);
        initialMousePos = Vector2f(x, y);
        arrow->setActive(true);
    }

    if (inputManager->mouseButtonDown(InputManager::left) && canMove) {
        SDL_GetMouseState(&x, &y);
        Vector2f currentMousePos = Vector2f(x, y);
        float dx = currentMousePos.x - initialMousePos.x;
        float dy = currentMousePos.y - initialMousePos.y;
        rotationAngle = 360 - SDL_atan2f(dx, dy) * 180 / 3.1415;
        arrow->setAngle(rotationAngle);
    }

    if (inputManager->mouseButtonReleased(InputManager::left) && canMove) {
        SDL_GetMouseState(&x, &y);
        finalMousePos = Vector2f(x, y);

        float dx = finalMousePos.x - initialMousePos.x;
        float dy = finalMousePos.y - initialMousePos.y;
        float length = SDL_sqrt(dx*dx + dy*dy);

        swingDir = Vector2f(-dx / length, -dy / length);
        moveSpeed = length * 7.5f;

        if (moveSpeed > 2500) {
            moveSpeed = 2500;
        }

        velocity = swingDir * moveSpeed;

        audioManager->playSFX("Assets/swing.wav", 0, -1);

        arrow->setActive(false);
    }



    if (abs(velocity.x) < 10.0f && abs(velocity.y) < 10.0f) {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
        canMove = true;
    }

    if (abs(velocity.x) > 0.0f && abs(velocity.y) > 0.0f) {
        canMove = false;
        velocity = velocity * friction;
        Translate(velocity * timer->getDeltaTime());
    } else {
        canMove = true;
    }


    if (getPosition().x < BALL_RADIUS) {
        setPosition(Vector2f(BALL_RADIUS, getPosition().y));
        velocity.x *= -1;
    } else if (getPosition().x > Graphics::getInstance()->SCREEN_WIDTH - BALL_RADIUS) {
        setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH - BALL_RADIUS, getPosition().y));
        velocity.x *= -1;
    }


    if (getPosition().y < BALL_RADIUS) {
        setPosition(Vector2f(getPosition().x, BALL_RADIUS));
        velocity.y *= -1;
    } else if (getPosition().y > Graphics::getInstance()->SCREEN_HEIGHT - BALL_RADIUS) {
        setPosition(Vector2f(getPosition().x, Graphics::getInstance()->SCREEN_HEIGHT - BALL_RADIUS));
        velocity.y *= -1;
    }
}

void Ball::Update() {
    handleMovement();

    ballTexture->setPosition(getPosition());
    arrow->setPosition(getPosition());
}

void Ball::Render() {
    if (visible) {
        ballTexture->Render();
    }
    if (arrow->isActive()) {
        arrow->Render();
    }
}

