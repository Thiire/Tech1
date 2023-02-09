/*
** EPITECH PROJECT, 2018
** my_follow.c
** File description:
** my_follow.c
*/

#include "include/imagebuffer.h"

static int decal = 219;

int faller(imagebuffer_t **image, sfClock *clock)
{
    if (image[7]->name == 2 && image[36]->position.y >=
    image[7]->position.y - 300) {
        sfClock_restart(clock);
        return (0);
    } else if (image[17]->name == 2 && image[36]->position.y >=
    image[17]->position.y - 300) {
        sfClock_restart(clock);
        return (0);
    } else if (image[27]->name == 2 && image[36]->position.y >=
    image[27]->position.y - 300) {
        sfClock_restart(clock);
        return (0);
    }
    return (2);
}

int jump(imagebuffer_t **image, float seconds, int ret, sfClock *clock)
{
    if (ret == 1) {
        if (seconds < 3)
            image[36]->position.y -= 15 - seconds * 20;
        else
            image[36]->position.y += 30;
        sfSprite_setPosition(image[36]->font, image[36]->position);
        image[36]->base.left = (seconds < 1) ? 0 : 1536;
        ret = jump_bis(image, seconds, ret, clock);
    } else if (ret == 2) {
        if (seconds < 3)
            image[36]->position.y += seconds * 10;
        else
            image[36]->position.y += 30;
        sfSprite_setPosition(image[36]->font, image[36]->position);
        image[36]->base.left = 1536;
        ret = faller(image, clock);
    }
    return (ret);
}

int displayer(sfRenderWindow *wn, imagebuffer_t **image, sfClock *clk, int ret)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clk);
    seconds = time.microseconds / 1000000.0;
    for (int n = 0; n < 37; n++) {
        if (image[n]->name != 4) {
            sfRenderWindow_drawSprite(wn, image[n]->font, NULL);
            image[n]->ptr_move(image[n]);
        }
    }
    ret = jump(image, seconds, ret, clk);
    return (ret);
}

int check_death(imagebuffer_t **image)
{
    if (image[7]->name == 2 && image[36]->position.y >
    image[7]->position.y - 295) {
        return (1);
    } else if (image[17]->name == 2 && image[36]->position.y >
    image[17]->position.y - 295) {
        return (1);
    }
    if (image[36]->position.y > 1080)
        return (1);
    if ((image[7]->name == 5 || image[17]->name == 5 || image[27]->name == 5)
    && image[27]->position.x < 120)
        return (2);
    return (0);
}

int platform(char **stc, imagebuffer_t **image, sfRenderWindow *wn)
{
    if (decal <= 3) {
        move_decal(image);
        stc[1] += 1;
        stc[2] += 1;
        stc[3] += 1;
        image[15] = tri_text1(image[14], stc, 1, 10);
        image[25] = tri_text1(image[24], stc, 2, 10);
        image[35] = tri_text1(image[34], stc, 3, 10);
        sfSprite_setPosition(image[15]->font, image[15]->position);
        sfSprite_setPosition(image[25]->font, image[25]->position);
        sfSprite_setPosition(image[35]->font, image[35]->position);
        decal = 219;
    }
    decal -= 3;
    return (check_death(image));
}
