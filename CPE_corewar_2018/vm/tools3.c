/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** tools3.c
*/

#include "../includes/corewar.h"

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

char *cnc(char *s1, char *s2)
{
    char *res = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 3));
    int i = 0;

    for (i = 0; s1[i] != '\0'; i++)
        res[i] = s1[i];
    for (int j = 0; s2[j] != '\0'; j++, i++)
        res[i] = s2[j];
    res[i] = '\0';
    return (res);
}

char *bin_hex(char *r)
{
    int res = 0;
    int res1 = 0;

    res += (r[0] == '1') ? 8 : 0;
    res += (r[1] == '1') ? 4 : 0;
    res += (r[2] == '1') ? 2 : 0;
    res += (r[3] == '1') ? 1 : 0;
    res1 += (r[4] == '1') ? 8 : 0;
    res1 += (r[5] == '1') ? 4 : 0;
    res1 += (r[6] == '1') ? 2 : 0;
    res1 += (r[7] == '1') ? 1 : 0;
    return (cnc(my_getnbr_base((long)res, "0123456789abcdef"),
    my_getnbr_base((long)res1, "0123456789abcdef")));
}

char *summ_calc(char *a, char *b, int type)
{
    int nb = my_strlen(b);

    if (type == 1) {
        for (int i = 0, j = 8 - nb; b[i] != '\0'; i++, j++)
            a[j] += b[i] - a[j];
    } else if (type == 2) {
        for (int i = 0; a[i] != '\0'; i++)
            a[i] -= b[i] - 48;
    }
    return (a);
}