#ifndef WINDOW_H
#define WINDOW_H
#include <ncurses.h>
#include <iostream>
#include <string>
#include "heroClass.hpp"

class Window
{
    public : 
        Window();
        Window(std::string name);
        ~Window();
        Window(const Window &newft);

        void readInput(Entity &player);
        void projectile(int x, int y, Entity & player);
        void makeBorder();
        void displayScore();
        void movePlayer();
        void moveto(int x, int y, int a);
        int maxy;
        int maxx;
        char border;
        int score;
};
#endif