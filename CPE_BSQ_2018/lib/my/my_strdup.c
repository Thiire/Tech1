/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char    *my_strdup(char const *src)
{
    char *str;
    int length = my_strlen(src) + 1;

    str = malloc(sizeof(char) * length);
    if (str == NULL)
        return (NULL);
    str = my_strcpy(str, str);
    str[length - 1] = '\0';
    return (str);
}
