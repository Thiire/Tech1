/*
** EPITECH PROJECT, 2018
** Task02.c
** File description:
** Task02.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/framebuffer.h"
#include <SFML/System/Vector2.h>
#include <math.h>
#include <SFML/Window/Keyboard.h>

void check(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

int pluie_de_ligne(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

int rond_grand(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

sfVector2f sizer(framebuffer_t *fb, sfVector2f center, int size)
{
    if (center.y < 0 - size) {
        center.y = fb->height + size;
    } else if (center.y > fb->height + size) {
        center.y = 0 - size;
    }
    if (center.x < 0 - size) {
        center.x = fb->width + size;
    } else if (center.x > fb->width + size) {
        center.x = 0 - size;
    }
    center.x += 3;
    center.y += 3;
    draw_circle(fb, center, size, sfRed);
    return (center);
}

void my_change(framebuffer_t *fb)
{
    for (long int n = 3; n < (fb->width * fb->height * fb->BPP / 8); n += 4)
    {
        if (fb->pixels[n] > 2) {
            fb->pixels[n] -=2;
            fb->pixels[n - 2] += 1;
        }
    }
}

void my_second_test(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite,
sfRenderWindow *window)
{
    sfEvent ev;

    while (sfRenderWindow_pollEvent(window, &ev)) {
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyRight) {
            while (sfRenderWindow_pollEvent(window, &ev) || ev.type != 
            sfEvtKeyReleased);
            pluie_de_ligne(fb, texture, sprite, window);
        }
        if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyLeft) {
            while (sfRenderWindow_pollEvent(window, &ev) || ev.type != 
            sfEvtKeyReleased);
            rond_grand(fb, texture, sprite, window);
        }
    }
}

int meteorite(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite,
sfRenderWindow *window)
{
    clear(fb);
    sfRenderWindow_clear(window, sfBlack);
    int res = 0;
    int size = 50;
    sfVector2f center = {0, 0};

    for (int i = 0; sfRenderWindow_isOpen(window); i++) {
        sfRenderWindow_setFramerateLimit(window, 60);
        my_change(fb);
        center = sizer(fb, center, size);
        my_second_test(fb, texture, sprite, window);
        check(fb, texture, sprite, window);
    }
    return (0);
}
