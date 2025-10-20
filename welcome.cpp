#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>

//#include <vector>
#include <string>
#include <cstring>

//#include <iostream>

int welcome()
{
    //initscr();     // Переход в curses-режим
    // Инициализация ncurses
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


    //WINDOW *win = newwin(60, 80, 5, 5); // высота, ширина, y, x
    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);                     // рамка вокруг окна
    

    //start_color();                     // инициализация цветов
    //init_pair(1, COLOR_RED, COLOR_BLACK);

    
    //wattron(win, COLOR_PAIR(1));
    //clear();

    //mvwprintw(win, 4, 2, "WELCOME!\n");

    // Текст для вывода
    const char *text = "WELCOME!";
    const char *subtitle = " Это окно ncurses.";

    // Выводим текст по центру окна
    mvwprintw(win, 2, (width - strlen(text)) / 2, text);
    mvwprintw(win, 4, (width - strlen(subtitle)) / 2, subtitle);    
        //mvwprintw(win, 4, 2, "Красный текст!");
    //wattroff(win, COLOR_PAIR(1));



    // char hello[] = "Hello, world!";
    // mvaddstr(LINES/2, (COLS-strlen(hello))/2, hello);


    wrefresh(win); 

    getch();

    delwin(win);

    endwin();                    // Выход из curses-режима. Обязательная команда.

    return 0;
};
