/*
** EPITECH PROJECT, 2019
** my_malloc.c
** File description:
** my_malloc.c
*/

#include <unistd.h>
#include <stdlib.h>

char *my_malloc(int nb)
{
    char *str = malloc(sizeof(char) * nb + 1);

    for (int n = 0; n < nb + 1; n++)
        str[n] = '\0';
    return (str);
}
