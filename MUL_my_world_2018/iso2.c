/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iso2
*/

#include "my_world.h"

void vertex_filler2(Map_t *map, int i, int n)
{
    if (i == map->max_y - 1) {
        draw_x(map, n, i);
    } else if (n == map->max_x - 1) {
        draw_y(map, n, i);
    } else {
        draw_texture(map, n, i);
        draw_y(map, n, i);
        draw_x(map, n, i);
    }
}

void vertex_filler(Map_t *map)
{
    ground_x(map, 0);
    ground_x(map, map->max_x - 1);
    for (int i = 0; i < map->max_y; i++) {
        for (int n = 0; n < map->max_x - 1; n++) {
            vertex_filler2(map, i, n);
        }
    }
    ground_y(map, map->max_y - 1);
}

Map_t *map_filler(void)
{
    Map_t *map = malloc(sizeof(Map_t));
    map->perm = perm_filler();
    map->x = 0;
    map->y = 0;
    map->max_x = MAP_X;
    map->max_y = MAP_Y;
    map->input = malloc(sizeof(input_t));
    map->input->scale = 100;
    map->input->rot_x = 0;
    map->input->rot_y = 45;
    map->input->sec_scale_x = 0;
    map->input->sec_scale_y = 0;
    map->input->sec_scale = 1;
    malloc_filler(map);
    int_filler(map, 0, 0);
    return (map);
}