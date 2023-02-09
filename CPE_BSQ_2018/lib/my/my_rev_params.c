/*
** EPITECH PROJECT, 2018
** my_rev_params.c
** File description:
** param
*/

#include <unistd.h>

int my_putstr(char *);

char my_rev_params(int ac, char **str)
{
    for (int i = ac - 1; i >= 0 && str[i] != NULL; i--)
    {
        my_putstr(str[i]);
    }
    return (0);
}
