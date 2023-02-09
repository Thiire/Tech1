/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "lib.h"

char **my_str_tab(char *str)
{
    int i = 0;
    int n = 0;
    int j = 0;
    char **tab;

    for (int y = 0; str[y] != '\0'; y++)
        n += (str[y] == ' ' || str[y] == '\t') ? 1 : 0;
    tab = my_double_malloc(n + 3, 200);
    while (str[i] != '\0') {
        for (n = 0; str[i] != '\0' && str[i] != ' ' && str[i] != '\t';
        i++, n++) {
            tab[j][n] = str[i];
        }
        for (; str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'); i++);
        j++;
    }
    tab[j] = NULL;
    return (tab);
}
