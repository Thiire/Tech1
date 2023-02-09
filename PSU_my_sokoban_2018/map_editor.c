/*
** EPITECH PROJECT, 2018
** map_editor.c
** File description:
** map_editor.c
*/

#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int recup(char *);

void my_check(int, int);

int choise_2(int map, char *str, int i)
{
    if (map == 88 || map == 120) {
        str[i] = 'X';
        i++;
    } else if (map == 79 || map == 111) {
        str[i] = 'O';
        i++;
    } else if (map == 80 || map == 112) {
        str[i] = 'P';
        i++;
    }
    return (i);
}

int choise(int map, char *str, int i)
{
    if (map == 127 && i != 0) {
        str[i - 1] = '\0';
        i--;
    } else if (map == 35) {
        str[i] = '#';
        i++;
    } else if (map == 32) {
        str[i] = ' ';
        i++;
    }
    if (map == 10) {
        str[i] = '\n';
        i++;
    }
    return (choise_2(map, str, i));
}

char *map_checker(char *str)
{
    int i = 6;
    int length = 0;
    int map = 0;

    while (map != 10 || i == 6) {
        my_check(30, 5);
        for (length = 0; str[length] != '\0'; length++);
        mvprintw(0, getmaxx(stdscr) / 2 - 2, "%s", "Name :");
        mvprintw(2, getmaxx(stdscr) / 2 - (length - 6) / 2, "%s", str + 6);
        refresh();
        map = getch();
        if ((map >= 'A' && map <= 'Z') || (map >= 'a' && map <= 'z')) {
            str[i] = map;
            i++;
        } else if (map == 127 && i != 6) {
            str[i - 1] = '\0';
            i--;
        }
    }
    return (str);
}

char *str_creator(void)
{
    char *str = malloc(sizeof(char) * 100);

    str[0] = 'b';
    str[1] = 'o';
    str[2] = 'n';
    str[3] = 'u';
    str[4] = 's';
    str[5] = '/';
    clear();
    return (str);
}

void creator(void)
{
    FILE *fo;
    char *name = malloc(sizeof(char) * 100);
    char *str = malloc(sizeof(char) * 1000);
    int length = 0;
    int map = 0;
    int i = 0;

    name = map_checker(str_creator());
    fo = fopen(name, "w");
    while (map != 9) {
        i = choise(map, str, i);
        clear();
        mvprintw(0, 0, "%s", str);
        refresh();
        map = getch();
    }
    for (length = 0; str[length] != '\0'; length++);
    fwrite(str, 1, length, fo);
    fclose(fo);
    recup(name);
}