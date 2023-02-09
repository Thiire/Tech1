/*
** EPITECH PROJECT, 2018
** game_block.c
** File description:
** game_block.c
*/

#include "include/imagebuffer.h"

void move_block(imagebuffer_t *block)
{
    sfSprite_setPosition(block->font, block->position);
    block->position.x -= 3;
}

void move_image(imagebuffer_t *image)
{
    sfVector2f pos;
    sfSprite_move(image->font, (sfVector2f){(image->speed) * -1, 0});
    pos = sfSprite_getPosition(image->font);
    if (pos.x <= -1920)
        sfSprite_setPosition(image->font, (sfVector2f){0, 0});
}

void move_player(imagebuffer_t *player)
{
    sfSprite_setPosition(player->font, player->position);
    sfSprite_setTextureRect(player->font, player->base);
    player->base.left += 512;
    if (player->base.left >= 5120)
        player->base.left = 0;
}

imagebuffer_t *image_ctr(char *str, sfIntRect cube, sfVector2f pos, type_t nm)
{
    imagebuffer_t *image = malloc(sizeof(imagebuffer_t));

    image->layer = sfTexture_createFromFile(str, NULL);
    image->font = sfSprite_create();
    image->base = cube;
    image->position = pos;
    image->speed = 1;
    image->name = nm;
    if (image->name == FONT)
        image->ptr_move = &move_image;
    else if (image->name == PLAYER)
        image->ptr_move = &move_player;
    else
        image->ptr_move = &move_block;
    sfSprite_setTexture(image->font, image->layer, sfFalse);
    sfSprite_setTextureRect(image->font, image->base);
    return (image);
}
