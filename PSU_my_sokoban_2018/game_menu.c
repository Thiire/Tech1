/*
** EPITECH PROJECT, 2018
** game_menu.c
** File description:
** game_menu.c
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

void my_check(int, int);

int recup(char *);

int enter_cond_3(int n, int map, char *name)
{
    if (map == 10 && n == 3)
        return (1);
    if (map == 10 && n == 2)
        recup(name);
    if (map == 10 && n == 1) {
        flushinp();
        map = 0;
        main_menu();
    }
    if (map == 10 && n == 0) {
        endwin();
        exit (0);
    }
    return (0);
}

int my_color_3(int n, int map, char *name)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    switch (n) {
        case 3 :
            mvprintw(3, getmaxx(stdscr) / 2 - 3, "%s", "Resume");
            break;
        case 2 :
            mvprintw(4, getmaxx(stdscr) / 2 - 3, "%s", "Retry");
            break;
        case 1 :
            mvprintw(5, getmaxx(stdscr) / 2 - 2, "%s", "Menu");
            break;
        case 0 :
            mvprintw(6, getmaxx(stdscr) / 2 - 2, "%s", "Quit");
            break;
        default :
            break;
    }
    attroff(COLOR_PAIR(1));
    return (enter_cond_3(n, map, name));
}

int game_menu(char *name)
{
    int map = 0;
    int n = 3;

    clear();
    while (1) {
        my_check(30, 10);
        mvprintw(0, getmaxx(stdscr) / 2 - 3, "%s", "Pause");
        mvprintw(1, getmaxx(stdscr) / 2 - 5, "%s", "-----------");
        mvprintw(3, getmaxx(stdscr) / 2 - 3, "%s", "Resume");
        mvprintw(4, getmaxx(stdscr) / 2 - 3, "%s", "Retry");
        mvprintw(5, getmaxx(stdscr) / 2 - 2, "%s", "Menu");
        mvprintw(6, getmaxx(stdscr) / 2 - 2, "%s", "Quit");
        if (my_color_3(n, map, name) == 1)
            return (0);
        refresh();
        map = getch();
        n += (map == 65 && n < 3) ? 1 : 0;
        n -= (map == 66 && n > 0) ? 1 : 0;
    }
}
