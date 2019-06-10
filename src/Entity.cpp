#include "../classes/entityClass.hpp"

Entity::Entity() {
    std::cout << "Player Created!\n";
}

Entity::Entity(std::string name) {

    std::cout << this->Name << " Created!\n";
}

Entity::~Entity() {
    // std::cout << "Player Destroyed\n";
}

Entity::Entity(const Entity &newft) {
    *this = newft;
}

void Entity::setLives(int value) {
    this->Lives = value;
}

void Entity::setX(int value) {
    this->position_x = value;
}

void Entity::setY(int value) {
    this->position_y = value;
}

void Entity::setchr(int value) {
    this->chr = value;
}

int Entity::getLives() {
    return (this->Lives);
}

int Entity::getX() {
    return (this->position_x);
}

int Entity::getY() {
    return (this->position_y);
}

int Entity::getchr() {
    return (this->chr);
}