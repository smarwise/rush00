#include "../classes/ft_retro.hpp"
#include "../classes/window.hpp"

int main() {
    Hero* player = new Hero();
    Window *win = new Window();

    win->makeWin();
    win->useWin();
    //  initscr();
    // raw();
    // int c;
    // printw("Write something (ESC to escape): ");
    // while ((c=getch())!=27)
    // {
    //     move(10, 0);
    //     printw("Keycode : %d, and the character %c", c, c);
    //     move(0, 0);
    //     printw("Write something");
    //     refresh();
    // }
    // endwin();
    delete player;
}