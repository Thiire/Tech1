/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/framebuffer.h"
#include <SFML/System/Vector2.h>
#include <math.h>
#include <SFML/Window/Keyboard.h>

void switcher(char **av, framebuffer_t *, sfTexture *, sfSprite *);

void displayer(sfRenderWindow *, sfText *, sfText *, sfEvent);

int pluie_de_ligne(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

int pluie_de_rond(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

int rond_grand(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

int meteorite(framebuffer_t *, sfTexture *, sfSprite *, sfRenderWindow *);

void switcher(char **av, framebuffer_t *fb, sfTexture *texture, sfSprite 
*sprite)
{
    sfVideoMode mode = {fb->width, fb->height, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "My window", sfDefaultStyle, NULL);
    switch (av[1][0]) {
        case '1' :
            meteorite(fb, texture, sprite, window);
            break;
        case '2' :
            pluie_de_ligne(fb, texture, sprite, window);
            break;
        case '3' :
            pluie_de_rond(fb, texture, sprite, window);
            break;
        case '4' :
            rond_grand(fb, texture, sprite, window);
            break;
        default :
            break;
    }
}

void check(framebuffer_t *fb, sfTexture *texture, sfSprite *sprite,
sfRenderWindow *window)
{
    sfEvent event;

    sfRenderWindow_clear(window, sfBlack);
    sfTexture_updateFromPixels(texture, fb->pixels, fb->width, fb->height, 
    0, 0);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

void my_consult(void)
{
    write(1, "Animation description :\n\tID : 1 -> meteorite crossing the"
    " screen\n\tID : 2 -> random line fading in time\n\tID : 3 -> random"
    " round filling the screen\n\tID : 4 -> random circle growing"
    " and fading in time\n", 200);
}


int receive(char **av, framebuffer_t *fb, sfTexture *texture, sfSprite *sprite)
{
    sfVideoMode mode = {fb->width, fb->height, 32};
    sfRenderWindow *window_test;

    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "Usage :\n\t./my_screensaver ID\nDescription :\n\tID"
        " correspond to the animation number\n\tmin_ID is 1\n\tmax_ID is 4\n",
         108);
        return (0);
    } else if (av[1][0] == '-' && av[1][1] == 'd' && av[1][2] == '\0') {
        my_consult();
        return (0);
    }
    if (av[1][1] != '\0')
        return (0);
    else
        switcher(av, fb, texture, sprite);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    framebuffer_t *fb;
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();

    fb = framebuffer_create(800, 600);
    texture = sfTexture_create(800, 600);
    receive(av, fb, texture, sprite);
    return (0);
}