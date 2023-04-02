#include "StartScreen.h"

StartScreen::StartScreen() {
    graphics = Graphics::getInstance();

    backgroundImage = new Texture("Assets/bg.jpg");
    backgroundImage->setPosition(Vector2f(graphics->SCREEN_WIDTH * 0.5f, graphics->SCREEN_HEIGHT * 0.5f));

    logo = new Texture("Assets/Logo.png");
    logo->setPosition(Vector2f(graphics->SCREEN_WIDTH * 0.5f, graphics->SCREEN_HEIGHT * 0.5f - 25));

    startPrompt = new Texture("LEFT CLICK TO START", "Assets/toonAround.ttf", 32, {255, 255, 255});
    startPrompt->setPosition(Vector2f(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f + 45));

    startShading = new Texture("Assets/startShader.png");
    startShading->setPosition(Vector2f(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f - 65));
}

StartScreen::~StartScreen() {
    delete backgroundImage;
    delete logo;
}

void StartScreen::Update() {

}

void StartScreen::Render() {
    backgroundImage->Render();
    logo->Render();
    startShading->Render();
    startPrompt->Render();

}
