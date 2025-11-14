#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>
#include <cstring>


#include <thread>
#include <chrono>

#include "tank.h"
#include "cross-zero.h"
#include "fly.h"
#include "buildg.h"

//#include <iostream>

void initW()
{
    cbreak();          // режим без буферизации
    noecho();         // не отображать вводимые символы
    curs_set(0);      // скрыть курсор
    refresh();
    setlocale(LC_ALL, "");
};

void outMenu(WINDOW* win)
{
        mvwprintw(win, 2, 2, "MENU:\n");

        // listG.push_back("1. Tank");
        mvwprintw(win, 4, 2, "1. Tank\n");

        // listG.push_back("2. X / 0");
        mvwprintw(win, 6, 2, "2. X / 0\n");

        // listG.push_back("3. Fly");
        mvwprintw(win, 8, 2, "3. Fly\n");

        // listG.push_back("4. building a graph");   
        mvwprintw(win, 10, 2, "4. Building a graph\n");

        // listG.push_back("EXIT");   
        mvwprintw(win, 12, 2, "5. EXIT\n");

        //refresh();
        
};

int selection()
{
    if (!initscr()) {
        return 1;  // Ошибка инициализации
    };

    initW();

    // Размеры окна
    const int width = 60;
    const int height = 20;

    // Вычисляем координаты для центрирования окна
    int start_y = (LINES - height) / 2;
    int start_x = (COLS - width) / 2;

    WINDOW *win = newwin(height, width, start_y, start_x);

    //WINDOW *win = newwin(60, 80, 5, 5); // высота, ширина, y, x
    //box(win, 0, 0);                     // рамка вокруг окна
    //box(win, 2, 2);                     // рамка вокруг окна

    //start_color();                     // инициализация цветов
    //init_pair(1, COLOR_RED, COLOR_BLACK);

    
    char choice = '0';
    while(choice!='5')
    {
        //wattron(win, COLOR_PAIR(1));        
        outMenu(win);
       
        if (choice=='1')
        {
            //printw("Tank\n");
            mvwprintw(win, 14, 2, "Pressed key: \n");
            mvwprintw(win, 16, 2, "Item 1 is selected\n");
            box(win, 0, 0); 
            //refresh();
            wrefresh(win); 
            std::this_thread::sleep_for(std::chrono::seconds(3));

            tank();
            choice='0';
            mvwprintw(win, 14, 2, "  \n");
            mvwprintw(win, 16, 2, " \n");
            continue;

        }else if (choice=='2')
        {
            //printw("X / 0\n");
            mvwprintw(win, 14, 2, "Pressed key: \n");
            mvwprintw(win, 16, 2, "Item 2 is selected\n");
            box(win, 0, 0); 
            //refresh();
            wrefresh(win); 
            std::this_thread::sleep_for(std::chrono::seconds(3));          
            
            crossZero();
            choice='0';
            mvwprintw(win, 14, 2, "  \n");
            mvwprintw(win, 16, 2, " \n");
            continue;


        }else if (choice=='3')
        {
            //printw("Fly \n");
            mvwprintw(win, 14, 2, "Pressed key: \n");
            mvwprintw(win, 16, 2, "Item 3 is selected\n");
            box(win, 0, 0); 
            //refresh();
            wrefresh(win); 
            std::this_thread::sleep_for(std::chrono::seconds(3));         
            
            fly();
            choice='0';
            mvwprintw(win, 14, 2, "  \n");
            mvwprintw(win, 16, 2, " \n");
            continue;


        }else if (choice=='4')
        {
            //printw("Graph \n");
            mvwprintw(win, 14, 2, "Pressed key: \n");
            mvwprintw(win, 16, 2, "Item 4 is selected\n");
            box(win, 0, 0); 
            //refresh();
            wrefresh(win); 
            std::this_thread::sleep_for(std::chrono::seconds(3));

            buildg();
            choice='0';
            mvwprintw(win, 14, 2, " \n");
            mvwprintw(win, 16, 2, " \n");
            continue;


        // }else if (choice=='5')
        // {
        //     //printw("EXIT \n");
        //     mvwprintw(win, 16, 2, "Item 5 is selected\n");
        } else{
            box(win, 0, 0); 
            //refresh();
            wrefresh(win); 
            std::this_thread::sleep_for(std::chrono::seconds(3));
        };

        // mvwprintw(win, 14, 2, "Red TEXT!");
        //wattroff(win, COLOR_PAIR(1));
        choice = getch();
        clear();
    };

    // if (choice=='1')    {        buildg();    }else
    // if (choice=='2')    {        buildg();    }else
    // if (choice=='3')    {        buildg();    }else
    // if (choice=='4')    {        buildg();    };    
    return 0;
};
