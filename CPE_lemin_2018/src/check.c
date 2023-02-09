/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** check
*/

#include "../include/my.h"

int check_start(info_t *gen, int nb, int j)
{
    int end = 0;
    int start = 0;

    for (int i = 0; i < j && nb == 1; i++) {
        start += (gen->points[i]->type == 1) ? 1 : 0;
        if (gen->points[i]->type == 1 && gen->points[i]->connection[0] == NULL)
            return (84);
    }
    for (int i = 0; i < j && nb == 2; i++) {
        end += (gen->points[i]->type == 2) ? 1 : 0;
        if (gen->points[i]->type == 2 && gen->points[i]->connection[0] == NULL)
            return (84);
    }
    if (start == 1 && nb == 1)
        return (84);
    else if (end == 1 && nb == 2)
        return (84);
    return (0);
}

int check_name(coord_t **coord, int i)
{
    int check = 0;
    int test = 0;

    for (int j = 0; j < i && check != 1 && test != 1;
    j++) {
        if (j != i) {
            check += (str_compare(coord[i]->room, coord[j]->room)) ? 1 : 0;
            test += ((coord[i]->x == coord[j]->x) && (coord[i]->y
            == coord[j]->y)) ? 1 : 0;
        }
    }
    if (check == 1 || test == 1)
        return (84);
    return (0);
}
