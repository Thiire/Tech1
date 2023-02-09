/*
** EPITECH PROJECT, 2019
** UI_monde
** File description:
** plus
*/

#include "my_world.h"

int drawing2(all_t *all, Map_t *map)
{
    sfRenderWindow_drawSprite(map->window, all->sprite->help, NULL);
    if (all->mode == 1) {
        map->type = 1;
        sfSprite_setTexture(all->sprite->shovel, all->tex->tshovel, sfTrue);
        sfRenderWindow_drawSprite(map->window, all->sprite->shovel, NULL);
        sfSprite_setTexture(all->sprite->hand, all->tex->thand_l, sfTrue);
        sfRenderWindow_drawSprite(map->window, all->sprite->hand, NULL);
        sfRenderWindow_drawSprite(map->window, all->sprite->mouse_hand, NULL);
    } else if (all->mode == 2) {
        map->type = -1;
        sfSprite_setTexture(all->sprite->hand, all->tex->thand, sfTrue);
        sfRenderWindow_drawSprite(map->window, all->sprite->hand, NULL);
        sfSprite_setTexture(all->sprite->shovel, all->tex->tshovel_l, sfTrue);
        sfRenderWindow_drawSprite(map->window, all->sprite->shovel, NULL);
        sfRenderWindow_drawSprite(map->window, all->sprite->mouse_sho, NULL);
    }
    return (0);
}

int drawing(all_t *all, sfRenderWindow *window, Map_t *map)
{
    sfRenderWindow_drawSprite(window, all->sprite->back, NULL);
    vertex_filler(map);
    sfSprite_setPosition(all->sprite->plus, all->vector->pos_plus);
    sfRenderWindow_drawSprite(window, all->sprite->plus, NULL);
    sfSprite_setPosition(all->sprite->moins, all->vector->pos_moins);
    sfRenderWindow_drawSprite(window, all->sprite->moins, NULL);
    sfSprite_setPosition(all->sprite->reset, all->vector->reset);
    sfRenderWindow_drawSprite(window, all->sprite->reset, NULL);
    sfSprite_setPosition(all->sprite->shovel, all->vector->shovel);
    sfSprite_setPosition(all->sprite->hand, all->vector->main);
    return (drawing2(all, map));
}