#include "../classes/window.hpp"
#include "../classes/projectileClass.hpp"

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

void Window::moveto(int x, int y, int a)
{
    getch();
    box(stdscr, 10, 10);
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
    Projectile *bul = new Projectile();
    // x = 2;
    // y = 1; 
    moveto(player.position_x , player.position_y, player.getchr());
    while ((c = getch()) != 27)
    {
        napms(40);
        switch (c)
        {
            case KEY_UP:
                player.position_y--;
                if (player.position_y < 1)
                    player.position_y = 1;
                moveto(player.position_x, player.position_y, player.getchr());
                break;
            case KEY_DOWN:
                player.position_y++;
                if (player.position_y > (maxy - 3))
                    player.position_y = (maxy - 3);
                moveto(player.position_x, player.position_y, player.getchr());
                break;
            // case KEY_LEFT:
            //     player.position_x--;
            //     if (player.position_x < 1)
            //         player.position_x = 1;
            //     moveto(player.position_x, player.position_y, player.getchr());
            //     break;
            // case KEY_RIGHT:
            //     player.position_x++;
            //     if (player.position_x > maxx - 3)
            //         player.position_x = maxx - 3;
            //     moveto(player.position_x, player.position_y, player.getchr());
            //     break;
            case ' ':
                projectile(player.position_x, player.position_y, player);
                break;
            default:
                player.position_x = player.position_x;
        }
    }
    return;
}

void Window::projectile(int x, int y, Entity & player)
{
    while (x != maxx-2)
    {
        moveto(x, y, '-');
        x++;
        // readInput(player);
    }
}

Window::~Window()
{
    nodelay(stdscr, false);
    getch();
    endwin();
}
