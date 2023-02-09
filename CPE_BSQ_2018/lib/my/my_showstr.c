/*
** EPITECH PROJECT, 2018
** my_showstr.c
** File description:
** my_showstr.c
*/

#include <unistd.h>
#include "my.h"

int my_putnbr_base(int, char const *);

int my_putstr(char const *);

int my_display(int str, char *base)
{
    write(1, "\\", 1);
    if (str >= 0 && str < 16) {
        write(1, "0", 1);
        my_putnbr_base(str, base);
    } else {
        my_putnbr_base(str, base);
    }
    return (0);
}

int my_showstr(char const *str)
{
    char base[17] = "0123456789abcdef";
    int i = 0;

    for (i = 0; str[i] != '\0' ; i++) {
        if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127) {
            my_display(str[i], base);
        }
        else  {
            write(1, &str[i], 1);
        }
    }
    return (0);
}
