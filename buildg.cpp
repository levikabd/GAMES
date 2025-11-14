
#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <unistd.h>

int buildg()
{
    const int max_x = 4;
    const int max_y = max_x*max_x;

    initscr();
    curs_set(0);

    for (int x = 0; x < 2*max_x+1; x++)
    {
        int y = (x-max_x)*(x-max_x);
        mvaddch(max_y-y,x,'o');
        refresh();
        sleep(1);
    };

    sleep(3);
    //getch();
    endwin();

    return 0;
};