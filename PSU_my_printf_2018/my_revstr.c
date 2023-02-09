/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** my_revstr.c
*/

#include <stdio.h>

char    *my_revstr(char *str)
{
    char stock;
    int i = 0;
    int j = 0;

    for (i = 0 ; str[i] != '\0' ; i++) {
    }
    i--;
    for (j = 0; j < (i / 2) + 1; j++) {
        stock = str[j];
        str[j] = str[i - j];
        str[i - j] = stock;
    }
    return (str);
}
