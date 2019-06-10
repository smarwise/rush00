#include "../classes/window.hpp"

Window::Window()
{
    std::cout << "Launching...";
    makeBorder();
    initscr();
    makeBorder();
    getch();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    this->maxy = 25;
    this->maxx = 40;
    // getmaxyx(stdscr, maxy, maxx);
    score = 0;
    displayScore();
}

Window::Window(const Window &newft)
{
    *this = newft;
}

void Window::makeBorder()
{
    border = '#';
    for (int i = 0; i < maxx - 1 ; i++)
    {
        move(0, i);
        addch(border);
    }
    for (int i = 0; i < maxx - 1 ; i++)
    {
        move(maxy-2, i);
        addch(border);
    }
    for (int i = 0; i < maxy - 1 ; i++)
    {
        move(i, 0);
        addch(border);
    }
     for (int i = 0; i < maxy - 1 ; i++)
    {
        move(i, maxx-2);
        addch(border);
    }
    refresh();
}

void Window::displayScore()
{
    move(maxy - 1, 0);
    printw("Score: %d", score);
    refresh();
}

void Window::moveto(int x, int y)
{
    getch();
    box(stdscr, 10, 10);
    char a = 'X';
    clear();
    makeBorder();
    displayScore();
    mvaddch(y, x, a);
    // mvaddch(y + 1, x, a);
    // mvaddch(y, x + 1, a);
    // mvaddch(y + 1, x + 1, a);
    refresh();
}

void Window::readInput(Entity & player)
{
    nodelay(stdscr, true);
    getch();
    refresh();
    int c;
    // x = 2;
    // y = 1; 
    moveto(player.position_x , player.position_y);
    while ((c = getch()) != 27)
    {
        switch (c)
        {
            // case KEY_UP:
            //     y--;
            //     if (y < 1)
            //         y = 1;
            //     moveto(y, player.position_x);
            //     break;
            // case KEY_DOWN:
            //     y++;
            //     if (y > (maxy - 3))
            //         y = (maxy - 3);
            //     moveto(y, player.position_x);
                // break;
            case KEY_LEFT:
                player.position_x--;
                if (player.position_x < 1)
                    player.position_x = 1;
                moveto(player.position_x, player.position_y);
                break;
            case KEY_RIGHT:
                player.position_x++;
                if (player.position_x > maxx - 3)
                    player.position_x = maxx - 3;
                moveto(player.position_x, player.position_y);
                break;
            default:
                player.position_x = player.position_x;
        }
    }
    return;
}

Window::~Window()
{
    nodelay(stdscr, false);
    getch();
    endwin();
}
