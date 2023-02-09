/*
** EPITECH PROJECT, 2018
** pluie_de_ligne.c
** File description:
** pluie_de_ligne.c
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

void changer(framebuffer_t *fb)
{
    for (long int n = 3; n < (fb->width * fb->height * fb->BPP / 8); n += 4)
    {
        fb->pixels[n] -= (fb->pixels[n] > 10) ? 10 : 0;
        fb->pixels[n - 3] -= (fb->pixels[n] > 5) ? 5 : 0;
        fb->pixels[n - 1] += (fb->pixels[n] > 1) ? 5 : 0;
    }
}

void quote(framebuffer_t *fb)
{
    sfVector2f a;
    sfVector2f b;

    a.x = rand() % fb->width;
    a.y = rand() % fb->height;
    b.x = rand() % fb->width;
    b.y = rand() % fb->height;
    draw_line(fb, a, b, sfRed);
}

void my_first_test(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite,
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
            pluie_de_rond(fb, texture, sprite, window);
        }
        if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyLeft) {
            while (sfRenderWindow_pollEvent(window, &ev) || ev.type != 
            sfEvtKeyReleased);
            meteorite(fb, texture, sprite, window);
        }
    }
}

int pluie_de_ligne(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite,
sfRenderWindow *window)
{
    clear(fb);
    sfRenderWindow_clear(window, sfBlack);

    for (int i = 0; sfRenderWindow_isOpen(window); i++) {
        sfRenderWindow_setFramerateLimit(window, 60);
        if (i == 10) {
            quote(fb);
            changer(fb);
            i = 0;
        }
        my_first_test(fb, texture, sprite, window);
        check(fb, texture, sprite, window);
    }
    return (0);
}
