#include "../classes/enemyClass.hpp"

Enemy::Enemy() {
    std::cout << "Player Created!\n";
}

Enemy::Enemy(std::string name) : Entity(name) {
    setLives(3);
    setX(11);
    setY(21);
    setchr('E');
    std::cout << this->Name << " Created!\n";
}

Enemy::~Enemy() {
    // std::cout << "Player Destroyed\n";
}

Enemy::Enemy(const Enemy &newft) {
    *this = newft;
}