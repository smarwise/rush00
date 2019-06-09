#ifndef FT_RETRO_HPP
#define FT_RETRO_HPP

// #include "heroClass.hpp"
#include <iomanip>
#include <iostream>
#include <string>

/* moved hero to here because it was causing compilation problems */
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