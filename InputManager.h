#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H

#include <stdio.h>
#include <SDL.h>
#include <string.h>
#include "Math.h"


class InputManager {
    private:
        static InputManager* instance;

        InputManager();
        ~InputManager();

        Uint8* previousKeyboardState;
        const Uint8* keyboardState;
        int keySize;

        Uint32 previousMouseState;
        Uint32 mouseState;

        int mouseX, mouseY;

    public:
        enum MOUSE_BUTTON {left = 0, right, middle};

        static InputManager* getInstance();
        static void Free();

        bool keyDown(SDL_Scancode scanCode);
        bool keyPressed(SDL_Scancode scanCode);
        bool keyReleased(SDL_Scancode scanCode);

        bool mouseButtonDown(MOUSE_BUTTON button);
        bool mouseButtonPressed(MOUSE_BUTTON button);
        bool mouseButtonReleased(MOUSE_BUTTON button);

        Vector2f getMousePos();

        void Update();
        void updatePreviousInput();
};

#endif
