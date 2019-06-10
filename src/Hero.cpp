#include "../classes/heroClass.hpp"

Hero::Hero() {
    std::cout << "Player Created!\n";
}

Hero::Hero(std::string name) : Entity(name) {
    setLives(3);
    setX(18);
    setY(21);
    setchr('X');
    std::cout << this->Name << " Created!\n";
}

Hero::~Hero() {
    // std::cout << "Player Destroyed\n";
}

Hero::Hero(const Hero &newft) {
    *this = newft;
}