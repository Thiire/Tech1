/*
** EPITECH PROJECT, 2019
** my_er.c
** File description:
** my_er.c
*/

#include "generator.h"

int zero(int calcul, int nombre)
{
    if (calcul == -1)
        nombre = nombre * -1;
    return (nombre);
}

int my_getnbr(char const *str)
{
    int calcul = 1;
    long nombre = 0;
    int i;

    if (str == NULL)
        return (0);
    for (i = 0 ; str[i] == '-' || str[i] == '+' ; i++)
        if (str[i] == '-')
            if (str[i+1] >= '0' && str[i+1] <= '9')
                calcul = -1;
    for (int j = i; str[j] != '\0'; j++) {
        if (str[j] < '0' || str[j] > '9')
            return (666);
        nombre = nombre * 10 + str[j] - 48;
    }
    return (zero(calcul, nombre));
}

int is_strnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}