/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** manage_key
*/

#include "my_world.h"

int md4(Map_t *map, sfEvent event, all_t *a)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && ((a->vector->mouse.x >= 874)
    && (a->vector->mouse.x <= 1074)) && ((a->vector->mouse.y >= 825) &&
    (a->vector->mouse.y <= 1025))) {
        manage_map(map, map->y, map->x);
        map->x = 0;
        map->y = 0;
        map->input->rot_x = 0;
        map->input->rot_y = 45;
        move_map(map, map->y, map->x, 4);
    }
    return (md5(map, event, a));
}

int md3(Map_t *m, sfEvent event, all_t *a)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && ((a->vector->mouse.x >= 1553)
    && (a->vector->mouse.x <= 1653)) && ((a->vector->mouse.y >= 3) &&
    (a->vector->mouse.y <= 103)) && m->max_x < 100 &&
    m->buffer[m->y][m->x + m->max_x + 1] != '\0' &&
    m->buffer[m->y + m->max_y + 1][0] != '\0') {
        manage_map(m, m->y, m->x);
        m->max_x++;
        m->max_y++;
        free(m->tab);
        int_filler(m, m->y, m->x);
    } else if (sfMouse_isButtonPressed(sfMouseLeft) && ((a->vector->mouse.x
    >= 1703) && (a->vector->mouse.x <= 1803)) && ((a->vector->mouse.y >= 3)
    && (a->vector->mouse.y <= 103)) && m->max_x > 5) {
        manage_map(m, m->y, m->x);
        m->max_x--;
        m->max_y--;
        free(m->tab);
        int_filler(m, m->y, m->x);
    }
    return (md4(m, event, a));
}

int md2(Map_t *map, sfEvent event, all_t *a)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) && ((a->vector->mouse.x >= 25)
    && (a->vector->mouse.x <= 100)) && ((a->vector->mouse.y >= 25) &&
    (a->vector->mouse.y <= 100))) || sfKeyboard_isKeyPressed(sfKeyH)) {
        a->help = 2;
        sfSprite_setTexture(a->sprite->help, a->tex->thelp_open, sfTrue);
    } else if ((sfMouse_isButtonPressed(sfMouseLeft) &&
    ((a->vector->mouse.x >= 580) && (a->vector->mouse.x <= 630)) &&
    ((a->vector->mouse.y >= 30) && (a->vector->mouse.y <= 80)))) {
        a->help = 1;
        sfSprite_setTexture(a->sprite->help, a->tex->thelp, sfTrue);
    }
    return (md3(map, event, a));
}

int md(Map_t *map, sfEvent event, all_t *a)
{
    a->vector->mouse = sfMouse_getPositionRenderWindow(map->window);
    if ((sfMouse_isButtonPressed(sfMouseLeft) && ((a->vector->mouse.x >= 548)
    && (a->vector->mouse.x <= 748)) && (a->vector->mouse.y >= 820) &&
    (a->vector->mouse.y <= 1080)) || sfKeyboard_isKeyPressed(sfKeyNum1)) {
        a->mode = 1;
        sfSprite_setPosition(a->sprite->mouse_hand, (sfVector2f)
        {(float)a->vector->mouse.x, (float)a->vector->mouse.y});
        sfRenderWindow_drawSprite(map->window, a->sprite->mouse_hand, NULL);
    } else if ((sfMouse_isButtonPressed(sfMouseLeft) &&
    ((a->vector->mouse.x >= 1200) && (a->vector->mouse.x <= 1400)) &&
    (a->vector->mouse.y >= 820) && (a->vector->mouse.y <= 1080)) ||
    sfKeyboard_isKeyPressed(sfKeyNum2)) {
        a->mode = 2;
        sfSprite_setPosition(a->sprite->mouse_sho, (sfVector2f)
        {(float)a->vector->mouse.x, (float)a->vector->mouse.y});
        sfRenderWindow_drawSprite(map->window, a->sprite->mouse_sho, NULL);
    }
    return (md2(map, event, a));
}
