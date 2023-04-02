#include "Entity.h"

Entity::Entity() {
    position = Vector2f(0.0, 0.0);
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

void Entity::Update() {}
void Entity::Render() {}
