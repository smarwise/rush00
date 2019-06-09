#include "../classes/ft_retro.hpp"

Hero::Hero() {
    std::cout << "Player Created!\n";
}

Hero::Hero(std::string name) : Name(name){
    std::cout << this->Name << " Created!\n";
}

Hero::~Hero() {
    // std::cout << "Player Destroyed\n";
}

Hero::Hero(const Hero &newft) {
    *this = newft;
}