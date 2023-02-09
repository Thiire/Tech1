/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** pushing_ants
*/

#include "../include/my.h"

void print_one(path_t *p)
{
    for (int i = 1; i < p->result; i++)
        my_printf("P1-%s\n", p->way[i]);
}

void print_ant(int j, path_t *p, int ants)
{
    for (int i = p->result - 1, n = p->result - 3; i < p->result; i++, n--) {
        my_printf("P%d-%s", j, p->way[i]);
        for (int k = 1; k <= n + 1 && j + k <= ants; k++)
            my_printf(" P%d-%s", j + k, p->way[i - k]);
        my_printf("\n");
    }
    if (ants != 2)
        my_printf("P%d-%s\n", j + 1, p->way[p->result - 1]);
}

int ants_check(path_t *p, int i, int k)
{
    if (i - k < 0)
        return (p->result - 1);
    return (i - k);
}

void ants_pushing(path_t *p, int ants)
{
    int j = 1;

    for (int i = 1, n = 0; i < p->result; i++, n++) {
        my_printf("P%d-%s", j, p->way[i]);
        for (int k = 1; k <= n && j + k <= ants; k++)
            my_printf(" P%d-%s", j + k, p->way[i - k]);
        my_printf("\n");
    }
    j++;
    for (int i = p->result - 1; j < ants - 1; i++, j++) {
        my_printf("P%d-%s", j, p->way[i]);
        for (int k = 1; k < p->result - 1 && j + k <= ants; k++)
            my_printf(" P%d-%s", j + k, p->way[ants_check(p, i, k)]);
        my_printf("\n");
        i = (i == p->result - 1) ? p->result - 2 : i;
    }
    print_ant(j, p, ants);
}