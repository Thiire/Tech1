/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** manage_key3
*/

#include "my_world.h"

int md10(Map_t *map, sfEvent event, all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyAdd) == sfTrue && map->max_x < 100 &&
    map->buffer[map->y][map->x + map->max_x + 1] != '\0' &&
    map->buffer[map->y + map->max_y + 1][0] != '\0') {
        manage_map(map, map->y, map->x);
        map->max_x++;
        map->max_y++;
        free(map->tab);
        int_filler(map, map->y, map->x);
    }
    if (sfKeyboard_isKeyPressed(sfKeySubtract) == sfTrue && map->max_x > 5) {
        manage_map(map, map->y, map->x);
        map->max_x--;
        map->max_y--;
        free(map->tab);
        int_filler(map, map->y, map->x);
    }
    return (0);
}