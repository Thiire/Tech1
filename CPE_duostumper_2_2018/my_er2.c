/*
** EPITECH PROJECT, 2019
** my_er2.c
** File description:
** my_er2.c
*/

#include "boogle.h"

char *str_cpy(char *str)
{
    int length1 = my_strlen(str);
    char *result = malloc(sizeof(char) * length1 + 1);

    for (int i = 0; i < length1; i++)
        result[i] = str[i];
    result[length1] = '\0';
    return (result);
}

int str_compare(char *c1, char *c2)
{
    if (my_strlen(c1) != my_strlen(c2))
        return (0);
    for (int i = 0; c1[i] != '\0' && c2[i] != '\0'; i++) {
        if (c1[i] != c2[i]) {
            return (0);
        }
    }
    return (1);
}