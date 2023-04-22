#include "Hole.h"

Hole::Hole() {
    holeTexture = new Texture("Assets/hole.png");
}

Hole::~Hole() {
    delete holeTexture;
}

void Hole::setVisible(bool vis) {
    visible = vis;
}

void Hole::Update() {
    holeTexture->setPosition(getPosition());
}

void Hole::Render() {
    if (visible) {
        holeTexture->Render();
    }
}
