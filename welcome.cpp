#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <cstring>

#include <thread>
#include <chrono>

int welcome()
{
    // Инициализация ncurses
    if (!initscr()) {
        return 1;  
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
    box(win, 0, 0);                     // рамка вокруг окна
    
    // Текст для вывода
    const char *text = "WELCOME!";
    const char *subtitle = " The window - ncurses.";

    // Выводим текст по центру окна
    mvwprintw(win, 2, (width - strlen(text)) / 2, text);
    mvwprintw(win, 4, (width - strlen(subtitle)) / 2, subtitle);    
    
    wrefresh(win); 

    std::this_thread::sleep_for(std::chrono::seconds(3));

    delwin(win);
    endwin();                    // Выход из curses-режима. Обязательная команда.

    return 0;
};
