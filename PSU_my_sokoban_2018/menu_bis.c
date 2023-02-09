/*
** EPITECH PROJECT, 2018
** menu_bis.c
** File description:
** menu_bis.c
*/

#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main_menu(void);

int recup(char *);

void my_check(int x, int y)
{
    int i = 0;

    while (x > getmaxx(stdscr) || y > getmaxy(stdscr)) {
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 8, "to short"
        " window");
        refresh();
    }
    clear();
    endwin();
}

void enter_cond_2(int n, int map)
{
    if (map == 10 && n == 3) {
        recup("bonus/level-1");
        main_menu();
    } else if (map == 10 && n == 2) {
        recup("bonus/level-2");
        main_menu();
    }
    if (map == 10 && n == 1) {
        recup("bonus/level-3");
        main_menu();
    } else if (map == 10 && n == 0) {
        recup("bonus/level-4");
        main_menu();
    }
}

void my_color_2(int n, int map)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    switch (n) {
        case 3 :
            mvprintw(3, getmaxx(stdscr) / 2 - 7, "%s", "Level-1 : easy");
            break;
        case 2 :
            mvprintw(4, getmaxx(stdscr) / 2 - 7, "%s", "Level-2 : easy");
            break;
        case 1 :
            mvprintw(5, getmaxx(stdscr) / 2 - 8, "%s", "Level-3 : medium");
            break;
        case 0 :
            mvprintw(6, getmaxx(stdscr) / 2 - 8, "%s", "Level-4 : medium");
            break;
        default :
            break;
    }
    attroff(COLOR_PAIR(1));
    enter_cond_2(n, map);
}

void level(int map)
{
    int n = 3;

    clear();
    while (map != 32) {
        my_check(30, 10);
        mvprintw(0, getmaxx(stdscr) / 2 - 6, "%s", "Level select");
        mvprintw(1, getmaxx(stdscr) / 2 - 8, "%s", "----------------");
        mvprintw(3, getmaxx(stdscr) / 2 - 7, "%s", "Level-1 : easy");
        mvprintw(4, getmaxx(stdscr) / 2 - 7, "%s", "Level-2 : easy");
        mvprintw(5, getmaxx(stdscr) / 2 - 8, "%s", "Level-3 : medium");
        mvprintw(6, getmaxx(stdscr) / 2 - 8, "%s", "Level-4 : medium");
        my_color_2(n, map);
        refresh();
        map = getch();
        n += (map == 65 && n < 3) ? 1 : 0;
        n -= (map == 66 && n > 0) ? 1 : 0;
    }
    main_menu();
}
