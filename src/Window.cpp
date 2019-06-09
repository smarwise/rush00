#include "../classes/window.hpp"

Window::Window()
{
}

Window::Window(const Window &newft)
{
    *this = newft;
}

WINDOW *Window::makeWin()
{
    initscr();
    this->win = newwin(50, 50, 10, 10);
    curs_set(0);
    refresh();
    return (win);
}

void Window::moveto(int y, int x)
{
    initscr();
    char a = 'P';
    wclear(this->win);
    mvwaddch(this->win, y, x, a);
    wrefresh(this->win);
    // refresh();
}

void Window::useWin()
{

    initscr();
    wrefresh(this->win);
    noecho();
    keypad(this->win, TRUE);
    int c, y, x;
    x = 10;
    y = 10; 
    moveto(y, x);
    while ((c = wgetch(this->win)) != 27)
    {
        switch (c)
        {
            case KEY_UP:
                y--;
                moveto(y, x);
                break;
            case KEY_DOWN:
                y++;
                moveto(y, x);
                break;
            case KEY_LEFT:
                x--;
                moveto(y, x);
                break;
            case KEY_RIGHT:
                x++;
                moveto(y, x);
                break;
            // default:
            //     x = x;
           
        }
        wrefresh(this->win);
    }
    return;
}

void Window::movePlayer()
{
    // int ch;

    // noecho();
    // ch = wgetch(this->win);
    // switch ((ch = wgetch(this->win)))
    // {
    // case KEY_UP:
    //     std::cout << std::endl
    //               << "Up" << std::endl; //key up
    //     break;
    // case KEY_DOWN:
    //     std::cout << std::endl
    //               << "Down" << std::endl; // key down
    //     break;
    // case KEY_LEFT:
    //     std::cout << std::endl
    //               << "Left" << std::endl; // key left
    //     break;
    // case KEY_RIGHT:
    //     std::cout << std::endl
    //               << "Right" << std::endl; // key right
    //     break;
    // default:
    //     std::cout << std::endl
    //               << "null" << std::endl; // not arrow
    //     break;
    // }
}

void Window::endWindow()
{
    delwin(this->win);
}

Window::~Window()
{
}
