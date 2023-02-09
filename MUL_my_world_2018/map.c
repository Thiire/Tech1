/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** map
*/

#include "my_world.h"

void map_rng(Map_t *map, int nb)
{
    int y = rand() % (map->max_x - 1);
    int x = rand() % (map->max_y - 1);

    if (nb == 1) {
        map->tab[y][x]++;
        map->tab[y][x + 1]++;
        map->tab[y + 1][x]++;
        map->tab[y + 1][x + 1]++;
    } else if (nb == 0) {
        map->tab[y][x]--;
        map->tab[y][x + 1]--;
        map->tab[y + 1][x]--;
        map->tab[y + 1][x + 1]--;
    }
}

void manage_map(Map_t *map, int y, int x)
{
    int w = 0;
    int v = 0;

    for (int i = y; i < y + map->max_x; i++, v++) {
        for (int n = x; n < x + map->max_y; n++, w++) {
            map->buffer[i][n] = map->tab[v][w] + 50;
        }
        w = 0;
    }
}

void move_map(Map_t *map, int y, int x, int nb)
{
    int w = 0;
    int v = 0;

    if (nb == 0)
        manage_map(map, y + 1, x);
    if (nb == 1)
        manage_map(map, y - 1, x);
    if (nb == 2)
        manage_map(map, y, x + 1);
    if (nb == 3)
        manage_map(map, y, x - 1);
    for (int i = y; i < y + map->max_x; i++, v++) {
        for (int n = x; n < x + map->max_y; n++, w++) {
            map->tab[v][w] = map->buffer[i][n] - 50;
        }
        w = 0;
    }
}

void raise(Map_t *map, sfRenderWindow *window)
{
    sfVector2f pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i < map->max_y; i++) {
        for (int n = 0; n < map->max_x; n++) {
            pos = project_iso_point(map, n, i, map->tab[n][i]);
            map->tab[n][i] += (map->type == -1 && abs(mouse.y - pos.x) <= 5 &&
            abs(mouse.x - pos.y) <= 5 && map->tab[n][i] > -20) ? map->type : 0;
            map->tab[n][i] += (map->type == 1 && abs(mouse.y - pos.x) <= 5 &&
            abs(mouse.x - pos.y) <= 5 && map->tab[n][i] < 50) ? map->type : 0;
        }
    }
}