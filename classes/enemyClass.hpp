#ifndef ENEMYCLASS_HPP_
#define ENEMYCLASS_HPP_
#include <string>

#include "entityClass.hpp"

class Enemy : public Entity {
    public:
        Enemy();
        Enemy(std::string name);
        ~Enemy();
        Enemy(const Enemy &newft);
		void operator = (Enemy *obj);

        void getHit();
};

#endif