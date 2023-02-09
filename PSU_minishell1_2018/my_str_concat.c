/*
** EPITECH PROJECT, 2018
** my_str_concat.c
** File description:
** my_str_concat.c
*/

#include "mysh.h"

int str_lgh(char *str)
{
    int length = 0;

    for (length = 0; str[length] != '\0'; length++);
    return (length);
}

char *my_str_concat(char *fst, char *scd)
{
    char *result = malloc(sizeof(char) * (str_lgh(fst) + str_lgh(scd) + 1));
    int i = 0;

    for (int n = 0; fst[n] != '\0'; n++, i++) {
        result[i] = fst[n];
    }
    for (int n = 0; scd[n] != '\0'; n++, i++) {
        result[i] = scd[n];
    }
    result[i] = '\0';
    return (result);
}