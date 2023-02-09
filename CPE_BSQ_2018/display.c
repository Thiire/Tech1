/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display.c
*/

#include "lib/my/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int disp(char **res)
{
    for (int y = 0; res[y][0] == 'o' || res[y][0] == 'x' || res[y][0] == '.';
     y++) {
        my_putstr(res[y]);
    }
    return (0);
}

int display(char **res, int *result)
{
    int w = 0;

    if (result[0] == 1) {
        res[result[2]][result[1]] = 'x';
        return (disp(res));
    }
    for (int n = 0; n < result[0]; n++) {
        for (w = 0; w < result[0]; w++) {
            res[result[2] + n][result[1] + w] = 'x';
        }
    }
    return (disp(res));
}

char **cut(char *stack)
{
    int n = 0;
    int i = 0;
    char **stc = malloc(sizeof(char) * 100000);

    for (int y = 0; y < 20000; y++)
        stc[y] = malloc(sizeof(char) * 20000);
    for (int i = 0; i < 10000; i++)
        for (int y = 0; y < 10000; y++)
            stc[i][y] = '0';
    for (int y = 0; stack[y] != '\0'; y++) {
        stc[n][i] = stack[y];
        if (stack[y] == '\n') {
            stc[n][i] = '\0';
            i = 0;
            n++;
        } else
            i++;
    }
    stc++;
    return (stc);
}
