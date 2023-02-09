/*
** EPITECH PROJECT, 2018
** my_coloring.c
** File description:
** my_coloring.c
*/

#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int my_cut(char **);

void checking(char **av, int i, int y)
{
    int length = my_cut(av);

    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(3, COLOR_CYAN, COLOR_CYAN);
    mvprintw(i, getmaxx(stdscr) / 2 - length / 2 + y, "%c", av[i][y]);
    if (av[i][y] == 'X') {
        attron(COLOR_PAIR(1));
        mvprintw(i, getmaxx(stdscr) / 2 - length / 2 + y, "%c", av[i][y]);
        attroff(COLOR_PAIR(1));
    } else if (av[i][y] == 'P') {
        attron(COLOR_PAIR(2));
        mvprintw(i, getmaxx(stdscr) / 2 - length / 2 + y, "%c", av[i][y]);
        attroff(COLOR_PAIR(2));
    } else if (av[i][y] == 'O') {
        attron(COLOR_PAIR(3));
        mvprintw(i, getmaxx(stdscr) / 2 - length / 2 + y, "%c", av[i][y]);
        attroff(COLOR_PAIR(3));
    }
}

void my_coloring(char **av, int *result, int length)
{
    int i = 0;
    int y = 0;

    init_pair(4, COLOR_GREEN, COLOR_GREEN);
    for (i = 0; av[i][0] != '\0'; i++) {
        for (y = 0; av[i][y] != '\0'; y++) {
            checking(av, i, y);
        }
    }
    for (int n = 0; result[n] != 0; n += 2) {
        if (av[result[n]][result[n + 1]] == 'X') {
        attron(COLOR_PAIR(4));
        mvprintw(result[n], getmaxx(stdscr) / 2 - length / 2 + result[n + 1],
        "%c", av[result[n]][result[n + 1]]);
        attroff(COLOR_PAIR(4));
        mvprintw(i - 1, getmaxx(stdscr) / 2 - length / 2, "%s", av[i - 1]);
        }
    }
}