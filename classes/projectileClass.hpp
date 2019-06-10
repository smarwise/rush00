#ifndef PROJECTILECLASS_HPP_
#define PROJECTILECLASS_HPP_
#include <string>

#include "entityClass.hpp"

class Projectile : public Entity {
    public:
        Projectile();
        Projectile(std::string name);
        ~Projectile();
        Projectile(const Projectile &newft);
		void operator = (Projectile *obj);

        void Shot();

        bool hot;
};

#endif