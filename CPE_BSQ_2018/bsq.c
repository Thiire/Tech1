/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** bsq.c
*/

#include "lib/my/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int display(char **, int *);

char **cut(char *);

int *to_compare(int *res, int *result)
{
    if (result[0] > res[0])
        return (result);
    else if (res[0] > result[0]) {
        result[0] = res[0];
        result[1] = res[1];
        result[2] = res[2];
        return (result);
    }
    if (result[2] < res[2])
        return (result);
    else if (result[2] = res[2] && result[1] < res[1])
        return (result);
    else if (res[1] < result[1]) {
        result[0] = res[0];
        result[1] = res[1];
        result[2] = res[2];
        return (result);
    }
    return (result);
}

int *to_store(char **stock, int i, int y, int *result)
{
    int length = 0;
    int height = 0;
    int j = 0;
    int res[3] = {0, 0, 0};

    for (length = i; stock[y][length] == '.'; length++);
    length = length - i;
    for (height = 1; height < length; height++) {
        for (j = 0; j < length; j++) {
            length = (stock[y + height][j + i] == '.') ? length : j;
        }
    }
    res[0] = length;
    res[1] = i;
    res[2] = y - 1;
    return (to_compare(res, result));
}

int *to_find(char **stock, int *result)
{
    int i = 0;
    int y = 1;
    int nbr = my_getnbr(stock[0]);

    for (y = 1; y < nbr || y == nbr; y++) {
        for (i = 0; stock[y][i] != '\0'; i++) {
            if (stock[y][i] == '.');
                result = to_store(stock, i, y, result);
        }
    }
    return (result);
}

int *to_cut(char *stack, int *result)
{
    int n = 0;
    int i = 0;
    char **stock = malloc(sizeof(char) * 100000);

    for (int y = 0; y < 20000; y++)
        stock[y] = malloc(sizeof(char) * 20000);
    for (int i = 0; i < 10000; i++)
        for (int y = 0; y < 10000; y++)
            stock[i][y] = '0';
    for (int y = 0; stack[y] != '\0'; y++) {
        stock[n][i] = stack[y];
        if (stack[y] == '\n') {
            stock[n][i] = '\0';
            i = 0;
            n++;
        } else
            i++;
    }
    return (to_find(stock, result));
}

int main(int ac, char **av)
{
    int of = 0;
    char *stack;
    struct stat board;
    int *result = malloc(sizeof(char) * 3);

    if (ac != 2)
        return (84);
    of = open(av[1], O_RDONLY);
    if (of == -1)
        return (84);
    if (stat(av[1], &board) < 0)
        return (84);
    stack = malloc(sizeof(char) * board.st_size);
    read(of, stack, board.st_size);
    result = to_cut(stack, result);
    display(cut(stack), result);
    return (0);
}
