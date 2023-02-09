/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** ffree funcs
*/

#include "../include/my.h"

void free_cord(coord_t *cord)
{
    for (int i = 0; cord->connection[i] != NULL; i++)
        free(cord->connection[i]);
    free(cord->connection);
    free(cord->room);
}

void free_elem_gen(info_t *gen)
{
    for (int i = 0; gen->points[i] != NULL; i++) {
        free_cord(gen->points[i]);
        free(gen->points[i]);
    }
    free(gen->points);
    for (int i = 0; gen->tunnel[i] != NULL; i++)
        free(gen->tunnel[i]);
    free(gen->tunnel);
    free(gen->start->room);
    free(gen->end->room);
    free(gen->start);
    free(gen->end);
}

void free_struct(info_t *gen, path_t **path)
{
    free_elem_gen(gen);
    free(gen);
    free(path);
}
