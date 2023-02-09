/*
** EPITECH PROJECT, 2018
** pluie_de_rond.c
** File description:
** pluie_de_rond.c
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

int draw(framebuffer_t *fb)
{
    sfVector2f center;
    int size = 0;

    center.x = rand() % fb->width;
    center.y = rand() % fb->height;
    size = rand() % 30;
    size = (size < 10) ? 10 : size;
    draw_circle(fb, center, size, sfRed);
    return (0);
}

void my_fourth_test(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite,
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
            rond_grand(fb, texture, sprite, window);
        }
        if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyLeft) {
            while (sfRenderWindow_pollEvent(window, &ev) || ev.type != 
            sfEvtKeyReleased);
            pluie_de_ligne(fb, texture, sprite, window);
        }
    }
}

void change(framebuffer_t *fb)
{
    for (long int n = 3; n < (fb->width * fb->height * fb->BPP / 8); n += 4)
    {
        fb->pixels[n - 3] -= (fb->pixels[n - 3] > 1) ? 1 : 0;
        fb->pixels[n - 1] += (fb->pixels[n - 3] > 1) ? 1 : 0;
        fb->pixels[n - 1] = (fb->pixels[n - 1] >= 255) ? 255 : 
        fb->pixels[n - 1];
        fb->pixels[n - 3] = (fb->pixels[n - 3] <= 1) ? 0 : fb->pixels[n - 3];
    }
}

int pluie_de_rond(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite,
sfRenderWindow *window)
{
    clear(fb);
    sfRenderWindow_clear(window, sfBlack);
    int size = 50;

    for (int i = 0; sfRenderWindow_isOpen(window); i++) {
        sfRenderWindow_setFramerateLimit(window, 60);
        change(fb);
        if (i == 10)
            i = draw(fb);
        my_fourth_test(fb, texture, sprite, window);
        check(fb, texture, sprite, window);
    }
    return (0);
}
