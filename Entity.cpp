#include "Entity.h"

Entity::Entity() {
    position = Vector2f(0.0, 0.0);
    angle = 0.0f;
    active = true;
}

Entity::Entity(Vector2f pos) {
    position = pos;
    active = true;
}

Entity::~Entity() {

}

void Entity::setActive(bool status) {
    active = status;
}

bool Entity::isActive() {
    return active;
}

void Entity::setPosition(Vector2f pos) {
    position = pos;
}

Vector2f Entity::getPosition() {
    return position;
}

void Entity::Translate(Vector2f vec) {
    position += vec;
}

void Entity::Rotate(float amount) {
    angle += amount;
}

float Entity::getAngle() {
    return angle;
}

void Entity::setAngle(float r) {
    angle = r;
}

void Entity::Update() {}
void Entity::Render() {}
