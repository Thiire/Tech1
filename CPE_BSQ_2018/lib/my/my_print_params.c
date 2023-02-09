/*
** EPITECH PROJECT, 2018
** my_print_params.c
** File description:
** my_print_params.c
*/

#include <unistd.h>

void    my_putchar(char);

int my_putstr(char const *);

int my_print_params(char **str)
{
    for (int i = 0; str[i] != NULL ; i++) {
        my_putstr(str[i]);
    }
    return (0);
}