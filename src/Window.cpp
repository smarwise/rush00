#include "../classes/window.hpp"

Window::Window()
{
}

// Window(std::string name);

Window::Window(const Window &newft)
{
    *this = newft;
}

WINDOW *Window::makeWin()
{
    initscr();
    this->win = newwin(50, 50, 10, 10);
    refresh();
    return (win);
}

void Window::useWin()
{

    initscr();
    // box(this->win, 0, 0);
    wrefresh(this->win);
    noecho();
    keypad(this->win, TRUE);
    int c, y, x;
    x = 10;
    y = 10;
    char a = 'P';
    mvwaddch(this->win, y, x, a | A_BOLD | A_COLOR);
    while ((c = wgetch(this->win)) != 27)
    {
        switch (c)
        {
            case KEY_UP:
                y--;
                mvwaddch(this->win, y, x, a | A_BOLD | A_COLOR);
            case KEY_DOWN:
                y++;
                mvwaddch(this->win, y, x, a | A_BOLD | A_COLOR);
            case KEY_LEFT:
                x--;
                mvwaddch(this->win, y, x, a | A_BOLD | A_COLOR);
                break;
            case KEY_RIGHT:
                x++;
                mvwaddch(this->win, y, x, a | A_BOLD | A_COLOR);
                break;
            default:
                x = x;
           
        }
         wrefresh(this->win);
    }
    // wgetch(this->win);
    // wrefresh(this->win);
    return;
}

void Window::movePlayer()
{
    int ch;

    noecho();
    ch = wgetch(this->win);
    switch ((ch = wgetch(this->win)))
    {
    case KEY_UP:
        std::cout << std::endl
                  << "Up" << std::endl; //key up
        break;
    case KEY_DOWN:
        std::cout << std::endl
                  << "Down" << std::endl; // key down
        break;
    case KEY_LEFT:
        std::cout << std::endl
                  << "Left" << std::endl; // key left
        break;
    case KEY_RIGHT:
        std::cout << std::endl
                  << "Right" << std::endl; // key right
        break;
    default:
        std::cout << std::endl
                  << "null" << std::endl; // not arrow
        break;
    }
}

void Window::endWindow()
{
    delwin(this->win);
}

Window::~Window()
{
}
