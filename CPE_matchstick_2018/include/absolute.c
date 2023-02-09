/*
** EPITECH PROJECT, 2018
** absolute.c
** File description:
** absolute.c
*/

long long int length(long long int nb)
{
    int i = 0;

    for (i = 0; nb != 0; i++) {
        nb = nb / 10;
    }
    return (i);
}

long long int absolute(long long int nb)
{
    if (nb < 0) {
        nb = (nb * -1) * 10;
        return (length(nb));
    } else
        return (length(nb));
}