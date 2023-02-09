/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *);

int my_putstr(char const *str, int *nombre)
{
    int i;

    if (nombre[0] > 0) {
        for (int y = 0; y < nombre[0] - my_strlen(str); y++)
            write(1, " ", 1);
        for (i = 0 ; str[i] != '\0' ; i++)
            write(1, &str[i], 1);
    } else if (nombre[0] < 0) {
        for (i = 0 ; str[i] != '\0' ; i++)
            write(1, &str[i], 1);
        for (int y = 0; y > nombre[0] + my_strlen(str); y--)
            write(1, " ", 1);
    } else
        for (i = 0 ; str[i] != '\0' ; i++)
            write(1, &str[i], 1);
    return (0);
}