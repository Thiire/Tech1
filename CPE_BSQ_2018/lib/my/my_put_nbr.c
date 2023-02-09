/*
** EPITECH PROJECT, 2018
** my_put_nbr.C
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

void    my_putchar(char);

int my_put_nbr(int nb)
{
    long nbs = nb;

    if ( nbs > 10) {
        my_put_nbr(nbs / 10);
    }
    my_putchar(nbs % 10 + 48);
    return (0);
}
