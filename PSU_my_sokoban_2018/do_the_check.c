/*
** EPITECH PROJECT, 2018
** do_the_check.c
** File description:
** do_the_check.c
*/

#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int do_the_check_2(char **tab, int map, int x, int y)
{
    if (map == 68) {
        tab[y][x - 1] = (tab[y][x - 1] == ' ' || tab[y][x - 1] == 'O') ?
        'P' : tab[y][x - 1];
        if (tab[y][x - 1] == 'X' && (tab[y][x - 2] == ' ' || tab[y][x - 2] ==
        'O')) {
            tab[y][x - 2] = 'X';
            tab[y][x - 1] = 'P';
        }
        tab[y][x] = (tab[y][x - 1] == 'P') ? ' ' : 'P';
    } else if (map == 67) {
        tab[y][x + 1] = (tab[y][x + 1] == ' ' || tab[y][x + 1] == 'O') ?
        'P' : tab[y][x + 1];
        if (tab[y][x + 1] == 'X' && (tab[y][x + 2] == ' ' || tab[y][x + 2] ==
        'O')) {
            tab[y][x + 2] = 'X';
            tab[y][x + 1] = 'P';
        }
        tab[y][x] = (tab[y][x + 1] == 'P') ? ' ' : 'P';
    } else
        return (0);
}

int do_the_check(char **tab, int map, int x, int y)
{
    if (map == 65) {
        tab[y - 1][x] = (tab[y - 1][x] == ' ' || tab[y - 1][x] == 'O') ?
        'P' : tab[y - 1][x];
        if (tab[y - 1][x] == 'X' && (tab[y - 2][x] == ' ' || tab[y - 2][x] ==
        'O')) {
            tab[y - 2][x] = 'X';
            tab[y - 1][x] = 'P';
        }
        tab[y][x] = (tab[y - 1][x] == 'P') ? ' ' : 'P';
    } else if (map == 66) {
        tab[y + 1][x] = (tab[y + 1][x] == ' ' || tab[y + 1][x] == 'O') ?
        'P' : tab[y + 1][x];
        if (tab[y + 1][x] == 'X' && (tab[y + 2][x] == ' ' || tab[y + 2][x] ==
        'O')) {
            tab[y + 2][x] = 'X';
            tab[y + 1][x] = 'P';
        }
        tab[y][x] = (tab[y + 1][x] == 'P') ? ' ' : 'P';
    } else
        return (do_the_check_2(tab, map, x, y));
}