/*
** EPITECH PROJECT, 2018
** my_putnbr_p.c
** File description:
** my_putnbr_p.c
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *);

char    *my_revstr(char *);

int c_putstr(char const *);

char *modifier(unsigned long int nbr, char const *base)
{
    char number[100];
    int	x = 0;
    int i;
    int	diff = 0;
    int high = my_strlen(base) - 1;

    for (i = 0 ; nbr != 0 ; i++) {
        diff = nbr % high;
        nbr = nbr / high;
        number[i] = base[diff];
    }
    return (my_revstr(number));
}

int my_putnbr_p(unsigned long int nbr, char const *base, int *nombre)
{
    char check = (nombre[2] == 1) ? '0' : ' ';
    char *result;

    result = modifier(nbr, base);
    if (nombre[0] > 0) {
        for (int i = 2; i < nombre[0] - my_strlen(result); i++) {
            write(1, &check, 1);
        }
        c_putstr(result);
        return (0);
    } else if (nombre[0] < 0) {
        c_putstr(result);
        for (int i = -2; i > nombre[0] + my_strlen(result); i--) {
            write(1, " ", 1);
        }
        return (0);
    }
    c_putstr(result);
    return (0);
}
