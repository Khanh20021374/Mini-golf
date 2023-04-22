#include "EndScreen.h"

EndScreen::EndScreen() {
    inputManager = InputManager::getInstance();

    bg = new Texture("Assets/playBg.png");
    bg->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.5f, Graphics::getInstance()->SCREEN_HEIGHT*0.5f));

    gameOverMessage = new Texture("GAME OVER", "Assets/toonAround.ttf", 48, {255, 255, 255});
    gameOverMessage->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.5f, Graphics::getInstance()->SCREEN_HEIGHT*0.365f));

    restartPrompt = new Texture("PRESS R TO RESTART", "Assets/toonAround.ttf", 32, {255, 255, 255});
    restartPrompt->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.5f, Graphics::getInstance()->SCREEN_HEIGHT*0.5f));

    quitPrompt = new Texture("PRESS Q TO QUIT", "Assets/toonAround.ttf", 32, {255, 255, 255});
    quitPrompt->setPosition(Vector2f(Graphics::getInstance()->SCREEN_WIDTH * 0.5f, Graphics::getInstance()->SCREEN_HEIGHT*0.55f));
}

EndScreen::~EndScreen() {
    delete bg;
    delete gameOverMessage;
    //delete gameOverShading;
    delete restartPrompt;
    //delete restartPromptShading;
    delete quitPrompt;
    //delete quitPromptShading;
}

void EndScreen::Update() {

}

void EndScreen::Render() {
    bg->Render();
    gameOverMessage->Render();
    restartPrompt->Render();
    quitPrompt->Render();
}
