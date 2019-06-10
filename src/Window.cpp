#include "../classes/window.hpp"

Window::Window(int height, int width, int x_co, int y_co)
{
    h = height;
    w = width;
    x = x_co;
    y = y_co;
    initscr();
    curs_set(0);
}

Window::Window(const Window &newft)
{
    *this = newft;
}

WINDOW *Window::makeWin()
{
    this->win = newwin(h, w, y, x);
    box(this->win, 0, 0);
    wrefresh(this->win);
    return (win);
}

void Window::moveto(Entity & ent)
{
    mvwprintw(this->win, ent.getY(), ent.getX(), "%c", ent.getchr());
}

void Window::shot(int x, int y) {

    mvwprintw(this->win, y, x, "%c", '-');
}

void Window::enem(int x, int y) {

    mvwprintw(this->win, y, x, "%c", '<');
}

void Window::useWin(Entity & ent)
{
    // wgetch(this->win);
    // noecho();
    // keypad(this->win, TRUE);
    // int c, y, x;
    // x = ent.position_x;
    // y = ent.position_y; 

    // while ((c = wgetch(this->win)) != 27)
    // {
    //     switch (c)
    //     {
    //         case KEY_UP:
    //             y--;
    //             ent.setY(y);
    //             wclear(this->win);
    //             moveto(ent);
    //             box(this->win, 0, 0);
    //             wrefresh(this->win);
    //             break;
    //         case KEY_DOWN:
    //             y++;
    //             ent.setY(y);
    //             wclear(this->win);
    //             moveto(ent);
    //             box(this->win, 0, 0);
    //             wrefresh(this->win);
    //             break;
    //         // case KEY_LEFT:
    //         //     x--;
    //         //     moveto(y, x);
    //         //     break;
    //         // case KEY_RIGHT:
    //         //     x++;
    //         //     moveto(y, x);
    //         //     break;
    //         case ' ':
    //             moveto(ent);
    //         default:
    //             x = x;
           
    //     }
    //     wrefresh(this->win);
    // }
    // return;
}

void Window::endWindow()
{
    delwin(this->win);
}

Window::~Window()
{
}