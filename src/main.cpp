#include "../classes/heroClass.hpp"
#include "../classes/enemyClass.hpp"
#include "../classes/window.hpp"
#include "../classes/projectileClass.hpp"

int main() {
    Hero* player = new Hero("John");
    Enemy *enem[15];
    Window *win = new Window(20, 40, 0, 0);
    Projectile *bul[10];
    
    bool proj[10] = {false, false, false, false, false, false, false, false, false};
    int no_bul = 0;
    int no_en = 0;

    initscr();
    curs_set(0);

    win->makeWin();

    while (1)
    {
        nodelay(win->win, true);
        keypad(win->win, TRUE);
        int c, y, x;
        x = player->position_x;
        y = player->position_y;
        c = wgetch(win->win);
        wclear(win->win);
        napms(40); 
        switch (c)
        {
            case KEY_UP:
                y--;
                player->setY(y);
                break;
            case KEY_DOWN:
                y++;
                player->setY(y);
                break;
            case ' ':
                if (no_bul == 9)
                {
                    no_bul = 0;
                    break;
                }
                bul[no_bul] = new Projectile();
                bul[no_bul]->setY(player->getY());
                bul[no_bul]->setX(player->getX());
                no_bul++;
                break;
            default:
                x = x;
                break;
           
        }
        int i = 0;

        if (no_en == 0)
        {
            while (i < 15)
            {
                int j = rand() % 40 + 40;
                int k = rand() % 20;
                enem[i] = new Enemy();
                enem[i]->setX(j);
                enem[i]->setY(k);
                i++;
            }
            no_en = 15;
        }

        i = 0;

        while (i < 15)
        {
            enem[i]->setX(enem[i]->getX()-1);
            win->enem(enem[i]->getX(), enem[i]->getY());
            if (enem[14]->getX() == -6)
            {
                no_en = 0;
                i = 14;
            }
            i++;
        }

        i = 0;

        while(i != no_bul)
        {
            bul[i]->setX(bul[i]->getX() + 1);
            win->shot(bul[i]->getX(), bul[i]->getY());
            i++;
        }
        win->moveto(*player);
        box(win->win, 0, 0);
        wrefresh(win->win);
    }


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