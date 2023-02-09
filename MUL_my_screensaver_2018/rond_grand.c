/*
** EPITECH PROJECT, 2018
** rond_grand.c
** File description:
** rond_grand.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/framebuffer.h"
#include <SFML/System/Vector2.h>
#include <math.h>
#include <SFML/Window/Keyboard.h>

void check(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

int pluie_de_rond(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

int meteorite(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

void drawer (framebuffer_t *framebuffer, sfVector2f center, int *radius, 
sfColor color)
{
    sfVector2f p;

    for (p.y = 0; p.y < framebuffer->height; p.y++) {
        for (p.x = 0; p.x < framebuffer->width; p.x++) {
            if (pow((p.x - center.x), 2) + pow((p.y - center.y), 2) <= pow(radius[0], 2))
                put_pixel(framebuffer, p.x, p.y, color);
        }
    }
    radius[0]++;
}

void my_changer(framebuffer_t *fb)
{
    for (long int n = 3; n < (fb->width * fb->height * fb->BPP / 8); n += 4)
    {
        if (fb->pixels[n] > 2) {
            fb->pixels[n] -=2;
        }
    }
}

void my_third_test(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite,
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
            meteorite(fb, texture, sprite, window);
        }
        if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyLeft) {
            while (sfRenderWindow_pollEvent(window, &ev) || ev.type != 
            sfEvtKeyReleased);
            pluie_de_rond(fb, texture, sprite, window);
        }
    }
}

sfVector2f resizer(sfVector2f ctr, int *res, int *size, int *c)
{
    for (int n = 0; n < 4; n++)
        c[n] = rand() % 250; 
    res[0] = rand() % 100;
    res[0] = (res[0] < 5) ? 5 : res[0];
    ctr.x = rand() % size[1];
    ctr.y = rand() % size[2];
    size[0] = 10;
    return (ctr);
}

int rond_grand(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite, 
sfRenderWindow *window)
{
    clear(fb);
    sfRenderWindow_clear(window, sfBlack);
    int c[4] = {50, 50, 50, 50};
    int res[1] = {50};
    int size[3] = {10, fb->width, fb->height};
    sfEvent event;
    sfVector2f ctr;

    for (int i = 0; sfRenderWindow_isOpen(window); i++) {
        sfRenderWindow_setFramerateLimit(window, 60);
        if (i % 2 == 0)
            my_changer(fb);
        if (i == res[0]) {
            ctr = resizer(ctr, res, size, c);
            i = 0;
        } else if (i < res[0] + 1)
            drawer(fb, ctr, size, (sfColor){c[0], c[1], c[2], c[3]});
        my_third_test(fb, texture, sprite, window);
        check(fb, texture, sprite, window);
    }
}
