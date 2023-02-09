/*
** EPITECH PROJECT, 2019
** my_er.c
** File description:
** my_er.c
*/

#include "navy.h"

char **my_double_malloc(void)
{
    char **stock = malloc(sizeof(char *) * 11);

    for (int i = 0; i < 11; i++) {
        stock[i] = malloc(sizeof(char) * 18);
        for (int n = 0; n < 18; n++)
            stock[i][n] = '\0';
    }
    return (stock);
}

void my_nputchar(char c, int output)
{
    write(output, &c, 1);
}

void my_er(char *str, int output)
{
    if (output != 1 && output != 2)
        output = 1;
    for (int i = 0; str[i] != '\0'; i++)
        my_nputchar(str[i], output);
}