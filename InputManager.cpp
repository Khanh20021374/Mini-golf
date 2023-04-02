#include "InputManager.h"

InputManager* InputManager::instance = NULL;

InputManager* InputManager::getInstance() {
    if (instance == NULL)
        instance = new InputManager();

    return instance;
}

void InputManager::Free() {
    delete instance;
}

InputManager::InputManager() {
    keyboardState = SDL_GetKeyboardState(&keySize);
    previousKeyboardState = new Uint8[keySize];
    memcpy(previousKeyboardState, keyboardState, keySize);
}
InputManager::~InputManager() {
    delete[] previousKeyboardState;
}

bool InputManager::keyDown(SDL_Scancode scanCode) {
    return keyboardState[scanCode];
}

bool InputManager::keyPressed(SDL_Scancode scanCode) {
    return !previousKeyboardState[scanCode] && keyboardState[scanCode];
}

bool InputManager::keyReleased(SDL_Scancode scanCode) {
    return previousKeyboardState[scanCode] && !keyboardState[scanCode];
}

bool InputManager::mouseButtonDown(MOUSE_BUTTON button) {
    Uint32 mask = 0;

    switch (button) {
        case left:
            mask = SDL_BUTTON_LMASK;
            break;

        case right:
            mask = SDL_BUTTON_RMASK;
            break;

        case middle:
            mask = SDL_BUTTON_MMASK;
            break;
    }

    return (mouseState & mask);
}

bool InputManager::mouseButtonPressed(MOUSE_BUTTON button) {
    Uint32 mask = 0;

    switch (button) {
        case left:
            mask = SDL_BUTTON_LMASK;
            break;

        case right:
            mask = SDL_BUTTON_RMASK;
            break;

        case middle:
            mask = SDL_BUTTON_MMASK;
            break;
    }

    return !(previousMouseState & mask) && (mouseState & mask);
}

bool InputManager::mouseButtonReleased(MOUSE_BUTTON button) {
    Uint32 mask = 0;

    switch (button) {
        case left:
            mask = SDL_BUTTON_LMASK;
            break;

        case right:
            mask = SDL_BUTTON_RMASK;
            break;

        case middle:
            mask = SDL_BUTTON_MMASK;
            break;
    }

    return (previousMouseState & mask) && !(mouseState & mask);
}

Vector2f InputManager::getMousePos() {
    return Vector2f((float)mouseX, (float)mouseY);
}

void InputManager::Update() {
    mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}

void InputManager::updatePreviousInput() {
    memcpy(previousKeyboardState, keyboardState, keySize);
    previousMouseState = mouseState;
}
