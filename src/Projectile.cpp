#include "../classes/projectileClass.hpp"

Projectile::Projectile() {
    std::cout << "Player Created!\n";
}

Projectile::Projectile(std::string name) : Entity(name) {
    setLives(3);
    setX(3);
    setY(18);
    setchr('X');
    this->hot = false;
    std::cout << this->Name << " Created!\n";
}

Projectile::~Projectile() {
    // std::cout << "Player Destroyed\n";
}

Projectile::Projectile(const Projectile &newft) {
    *this = newft;
}

void Projectile::Shot() {
    if (this->hot == true)
    {
        setX(getX() + 1);
    }
}