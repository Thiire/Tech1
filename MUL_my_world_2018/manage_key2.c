/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** manage_key2
*/

#include "my_world.h"

int md9(Map_t *map, sfEvent event, all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
        manage_map(map, map->y, map->x);
        map->x = 0;
        map->y = 0;
        map->input->rot_x = 0;
        map->input->rot_y = 45;
        move_map(map, map->y, map->x, 4);
    }
    if (sfKeyboard_isKeyPressed(sfKeyPageUp) == sfTrue)
        map_rng(map, 1);
    if (sfKeyboard_isKeyPressed(sfKeyPageDown) == sfTrue)
        map_rng(map, 0);
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
        map->input->scale++;
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
        map->input->scale--;
    return (md10(map, event, all));
}

int md8(Map_t *map, sfEvent event, all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue)
            map->input->rot_x = (map->input->rot_x == 360)
            ? 0 : map->input->rot_x + 1;
        else if (map->x != 0) {
            map->x--;
            move_map(map, map->y, map->x, 2);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue)
            map->input->rot_x = (map->input->rot_x == 0)
            ? 360 : map->input->rot_x - 1;
        else if (map->buffer[map->y][map->x + map->max_x + 1] != '\0') {
            map->x++;
            move_map(map, map->y, map->x, 3);
        }
    }
    return (md9(map, event, all));
}

int md7(Map_t *map, sfEvent event, all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue
        && map->input->rot_y > 0)
            map->input->rot_y--;
        else if (sfKeyboard_isKeyPressed(sfKeyLShift) != sfTrue
        && map->buffer[map->y + map->max_y + 1] != NULL) {
            map->y++;
            move_map(map, map->y, map->x, 1);
        }
    }
    return (md8(map, event, all));
}

int md6(Map_t *map, sfEvent event, all_t *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue
        && map->input->rot_y < 90)
            map->input->rot_y++;
        else if (sfKeyboard_isKeyPressed(sfKeyLShift) != sfTrue
        && map->y != 0) {
            map->y--;
            move_map(map, map->y, map->x, 0);
        }
    }
    return (md7(map, event, all));
}

int md5(Map_t *map, sfEvent event, all_t *all)
{
    if (event.type == sfEvtMouseMoved) {
        all->vector->mouse = sfMouse_getPositionRenderWindow(map->window);
        if (all->mode == 1) {
            all->vector->pos_main.x = all->vector->mouse.x - 10;
            all->vector->pos_main.y = all->vector->mouse.y - 3;
            sfSprite_setPosition(all->sprite->mouse_hand,
            (sfVector2f)all->vector->pos_main);
        } else if (all->mode == 2) {
            all->vector->pos_shovel.x = all->vector->mouse.x - 6;
            all->vector->pos_shovel.y = all->vector->mouse.y - 43;
            sfSprite_setPosition(all->sprite->mouse_sho,
            (sfVector2f)all->vector->pos_shovel);
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        raise(map, map->window);
    return (md6(map, event, all));
}