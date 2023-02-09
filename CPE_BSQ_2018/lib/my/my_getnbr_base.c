/*
** EPITECH PROJECT, 2018
** my_getnbr_base.c
** File description:
** my_getnbr_base.c
*/

#include <unistd.h>

int my_strlen(char const *);

int my_put_nbr(int);

int my_compute_power_rec(int, int);

int trocs(char const *str, char const *base)
{
    int result = 0;
    int nbr = 0;
    int i = 0;
    int	x = 0;
    int y = 0;
    int length = my_strlen(base);

    for (x = my_strlen(str) - 1 ; x != -1 ; x--) {
        for (i = 0 ; str[x] != base[i] ; i++) {
        }
        result = i;
        nbr += result * my_compute_power_rec(length, y);
        y++;
    }
    my_put_nbr(nbr);
    return (0);
}

int my_getnbr_base(char const *str, char const *base)
{
    trocs(str, base);
    return (0);
}
