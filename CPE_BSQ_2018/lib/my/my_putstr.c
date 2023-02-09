/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <unistd.h>

void    my_putchar(char);

int my_putstr(char const *str)
{
    int i;

    for (i = 0 ; str[i] != '\0' ; i++)
    {
        my_putchar(str[i]);
    }
    write(1, "\n", 1);
    return (0);
}