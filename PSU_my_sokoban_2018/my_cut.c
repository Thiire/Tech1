/*
** EPITECH PROJECT, 2018
** my_cut.c
** File description:
** my_cut.c
*/

#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

void main_menu(void);

void my_coloring(char **, int *, int);

int to_error(char **tab)
{
    int p = 0;
    int x = 0;
    int n = 0;
    int other = 0;

    for (int i = 0; tab[i][0] != '\0'; i++) {
        for (int y = 0; tab[i][y] != '\0'; y++) {
            n += (tab[i][y] == 'O') ? 1 : 0;
            p += (tab[i][y] == 'P') ? 1 : 0;
            x += (tab[i][y] == 'X') ? 1 : 0;
            other += (tab[i][y] != 'O' && tab[i][y] != 'X' && tab[i][y] != ' '
            && tab[i][y] != 'P' && tab[i][y] != '#') ? 1 : 0;
        }
    }
    if (p != 1 || n != x || n == 0 || x == 0 || other >= 1) {
        endwin();
        write(0, "invalid map\n", 13);
        exit(84);
    }
    return (0);
}

int my_cut(char **tab)
{
    int length1 = 0;
    int length2 = 0;

    for (int i = 0; tab[i][0] != '\0'; i++) {
        for (length1 = 0; tab[i][length1] != '\0'; length1++);
        length2 = (length1 >= length2) ? length1 : length2;
    }
    return (length2);
}

int *store(char **tab, int *result)
{
    int y = 0;
    int stock = 0;

    for (int i = 0; tab[i][0] != '\0'; i++) {
        for (y = 0; tab[i][y] != '\0'; y++) {
            result[stock] = (tab[i][y] == 'O') ? i : 0;
            result[stock + 1] = (tab[i][y] == 'O') ? y : 0;
            stock += (tab[i][y] == 'O') ? 2 : 0;
        }
    }
    return (result);
}

int my_clear(char **tab, int *result)
{
    int length = 0;

    clear();
    for (length = 0; result[length] != 0; length += 2) {
        if (tab[result[length]][result[length + 1]] == ' ')
            tab[result[length]][result[length + 1]] = 'O';
    }
    return (0);
}

int to_control(char **tab, int *result)
{
    int res = 0;

    init_pair(1, COLOR_RED, COLOR_BLACK);
    for (int length = 0; result[length] != 0; length += 2) {
        if (tab[result[length]][result[length + 1]] == 'X') {
        } else
            res++;
    }
    if (res == 0) {
        clear();
        my_coloring(tab, result, my_cut(tab));
        refresh();
        usleep(1000000);
        clear();
        mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 4, "Victory");
        refresh();
        usleep(3000000);
        main_menu();
    }
    return (0);
}