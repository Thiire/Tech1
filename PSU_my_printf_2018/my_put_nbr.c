/*
** EPITECH PROJECT, 2018
** my_put_nbr.C
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include <stdio.h>

void    c_putchar(char);

long long int absolute(long long int nb);

int my_put_nbr(long long int nb)
{
    long long int nbs = nb;

    if (nbs < 0) {
        c_putchar('-');
        nbs = nbs * -1;
    }
    if (nbs > 10) {
        my_put_nbr(nbs / 10);
    }
    c_putchar(nbs % 10 + 48);
    return (0);
}

int my_put_nbrs(long long int nb, int *nombre)
{
    char check = (nombre[2] == 1) ? '0' : ' ';

    if (nombre[0] > 0) {
        for (int i = 0; i < nombre[0] - absolute(nb); i++)
            write(1, &check, 1);
        my_put_nbr(nb);
    } else if (nombre[0] < 0) {
        my_put_nbr(nb);
        for (int i = 0; i > nombre[0] + absolute(nb); i--)
            write(1, " ", 1);
    } else
        my_put_nbr(nb);
    return (0);
}