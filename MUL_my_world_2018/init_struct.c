/*
** EPITECH PROJECT, 2019
** UI_monde
** File description:
** tools
*/

#include "my_world.h"

void vector(all_t *all)
{
    all->vector->reset = (sfVector2f){874, 825};
    all->vector->main = (sfVector2f){548, 825};
    all->vector->shovel = (sfVector2f){1200, 825};
    all->vector->pos_moins = (sfVector2f){1553, 3};
    all->vector->pos_plus = (sfVector2f){1703, 3};
}

void texture(all_t *a)
{
    a->tex->tback = sfTexture_createFromFile("pc/back.jpg", NULL);
    a->tex->thand = sfTexture_createFromFile("pc/main.png", NULL);
    a->tex->tshovel = sfTexture_createFromFile("pc/shovel.png", NULL);
    a->tex->tplus = sfTexture_createFromFile("pc/plus.png", NULL);
    a->tex->tmoins = sfTexture_createFromFile("pc/moins.png", NULL);
    a->tex->tmouse_h = sfTexture_createFromFile("mc/mouse_main.png", NULL);
    a->tex->tmouse_s = sfTexture_createFromFile("mc/mouse_shovel.png", NULL);
    a->tex->thand_l = sfTexture_createFromFile("pc/main_lock.png", NULL);
    a->tex->tshovel_l = sfTexture_createFromFile("pc/shovel_lock.png", NULL);
    a->tex->thelp = sfTexture_createFromFile("pc/help.png", NULL);
    a->tex->thelp_open = sfTexture_createFromFile("pc/help_open.png", NULL);
    a->tex->treset = sfTexture_createFromFile("pc/reset.png", NULL);
}

void sprite(all_t *all)
{
    all->sprite->back = sfSprite_create();
    sfSprite_setTexture(all->sprite->back, all->tex->tback, sfTrue);
    all->sprite->shovel = sfSprite_create();
    sfSprite_setTexture(all->sprite->shovel, all->tex->tshovel, sfTrue);
    all->sprite->hand = sfSprite_create();
    sfSprite_setTexture(all->sprite->hand, all->tex->thand, sfTrue);
    all->sprite->mouse_hand = sfSprite_create();
    sfSprite_setTexture(all->sprite->mouse_hand, all->tex->tmouse_h, sfTrue);
    all->sprite->mouse_sho = sfSprite_create();
    sfSprite_setTexture(all->sprite->mouse_sho, all->tex->tmouse_s, sfTrue);
    all->sprite->plus = sfSprite_create();
    sfSprite_setTexture(all->sprite->plus, all->tex->tplus, sfTrue);
    all->sprite->moins = sfSprite_create();
    sfSprite_setTexture(all->sprite->moins, all->tex->tmoins, sfTrue);
    all->sprite->help = sfSprite_create();
    sfSprite_setTexture(all->sprite->help, all->tex->thelp, sfTrue);
    all->sprite->reset = sfSprite_create();
    sfSprite_setTexture(all->sprite->reset, all->tex->treset, sfTrue);
}

all_t *init_struct(void)
{
    all_t *all = malloc(sizeof(all_t));
    all->tex = malloc(sizeof(texture_t));
    all->sprite = malloc(sizeof(sprite_t));
    all->vector = malloc(sizeof(vector_t));

    all->mode = 1;
    all->help = 1;
    vector(all);
    texture(all);
    sprite(all);
    return (all);
}