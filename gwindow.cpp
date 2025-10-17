#include <ncurses.h>

#include <vector>
#include <string>

//#include <iostream>

int gwin(std::vector<std::string> listG)
{
    initscr();     // Переход в curses-режим

    cbreak();          // режим без буферизации
    noecho();         // не отображать вводимые символы

    setlocale(LC_ALL, "");

    int choice = 0;
    while(choice!='3')
    {
        clear();
        printw("MENU:\n");
        printw("1. Open the file\n");
        printw("2. Save\n");
        printw("3. EXIT\n");
        //refresh();
        
        printw("pressed key: \n");
        if (choice=='1')
        {
            printw("Item 1 is selected\n");
        }else if (choice=='2')
        {
            printw("Item 2 is selected\n");
        }else if (choice=='3')
        {
            printw("EXIT \n");
//        } else{
        };

        refresh();
        choice = getch();
    };


    // int choice = 0;
    // while (choice != 3) {
    //     clear();
    //     printw("MENU:\n");
    //     printw("1. Open the file\n");
    //     printw("2. Save\n");
    //     printw("3. EXIT\n");
    //     int choice = getch();
    //     switch(choice) {
    //         case 1:
    //             printw("Выбран пункт 1\n");
    //             break;
    //         case 2:
    //             printw("Выбран пункт 2\n");
    //             break;
    //         case 3:
    //             printw("Выход из программы\n");
    //             break;
    //     };
    //     refresh();
    // };

    // printw("Нажмите любую клавишу...\n");
    // int key = getch();
    // printw("Нажата клавиша: %c\n", key);
    // refresh();

    //getch();

    endwin();                    // Выход из curses-режима. Обязательная команда.

    return 0;
};
