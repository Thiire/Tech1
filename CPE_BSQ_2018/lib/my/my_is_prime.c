/*
** EPITECH PROJECT, 2018
** my_is_prime.c
** File description:
** my_is_prime.c
*/

#include <stdio.h>

int my_is_prime(int nb)
{
    int a = 2;

    if ( nb <= 1 )
        return (0);
    for (a = 2 ; nb % a > 0 ; a++) {
    }
    if (a == nb)
        return (1);
    return (0);
}
