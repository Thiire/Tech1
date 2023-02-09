/*
** EPITECH PROJECT, 2019
** map_filler.c
** File description:
** map_filler.c
*/

#include "my_world.h"

void draw_y(Map_t *map, int x, int y)
{
    sfVertexArray *stock = sfVertexArray_create();
    sfVector2f pos1 = project_iso_point(map, x, y, map->tab[y][x]);
    sfVector2f pos2 = project_iso_point(map, x, y + 1, map->tab[y+1][x]);
    sfVertex v1 = {.position = (sfVector2f){pos1.x, pos1.y}, .color = sfBlack};
    sfVertex v2 = {.position = (sfVector2f){pos2.x, pos2.y}, .color = sfBlack};

    sfVertexArray_append(stock, v1);
    sfVertexArray_append(stock, v2);
    sfVertexArray_setPrimitiveType(stock, sfLinesStrip);
    sfRenderWindow_drawVertexArray(map->window, stock, NULL);
    sfVertexArray_destroy(stock);
}

void draw_x(Map_t *map, int x, int y)
{
    sfVertexArray *tmp = sfVertexArray_create();
    sfVector2f pos1 = project_iso_point(map, x, y, map->tab[y][x]);
    sfVector2f pos2 = project_iso_point(map, x + 1, y, map->tab[y][x+1]);
    sfVertex v1 = {.position = (sfVector2f){pos1.x, pos1.y}, .color = sfBlack};
    sfVertex v2 = {.position = (sfVector2f){pos2.x, pos2.y}, .color = sfBlack};

    sfVertexArray_append(tmp, v1);
    sfVertexArray_append(tmp, v2);
    sfVertexArray_setPrimitiveType(tmp, sfLinesStrip);
    sfRenderWindow_drawVertexArray(map->window, tmp, NULL);
    sfVertexArray_destroy(tmp);
}

void draw_texture(Map_t *map, int x, int y)
{
    sfConvexShape *tmp = sfConvexShape_create();
    sfVector2f pos1 = project_iso_point(map, x, y, map->tab[y][x]);
    sfVector2f pos2 = project_iso_point(map, x + 1, y, map->tab[y][x+1]);
    sfVector2f pos3 = project_iso_point(map, x + 1, y + 1,
    map->tab[y + 1][x + 1]);
    sfVector2f pos4 = project_iso_point(map, x, y + 1, map->tab[y+1][x]);
    sfConvexShape_setPointCount(tmp, 4);
    sfConvexShape_setPoint(tmp, 0, pos1);
    sfConvexShape_setPoint(tmp, 1, pos2);
    sfConvexShape_setPoint(tmp, 2, pos3);
    sfConvexShape_setPoint(tmp, 3, pos4);
    sfConvexShape_setFillColor(tmp, block_text((map->tab[y][x] +
    map->tab[y][x+1] + map->tab[y+1][x+1] + map->tab[y+1][x]) / 4));
    sfRenderWindow_drawConvexShape(map->window, tmp, NULL);
    sfConvexShape_destroy(tmp);
}

void ground_y(Map_t *map, int y)
{
    sfConvexShape *tmp = sfConvexShape_create();
    sfVector2f pos;
    sfVector2f pos_n;
    sfVector2f pos_v;

    sfConvexShape_setPointCount(tmp, map->max_x + 2);
    for (int i = 0; i < map->max_x; i++) {
        pos = project_iso_point(map, i, y, map->tab[y][i]);
        sfConvexShape_setPoint(tmp, i, pos);
    }
    pos_v = project_iso_point(map, 0, y, -50);
    pos_n = project_iso_point(map, map->max_x - 1, y, -50);
    sfConvexShape_setPoint(tmp, map->max_x, pos_n);
    sfConvexShape_setPoint(tmp, map->max_x + 1, pos_v);
    sfConvexShape_setFillColor(tmp, (sfColor){64, 34, 4, 255});
    sfRenderWindow_drawConvexShape(map->window, tmp, NULL);
    sfConvexShape_destroy(tmp);
}

void ground_x(Map_t *map, int x)
{
    sfConvexShape *tmp = sfConvexShape_create();
    sfVector2f pos;
    sfVector2f pos_n;
    sfVector2f pos_v;

    sfConvexShape_setPointCount(tmp, map->max_y + 2);
    for (int i = 0; i < map->max_y; i++) {
        pos = project_iso_point(map, x, i,
        map->tab[i][x]);
        sfConvexShape_setPoint(tmp, i, pos);
    }
    pos_v = project_iso_point(map, x, 0, -50);
    pos_n = project_iso_point(map, x, map->max_y - 1, -50);
    sfConvexShape_setPoint(tmp, map->max_y, pos_n);
    sfConvexShape_setPoint(tmp, map->max_y + 1, pos_v);
    sfConvexShape_setFillColor(tmp, (sfColor){64, 34, 4, 255});
    sfRenderWindow_drawConvexShape(map->window, tmp, NULL);
    sfConvexShape_destroy(tmp);
}