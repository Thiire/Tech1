/*
** EPITECH PROJECT, 2018
** my_popup.c
** File description:
** my_popup.c
*/

#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int game_menu(char *);

int my_cut(char **);

int *store(char **, int *);

int my_clear(char **, int *);

int to_control(char **, int *);

int to_error(char **);

int do_the_check(char **, int, int, int);

void my_coloring(char **, int *, int);

int to_modify(char **tab, int map, int *result)
{
    int x = 0;
    int y = 0;

    for (y = 0; tab[y][x] != 'P' && tab[y][0] != '\0'; y++) {
        for (x = 0; tab[y][x] != 'P' && tab[y][x] != '\0'; x++);
        if (tab[y][x] == 'P')
            break;
        x = 0;
    }
    do_the_check(tab, map, x, y);
    to_control(tab, result);
    return (0);
}

int to_check(int length, char **tab, int map, int *result)
{
    int i = 0;

    for (i = 0; tab[i][0] != '\0'; i++);
    if (length > getmaxx(stdscr) || i > getmaxy(stdscr)) {
        while (length > getmaxx(stdscr) || i > getmaxy(stdscr)) {
            clear();
            mvprintw(getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 8, "to short"
            " window");
            refresh();
        }
        clear();
        attroff(A_NORMAL);
        endwin();
    }
    return (to_modify(tab, map, result));
}

int display(char **av, int *result, char *name)
{
    initscr();
    start_color();
    int length = 0;
    int map = 0;

    length = my_cut(av);
    attron(A_NORMAL);
    clear();
    my_coloring(av, result, length);
    while (1) {
        if (map == 32)
            game_menu(name);
        to_check(length, av, map, result);
        my_clear(av, result);
        my_coloring(av, result, length);
        map = getch();
        refresh();
    }
    endwin();
    return (0);
}

int to_cut(char *stack, int *result, char *av)
{
    int n = 1;
    int i = 0;
    char **stc = malloc(sizeof(char) * 10000);

    for (int y = 0; y < 2000; y++)
        stc[y] = malloc(sizeof(char) * 2000);
    for (int y = 0; stack[y] != '\0'; y++) {
        stc[n][i] = stack[y];
        if (stack[y] == '\n') {
            stc[n][i] = '\0';
            i = 0;
            n++;
        } else
            i++;
    }
    stc[n][0] = (stc[n][0] != '#' && stc[n][0] != ' ') ? '\0' : stc[n][0];
    stc[n + 1][0] = '\0';
    stc++;
    to_error(stc);
    return (display(stc, store(stc, result), av));
}

int recup(char *av)
{
    int of = 0;
    char *stack;
    int *result = malloc(sizeof(int) * 100);
    struct stat board;

    of = open(av, O_RDONLY);
    stat(av, &board);
    stack = malloc(sizeof(char) * board.st_size);
    if (of == -1) {
        write(0, "invalid files\n", 15);
        return (84);
    }
    read(of, stack, board.st_size);
    to_cut(stack, result, av);
    return (0);
}
