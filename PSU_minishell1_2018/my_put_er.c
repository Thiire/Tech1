/*
** EPITECH PROJECT, 2018
** my_put_er.c
** File description:
** my_put_er.c
*/

#include "mysh.h"

void my_er_disp(char c)
{
    write(2, &c, 1);
}

void my_no_er_disp(char c)
{
    write(1, &c, 1);
}

int my_er(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_er_disp(str[i]);
    if (isatty(0) == 0)
        exit (1);
    return (0);
}

int my_no_er(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_no_er_disp(str[i]);
    return (0);
}