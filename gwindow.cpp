#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>
#include <cstring>

//#include <iostream>

int gwin(std::vector<std::string> listG)
{
    if (!initscr()) {
        return 1;  // Ошибка инициализации
    };

    cbreak();          // режим без буферизации
    noecho();         // не отображать вводимые символы
    curs_set(0);      // скрыть курсор
    refresh();
    setlocale(LC_ALL, "");

    // Размеры окна
    const int width = 40;
    const int height = 10;

    // Вычисляем координаты для центрирования окна
    int start_y = (LINES - height) / 2;
    int start_x = (COLS - width) / 2;

    WINDOW *win = newwin(height, width, start_y, start_x);
    //WINDOW *win = newwin(60, 80, 5, 5); // высота, ширина, y, x
    box(win, 0, 0);                     // рамка вокруг окна
    box(win, 2, 2);                     // рамка вокруг окна

    //start_color();                     // инициализация цветов
    //init_pair(1, COLOR_RED, COLOR_BLACK);

    
    int choice = 0;
    while(choice!='3')
    {
        clear();
        // printw("MENU:\n");
        // printw("1. Open the file\n");
        // printw("2. Save\n");
        // printw("3. EXIT\n");
        mvwprintw(win, 2, 2, "MENU:\n");
        mvwprintw(win, 2, 2, "1. Open the file\n");
        mvwprintw(win, 2, 2, "2. Save\n");
        mvwprintw(win, 2, 2, "3. EXIT\n");
        
        //printw("pressed key: \n");
        mvwprintw(win, 2, 2, "Pressed key: \n");
        if (choice=='1')
        {
            //printw("Item 1 is selected\n");
            mvwprintw(win, 2, 2, "Item 1 is selected\n");
        }else if (choice=='2')
        {
            //printw("Item 2 is selected\n");
            mvwprintw(win, 2, 2, "Item 2 is selected\n");
        }else if (choice=='3')
        {
            //printw("EXIT \n");
            mvwprintw(win, 2, 2, "EXIT \n");
//        } else{
        };

        
        mvwprintw(win, 4, 2, "RED TEXT!");
        //wattroff(win, COLOR_PAIR(1));

        refresh();
        wrefresh(win); 
        choice = getch();
    };


    //getch();
    delwin(win);
    endwin();                    // Выход из curses-режима. Обязательная команда.

    return 0;
};
