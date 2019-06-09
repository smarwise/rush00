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

        void readInput();
        void makeBorder();
        void displayScore();
        void movePlayer();
        void moveto(int x, int y);
        void endWindow();
        int maxy;
        int maxx;
        char border;
        int score;
};
#endif