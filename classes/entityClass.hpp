#ifndef ENTITYCLASS_HPP
#define ENTITYCLASS_HPP

#include <iomanip>
#include <iostream>

class Entity {
    public:
        Entity();
        Entity(std::string name);
        ~Entity();
        Entity(const Entity &newft);
		void operator = (Entity *obj);

        std::string Name;
        int Lives;
        int position_y; /* Dont know if you need these co-ordinates */
        int position_x;

        void setLives(int value);
        void setX(int value);
        void setY(int value);

        int getLives();
        int getX();
        int getY();
};

#endif