/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** tools.c
*/

#include "../includes/corewar.h"

int spe_num(char *str)
{
    for (; str[0] < '1' || str[0] > '9'; str++);
    return (my_getnbr(str));
}

char **my_str_tab(char *str)
{
    int i = 0;
    int n = 0;
    int j = 0;
    char **tab;

    for (int y = 0; str[y] != '\0'; y++)
        n += (str[y] == ' ' || str[y] == ',') ? 1 : 0;
    tab = my_double_malloc(n + 3, 200);
    while (str[i] != '\0') {
        for (n = 0; str[i] != '\0' && str[i] != ' ' && str[i] != ',';
        i++, n++) {
            tab[j][n] = str[i];
        }
        for (; str[i] != '\0' && (str[i] == ' ' || str[i] == ','); i++);
        j++;
    }
    tab[j] = NULL;
    return (tab);
}

char *cn(char *s1)
{
    char *res = malloc(sizeof(char) * (my_strlen(s1) + 1));
    int i = 0;

    for (i = 0; s1[i] != '\0'; i++)
        res[i] = s1[i];
    res[i] = '\0';
    return (res);
}

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
