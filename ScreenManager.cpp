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

    inputManager = InputManager::getInstance();

    currentScreen = start;
}

ScreenManager::~ScreenManager() {
    delete startScreen;
}

void ScreenManager::Update() {

    switch (currentScreen) {
        case start:
            startScreen->Update();
            if (inputManager->mouseButtonPressed(InputManager::left)) {
                currentScreen = play;
            }
            break;

        case play:
            if (inputManager->keyPressed(SDL_SCANCODE_ESCAPE)) {
                currentScreen = start;
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

            break;
    }

}
