/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** basic_funcs
*/

#include "../include/my.h"

int str_compare(char *c1, char *c2)
{
    if (c1 == NULL || c2 == NULL)
        return (0);
    if (my_strlen(c1) != my_strlen(c2))
        return (0);
    for (int i = 0; c1[i] != '\0' && c2[i] != '\0'; i++) {
        if (c1[i] != c2[i]) {
            return (0);
        }
    }
    return (1);
}

int str_tab(char **tab)
{
    int i = 0;

    if (!tab || tab[i] == NULL)
        return (0);
    for (; tab[i] != NULL; ++i);
    return (i);
}

char **my_double_malloc(int a, int b)
{
    char **stock = malloc(sizeof(char *) * a);

    for (int i = 0; i < a; i++) {
        stock[i] = malloc(sizeof(char) * b);
        for (int n = 0; n < b; n++)
            stock[i][n] = '\0';
    }
    return (stock);
}
