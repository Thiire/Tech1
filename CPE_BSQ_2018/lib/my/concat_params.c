/*
** EPITECH PROJECT, 2018
** concat_params.c
** File description:
** concat_params
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char    *concat_params(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int secondS = 0;
    char *str;
    str = malloc(sizeof(char) * (argc + 1));

    if (str == NULL)
        return (NULL);
    for (i = 0 ; i < argc ; i++) {
        for ( secondS = 0 ; argv[i][j] != '\0' ; secondS++) {
            str[secondS] = argv[i][j];
            j++;
        }
        j = 0;
    }
    return (str);
}
