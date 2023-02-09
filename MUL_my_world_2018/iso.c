/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iso
*/

#include "my_world.h"

void int_filler(Map_t *map, int v, int w)
{
    map->tab = malloc(sizeof(int *) * map->max_x);
    for (int i = 0, j = v; i < map->max_x; i++, j++) {
        map->tab[i] = malloc(sizeof(int) * map->max_x);
        for (int n = 0, k = w; n < map->max_y; n++, k++) {
            map->tab[i][n] = map->buffer[j][k] - 50;
        }
    }
}

void malloc_filler(Map_t *map)
{
    int fd = open("Map/map", O_RDONLY);
    int i = 0;

    map->buffer = malloc(sizeof(char *) * 1000000);

    for (int i = 0; i < 1000; i++) {
        map->buffer[i] = malloc(sizeof(char) * 1000);
        for (int y = 0; y < 1000; y++) {
            map->buffer[i][y] = Perlin(y, i, 100, map) * 100 + 50;
            map->buffer[i][y] = (map->buffer[i][y] < 30)
            ? 30 : map->buffer[i][y];
        }
    }
}

float cv(int degree)
{
    float pi = 3.1415926535897932;

    return (degree * (pi/180));
}

sfVector2f project_iso_point(Map_t *map, int x, int y, int z)
{
    sfVector2f pos;
    float v = (((x * 1.0f / (map->max_x - (map->input->sec_scale +
    map->input->sec_scale_x))) * (2 * map->input->sec_scale)) -
    (map->input->sec_scale + map->input->sec_scale_x)) * map->input->scale;
    float w = (((y * 1.0f / (map->max_y - (map->input->sec_scale +
    map->input->sec_scale_y))) * (2 * map->input->sec_scale)) -
    (map->input->sec_scale + map->input->sec_scale_y)) * map->input->scale;
    float k = z * (map->input->scale / map->max_x);
    float a = 0;
    float b = 0;
    float c = 0;
    float tmp = 0;

    z = (z == 0) ? 1 : z;
    a = cos(cv(map->input->rot_x)) * (v) - (sin(cv(map->input->rot_x)) * (k));
    c = sin(cv(map->input->rot_x)) * (v) + (cos(cv(map->input->rot_x)) * (k));
    tmp = w * cos(cv(map->input->rot_y)) - c * sin(cv(map->input->rot_y));
    c = b * sin(cv(map->input->rot_y)) + c * cos(cv(map->input->rot_y));
    pos = (sfVector2f) {a + (1920 / 2), tmp + (1080 / 2)};
    return (pos);
}

sfColor block_text(int r)
{
    sfColor c;

    if (r <= 1) {
        if (r < 0 && r >= -6)
            c = (sfColor){255, 255 - (abs(r) * 10), 220 - (abs(r) * 20), 255};
        else if (r < -6 && r > -20)
            c = (sfColor){255, 190, 110, 255};
        else if (r <= -20)
            c = (sfColor){30, 144, 255, 255};
        if (r == 0 || r == 1)
            c = (sfColor){0, 225, 0, 255};
    } else if (r <= 15) {
        c = (sfColor){0, 255 - r * 15, 0, 255};
    } else {
        if (r <= 23)
        c = (sfColor){r * (r - 14), r * (r - 14), r * (r - 14), 255};
        else
        c = (sfColor){200, 200, 200, 255};
    }
    return (c);
}
