#include "ScreenManager.h"

ScreenManager* ScreenManager::instance = NULL;

ScreenManager* ScreenManager::getInstance() {
    if (instance == NULL)
        instance = new ScreenManager();

    return instance;
}

void ScreenManager::Free() {
    delete instance;
}

ScreenManager::ScreenManager() {
    startScreen = new StartScreen();
    playScreen = new PlayScreen();
    endScreen = new EndScreen();

    gameOver = false;

    playScreen->StartNewGame();

    inputManager = InputManager::getInstance();

    currentScreen = start;
}

ScreenManager::~ScreenManager() {
    delete startScreen;
    delete playScreen;
    delete endScreen;
}

bool ScreenManager::isOver() {
    return gameOver;
}

void ScreenManager::Update() {

    switch (currentScreen) {
        case start:
            startScreen->Update();
            if (inputManager->mouseButtonPressed(InputManager::left)) {
                currentScreen = play;
                playScreen->StartNewGame();
            }
            break;

        case play:
            if (inputManager->keyPressed(SDL_SCANCODE_N)) {
                currentScreen = over;
            }
            playScreen->Update();
            break;

        case over:
            endScreen->Update();
            if (inputManager->keyPressed(SDL_SCANCODE_R)) {
                playScreen = new PlayScreen();
                playScreen->StartNewGame();
                currentScreen = play;
            } else if (inputManager->keyPressed(SDL_SCANCODE_Q)) {
                gameOver = true;
            }
            break;

    }
}

void ScreenManager::Render() {

    switch (currentScreen) {

        case start:
            startScreen->Render();
            break;

        case play:
            playScreen->Render();
            break;

        case over:
            endScreen->Render();
            break;
    }

}
