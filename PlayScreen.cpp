#include "PlayScreen.h"

PlayScreen::PlayScreen() {
    timer = Timer::getInstance();
    inputManager = InputManager::getInstance();

    levelManager = NULL;

    levelStarted = false;
    gameOver = false;

    background = new Texture("Assets/playBg.png");
    background->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.5f, Graphics::getInstance()->SCREEN_HEIGHT * 0.5f));
}


PlayScreen::~PlayScreen() {
    timer = NULL;
    inputManager = NULL;

    delete levelManager;
    delete background;
}

void PlayScreen::StartNewGame() {
    currentLevel = 0;
    gameStarted = true;
}

void PlayScreen::StartNextLevel() {
    currentLevel++;
    levelStarted = true;

    delete levelManager;
    levelManager = new LevelManager(currentLevel);
}

bool PlayScreen::isOver() {
    return gameOver;
}

int PlayScreen::getCurrentLevel() {
    return currentLevel;
}

void PlayScreen::Update() {
    if (gameStarted) {
        if (!levelStarted) {
            StartNextLevel();
        } else {
            levelManager->Update();
            if (levelManager->isOver()) {
                gameOver = true;
            }
        }
    }
}

void PlayScreen::Render() {
    if (gameStarted && levelStarted) {
        background->Render();
        levelManager->Render();
    }
}
