/*
** EPITECH PROJECT, 2018
** follower.c
** File description:
** follower.c
*/

#include "include/imagebuffer.h"

imagebuffer_t **texture_mover(imagebuffer_t **image, char **stc)
{
    int x = 1;
    int y = 1;

    image[4] = image_ctr("Bonus/txt/Trees.png", (sfIntRect)
    {0, 0, 3840, 1080}, (sfVector2f){0, 0}, FONT);
    image[4]->speed = 2;
    image[5] = image_ctr("Bonus/txt/Ground.png", (sfIntRect)
    {0, 0, 3840, 1080}, (sfVector2f){0, 0}, FONT);
    image[5]->speed = 3;
    for (int n = 6; x <= 10 || y != 4; n++, x++) {
        if (stc[y][x] == ' ') {
            image[n] = image_ctr("Empty.png", (sfIntRect){0, 0, 218, 218},
            (sfVector2f){(x - 1) * 218, 200+y * 218}, EMPTY);
        } else if (stc[y][x] != ' ') {
            image[n] = tri_text1(image[n], stc, y, x);
        }
        y += (x == 10 && y != 4) ? 1 : 0;
        x = (x == 10 && y != 4) ? 0 : x;
    }
    return (image);
}

imagebuffer_t **creator(char **stc)
{
    imagebuffer_t **image = malloc(sizeof(imagebuffer_t *) * 36);

    image[0] = image_ctr("Bonus/txt/Clouds2.png", (sfIntRect)
    {0, 0, 3840, 1080}, (sfVector2f){0, 0}, FONT);
    image[0]->speed = 0.5;
    image[1] = image_ctr("Bonus/txt/Clouds.png", (sfIntRect)
    {0, 0, 3840, 1080}, (sfVector2f){0, 0}, FONT);
    image[1]->speed = 0.75;
    image[2] = image_ctr("Bonus/txt/Bushes.png", (sfIntRect)
    {0, 0, 3840, 1080}, (sfVector2f){0, 0}, FONT);
    image[2]->speed = 1;
    image[3] = image_ctr("Bonus/txt/Trees2.png", (sfIntRect)
    {0, 0, 3840, 1080}, (sfVector2f){0, 0}, FONT);
    image[3]->speed = 1.5;
    image = texture_mover(image, stc);
    image[36] = image_ctr("Bonus/character/Player.png", (sfIntRect)
    {0, 0, 512, 512}, (sfVector2f){-150, 100}, PLAYER);
    sfSprite_setPosition(image[36]->font, image[36]->position);
    return (image);
}

int fall(imagebuffer_t **im, int ret, sfClock *clock)
{
    if (im[7]->name != 4 && im[36]->position.y <
    im[7]->position.y - 300) {
        sfClock_restart(clock);
        return (2);
    } else if (im[17]->name != 4 && im[7]->name == 4 && im[36]->position.y <
    im[17]->position.y - 300) {
        sfClock_restart(clock);
        return (2);
    } else if (im[27]->name != 4 && im[17]->name == 4 && im[7]->name == 4 &&
    im[36]->position.y < im[27]->position.y - 300) {
        sfClock_restart(clock);
        return (2);
    }
    if (im[7]->name == 4 && im[17]->name == 4 && im[27]->name == 4) {
        sfClock_restart(clock);
        return (2);
    }
    return (0);
}

int check(sfRenderWindow *window, sfClock *clock, int ret, imagebuffer_t **im)
{
    sfEvent event;

    if (ret == 0)
        ret = fall(im, ret, clock);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
        ret != 1) {
            ret = 1;
            sfClock_restart(clock);
        }
    }
    return (ret);
}

int jump_bis(imagebuffer_t **image, float seconds, int ret, sfClock *clock)
{
    if (image[7]->name == 2 && image[36]->position.y >
    image[7]->position.y - 295 && image[36]->position.y <
    image[7]->position.y - 265) {
        sfClock_restart(clock);
        ret = 0;
        image[36]->position.y = image[7]->position.y - 300;
    } else if (image[17]->name == 2 && image[36]->position.y >
    image[17]->position.y - 295 && image[36]->position.y <
    image[17]->position.y - 265) {
        sfClock_restart(clock);
        ret = 0;
        image[36]->position.y = image[17]->position.y - 300;
    } else if (image[27]->name == 2 && image[36]->position.y >
    image[27]->position.y - 295 && image[36]->position.y <
    image[27]->position.y - 265) {
        sfClock_restart(clock);
        ret = 0;
        image[36]->position.y = image[27]->position.y - 300;
    }
    return (ret);
}
