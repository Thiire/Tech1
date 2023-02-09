/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** menu.c
*/

#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void my_check(int, int);

void level(int);

void main_menu(void);

int recup(char *);

void creator(void);

void option(int map)
{
    clear();
    while (map != 32) {
        my_check(60, 20);
        mvprintw(0, getmaxx(stdscr) / 2 - 6, "%s", "Description");
        mvprintw(1, getmaxx(stdscr) / 2 - 8, "%s", "---------------");
        mvprintw(3, 0, "%s", "Containing '#' for walls, "
        "'P' for the player, 'X' for boxes and 'O' for storage locations.");
        mvprintw(6, getmaxx(stdscr) / 2 - 3, "%s", "Usage");
        mvprintw(7, getmaxx(stdscr) / 2 - 8, "%s", "---------------");
        mvprintw(9, 0, "%s", "Use the [Arrow key] to move your player, use "
        "[Space] to return and [Enter] to confirm");
        mvprintw(12, getmaxx(stdscr) / 2 - 3, "%s", "Editor");
        mvprintw(13, getmaxx(stdscr) / 2 - 8, "%s", "---------------");
        mvprintw(15, 0, "%s", "Create a map with '#', 'P', 'X', 'O', you can "
        "delete with [Backspace], go to the next line with [Enter]. Save and "
        "launch it with [Tab]");
        refresh();
        map = getch();
    }
    main_menu();
}

void enter_cond(int n, int map)
{
    if (map == 10 && n == 3) {
        flushinp();
        map = 0;
        level(map);
    }
    if (map == 10 && n == 2)
        creator();
    if (map == 10 && n == 1)
        option(map);
    if (map == 10 && n == 0) {
        endwin();
        exit (0);
    }
}

void my_color(int n, int map)
{
    init_pair(1, 
   COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    switch (n) {
        case 3 :
            mvprintw(3, getmaxx(stdscr) / 2 - 7, "%s", "Select a level");
            break;
        case 2 :
            mvprintw(4, getmaxx(stdscr) / 2 - 5, "%s", "Map editor");
            break;
        case 1 :
            mvprintw(5, getmaxx(stdscr) / 2 - 6, "%s", "Description");
            break;
        case 0 :
            mvprintw(6, getmaxx(stdscr) / 2 - 2, "%s", "Quit");
            break;
        default :
            break;
    }
    attroff(COLOR_PAIR(1));
    enter_cond(n, map);
}

void main_menu(void)
{
    int map = 0;
    int n = 3;

    initscr();
    start_color();
    while (1) {
        my_check(30, 10);
        mvprintw(0, getmaxx(stdscr) / 2 - 3, "%s", "Sokoban");
        mvprintw(1, getmaxx(stdscr) / 2 - 5, "%s", "-----------");
        mvprintw(3, getmaxx(stdscr) / 2 - 7, "%s", "Select a level");
        mvprintw(4, getmaxx(stdscr) / 2 - 5, "%s", "Map editor");
        mvprintw(5, getmaxx(stdscr) / 2 - 6, "%s", "Description");
        mvprintw(6, getmaxx(stdscr) / 2 - 2, "%s", "Quit");
        my_color(n, map);
        refresh();
        map = getch();
        n += (map == 65 && n < 3) ? 1 : 0;
        n -= (map == 66 && n > 0) ? 1 : 0;
    }
    exit (0);
}

void main(int ag, char **av)
{
    if (ag == 1) {
        main_menu();
    } else if (ag == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
            write(0, "USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file"
            " representing the warehouse map, containing ‘#’ for walls,"
            "\n\t‘P’ for the player, ‘X’ for boxes and ‘O’ for storage"
            " locations.\n", 187);
            exit(0);
        } else
            recup(av[1]);
    }
}