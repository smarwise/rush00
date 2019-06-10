#include "../classes/projectileClass.hpp"

Projectile::Projectile(int x, int y) {
    setX(x);
    setY(y);
    setchr('-');
    std::cout << "Player Created!\n";
}

Projectile::Projectile() {
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