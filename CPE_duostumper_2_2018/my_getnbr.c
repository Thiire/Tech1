/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "boogle.h"

int my_getnbr(char *str)
{
    int i = 0;
    int nbr = 0;
    int check = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++)
        check += (str[i] < '0' || str[i] > '9') ? 1 : 0;
    if (check >= 1)
        return (0);
    while (str[i] != 0) {
        nbr = nbr * 10 + str[i] - '0';
        i++;
    }
    return (nbr);
}
