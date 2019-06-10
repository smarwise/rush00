#ifndef WINDOW_H
#define WINDOW_H
#include <ncurses.h>
#include <iostream>
#include <string>
#include "heroClass.hpp"

class Window
{
    public : 
        Window(int height, int width, int x_co, int y_co);
        Window(std::string name);
        ~Window();
        Window(const Window &newft);

        WINDOW *makeWin();
        void moveto(Entity & ent);
        void shot(int x, int y);
        void enem(int x, int y);
        void useWin(Entity & ent);
        void movePlayer();
        void endWindow();

        WINDOW *win;

        int h;
        int w;
        int x;
        int y;
};
#endif