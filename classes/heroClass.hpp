#ifndef HEROCLASS_HPP_
#define HEROCLASS_HPP_
#include <string>

class Hero {
    public:
        Hero();
        Hero(std::string name);
        ~Hero();
        Hero(const Hero &newft);
		void operator = (Hero *obj);

        std::string Name;
        int Lives;
        int position_y; /* Dont know if you need these co-ordinates */
        int position_x;

        void Move();
        void getHit();
        void Shoot();
        void End();
};

#endif