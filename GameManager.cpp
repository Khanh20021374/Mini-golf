#include "GameManager.h"

GameManager* GameManager::instance = NULL;

GameManager* GameManager::getInstance() {
    if (instance == NULL) {
        instance = new GameManager();
    }
    return instance;
}

void GameManager::Free() {
    delete instance;
}

GameManager::GameManager() {
    quit = false;

    graphics = Graphics::getInstance();

    if (!Graphics::Initialized())
        quit = true;

    AssetManager = AssetManager::getInstance();
    inputManager = InputManager::getInstance();
    audioManager = AudioManager::getInstance();
    timer = Timer::getInstance();

    screenManager = ScreenManager::getInstance();
}

GameManager::~GameManager() {
    ScreenManager::Free();
    AudioManager::Free();
    AssetManager::Free();
    Graphics::Free();
    InputManager::Free();
    Timer::Free();
}

void GameManager::Update() {
    inputManager->Update();
    screenManager->Update();
}

void GameManager::lateUpdate() {
    inputManager->updatePreviousInput();
}

void GameManager::Render() {
    graphics->clearScreen();
    screenManager->Render();
    graphics->Render();
}

void GameManager::Run() {

    while (!quit) {
        timer->Update();

        while (SDL_PollEvent(&event) != 0) {

            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        if (timer->getDeltaTime() >= (1.0f / FRAME_RATE)) {
            timer->Reset();

            Update();
            Render();
            lateUpdate();

        }
    }
}
