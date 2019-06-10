#ifndef HEROCLASS_HPP_
#define HEROCLASS_HPP_
#include <string>

#include "entityClass.hpp"

class Hero : public Entity {
    public:
        Hero();
        Hero(std::string name);
        ~Hero();
        Hero(const Hero &newft);
		void operator = (Hero *obj);

        void getHit();
        void Shoot();

};

#endif