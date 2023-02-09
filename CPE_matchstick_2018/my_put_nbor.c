/*
** EPITECH PROJECT, 2018
** my_put_nbor.C
** File description:
** my_put_nbor.c
*/

#include <unistd.h>

void my_putchor(char c)
{
    write(2, &c, 1);
}

int my_put_nbor(int nb)
{
    long nbs = nb;

    if (nbs >= 10) {
        my_put_nbor(nbs / 10);
    }
    my_putchor(nbs % 10 + 48);
    return (0);
}
