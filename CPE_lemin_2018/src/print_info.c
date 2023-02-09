/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** print info
*/

#include "../include/my.h"

int check_room(info_t *gen, int j)
{
    if (check_name(gen->points, j) == 84)
        return (84);
    if (gen->points[j]->type == 1) {
        my_printf("##start\n");
        if (gen->points[j]->connection[0] == NULL)
            return (84);
    }
    if (gen->points[j]->type == 1 && check_start(gen, 1, j) == 84)
        return (84);
    if (gen->points[j]->type == 2) {
        my_printf("##end\n");
        if (gen->points[j]->connection[0] == NULL)
            return (84);
    }
    if (gen->points[j]->type == 2 && check_start(gen, 2, j) == 84)
        return (84);
    return (0);
}

int print_info_room(info_t *gen, int i, int j)
{
    if (i != 0)
        my_printf("#rooms\n");
    else {
        gen->error = 1;
        return (84);
    }
    for (; j < i; j++) {
        if (check_room(gen, j) == 84) {
            gen->error = 1;
            my_printf("%s %i %i\n", gen->points[j]->room, gen->points[j]->x,
            gen->points[j]->y);
            return (84);
        }
        my_printf("%s %i %i\n", gen->points[j]->room, gen->points[j]->x,
        gen->points[j]->y);
    }
    return (0);
}

void tunnel_double(info_t *gen, char *tab, int i)
{
    int result = 0;

    for (int n = 0; gen->points[i]->connection[n] != NULL; n++) {
        result += (str_compare(gen->points[i]->connection[n], tab)) ? 1 : 0;
    }
    if (result > 1)
        gen->points[i]->error += 1;
    if (gen->points[i]->error > 1)
        gen->error = 1;
}

int tunnel_check(info_t *gen, char **tab, int j)
{
    int rs1 = -1;
    int rs2 = -1;

    for (int i = 0; i < j; i++) {
        rs1 = (str_compare(gen->points[i]->room, tab[0])) ? i : rs1;
        rs2 = (str_compare(gen->points[i]->room, tab[1])) ? i : rs2;
    }
    if (rs1 == -1 || rs2 == -1) {
        gen->error = 1;
        return (84);
    }
    for (int i = 0; i < j; i++) {
        if (str_compare(gen->points[i]->room, tab[0]))
            tunnel_double(gen, tab[1], i);
        else if (str_compare(gen->points[i]->room, tab[1]))
            tunnel_double(gen, tab[0], i);
    }
    return (0);
}

int print_info(info_t *gen, int i, int y)
{
    int j = 0;
    char **tab = NULL;

    gen->error = 0;
    my_printf("#number_of_ants\n%i\n", gen->ants);
    if (print_info_room(gen, i, 0) == 84)
        return (gen->error);
    if (y != 0 && i != 0)
        my_printf("#tunnels\n");
    else {
        gen->error = 1;
        return (gen->error);
    }
    for (; j < y && i != 0 && gen->error != 1; j++) {
        tab = my_str_to_word_array(gen->tunnel[j], '-');
        tunnel_check(gen, tab, i);
        my_printf("%s\n", gen->tunnel[j]);
    }
    return (gen->error);
}
