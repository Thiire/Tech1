/*
** EPITECH PROJECT, 2018
** my_putnbr_base.c
** File description:
** my_putnbr_base.c
*/

#include <unistd.h>

int my_strlen(char const *);

char    *my_revstr(char *);

int my_putstr(char const *);

int trade(int nbr, char const *base)
{
    char number[100];
    int	x = 0;
    int i;
    int	diff = 0;
    int high = my_strlen(base);

    for (i = 0 ; nbr != 0 ; i++) {
        diff = nbr % high;
        nbr = nbr / high;
        for (x = 0 ; x < diff ; x++) {
        }
        if (diff != 0)
            number[i] = base[x];
        else if (diff == 0)
            number[i] = base[0];
    }
    number[i] = '\0';
    my_putstr(my_revstr(number));
    return (0);
}

int my_putnbr_base(int nbr, char const *base)
{
    if ( nbr < 0 ) {
        write(1, "-", 1);
        nbr = nbr * -1;
    }
    trade(nbr, base);
    return (0);
}
