/*
** EPITECH PROJECT, 2018
** c_putstr.c
** File description:
** c_putstr.c
*/

#include <unistd.h>

void    c_putchar(char);

int c_putstr(char const *str)
{
    int i;

    for (i = 0 ; str[i] != '\0' ; i++) {
        c_putchar(str[i]);
    }
    return (0);
}