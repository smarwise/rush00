#ifndef WINDOW_H
#define WINDOW_H
#include <ncurses.h>
#include <iostream>
#include <string>

class Window
{
    public : 
        Window();
        Window(std::string name);
        ~Window();
        Window(const Window &newft);

        WINDOW *makeWin();
        void useWin();
        void movePlayer();
        void moveto(int x, int y);
        void endWindow();
        WINDOW *win;
};
#endif