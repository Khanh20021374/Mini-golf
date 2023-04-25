#include "LevelManager.h"

LevelManager::LevelManager(int level) {
    timer = Timer::getInstance();
    audioManager = AudioManager::getInstance();

    ball = NULL;
    hole = NULL;

    currentLevel = level;
    levelStarted = false;
    gameOver = false;

    current = 0.0f;
    elapsedTime = 0.0f;

    countDown = 60;

    levelText = new Texture("Level", "assets/toonAround.ttf", 32, {255, 255, 255});
    levelText->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.45f, Graphics::getInstance()->SCREEN_HEIGHT * 0.5f));
    levelTextOnScreen = 0.0f;
    levelTextOffScreen = 1.5f;

    levelNumber = new Texture(std::to_string(currentLevel), "assets/toonAround.ttf", 32, {255, 255, 255});
    levelNumber->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.55f, Graphics::getInstance()->SCREEN_HEIGHT * 0.5f));

    clock = new Texture("Time left: " + std::to_string(countDown), "assets/toonAround.ttf", 32, {255, 255, 255});
    clock->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.50f, Graphics::getInstance()->SCREEN_HEIGHT * 0.05f));
}

LevelManager::~LevelManager() {
    timer = NULL;

    delete levelText;
    delete levelNumber;

    delete ball;
    delete hole;
}

void LevelManager::StartLevel() {
    int xMax = Graphics::getInstance()->SCREEN_WIDTH;
    int xMin = 8;
    int yMax = Graphics::getInstance()->SCREEN_HEIGHT;
    int yMin = 8;

    srand(time(nullptr));
    int randX = rand();
    randX = randX % (xMax - xMin + 1) + xMin;

    int randY = rand();
    randY = randY % (yMax - yMin + 1) + yMin;

    levelStarted = true;

    delete ball;
    ball = new Ball();
    ball->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.5f, Graphics::getInstance()->SCREEN_HEIGHT * 0.5f));
    ball->setVisible(true);

    delete hole;
    hole = new Hole();
    hole->setPosition(Vector2f(randX, randY));
    hole->setVisible(true);
}

void LevelManager::StartNextLevel() {
    levelStarted = false;
    current = 0.0f;
    currentLevel++;
    levelNumber = new Texture(std::to_string(currentLevel), "assets/toonAround.ttf", 32, {255, 255, 255});
    levelNumber->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.55f, Graphics::getInstance()->SCREEN_HEIGHT * 0.5f));
}

void LevelManager::Update() {
    if (!levelStarted) {
        current += timer->getDeltaTime();

        if (current >= levelTextOffScreen) {
            StartLevel();
        }

    } else {
        ball->Update();
        hole->Update();

        if (checkCollision(ball, hole)) {
            ball->setVisible(false);
            audioManager->playSFX("Assets/hole.mp3", 0, -1);

            StartNextLevel();
        }

        elapsedTime += timer->getDeltaTime();
        if (elapsedTime >= 1) {
            countDown--;
            elapsedTime = 0.0f;
            clock = new Texture("Time left: " + std::to_string(countDown), "assets/toonAround.ttf", 32, {255, 255, 255});
            clock->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.50f, Graphics::getInstance()->SCREEN_HEIGHT * 0.05f));
        }
        if (countDown <= 0) {
            gameOver = true;
        }


        std::cout << countDown << '\n';
    }
}

void LevelManager::Render() {
    if (!levelStarted) {
        if (current > levelTextOnScreen && current < levelTextOffScreen) {
            levelNumber->Render();
            levelText->Render();
        }
    } else {
        ball->Render();
        hole->Render();
        clock->Render();
    }
}

bool LevelManager::checkCollision(Ball* ball, Hole* hole) {
    // Calculate the distance between the centers of the two circles
    int dx = ball->getPosition().x - hole->getPosition().x;
    int dy = ball->getPosition().y - hole->getPosition().y;
    int distance = SDL_sqrtf(dx * dx + dy * dy);

    // Check if the distance is less than the sum of the two radii
    if (distance < ball->BALL_RADIUS + hole->HOLE_RADIUS) {
        return true;
    } else {
        return false;
    }
}

bool LevelManager::isOver() {
    return gameOver;
}
