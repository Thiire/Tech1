/*
** EPITECH PROJECT, 2018
** my_find_prime_sup.c
** File description:
** my_find_prime_sup.c
*/

int my_is_prime(int);

int my_find_prime_sup(int nb)
{
    if (nb <= 2)
        return (2);
    while ( my_is_prime(nb) != 1) {
        nb++;
    }
    return (nb);
}
