/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** lib_p3
*/

#include "lib.h"

void my_putchar(char c, int output)
{
    write(output, &c, 1);
}

char *my_cpy(char *str)
{
    int length = my_strlen(str);
    int i = 0;
    char *new = malloc(sizeof(char) * length + 1);

    for (i = 0; str[i] != '\0'; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

int is_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int my_empty(char *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        for (j = i; str[j] == ' '; j++);
        if (str[j] == '\0')
            return (i);
        else
            i = j;
    }
    return (i);
}