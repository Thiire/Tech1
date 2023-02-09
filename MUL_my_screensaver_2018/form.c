/*
** EPITECH PROJECT, 2018
** form.c
** File description:
** form.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "framebuffer.h"
#include <math.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>

void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, 
sfColor color)
{
    int i = 0;

    for (int n = 0; n < y; n++)
        i += framebuffer->width * 4;
    for (int n = 0; n < x; n++)
        i += 4;
    framebuffer->pixels[i] = color.r;
    framebuffer->pixels[i + 1] = color.g;
    framebuffer->pixels[i + 2] = color.b;
    framebuffer->pixels[i + 3] = color.a;
}

void draw_line (framebuffer_t *framebuffer, sfVector2f a, sfVector2f b, sfColor 
color)
{
    sfVector2f p;
    float stocka = (a.y - b.y) / (a.x - b.x);
    float stockb =  a.y - stocka * a.x;
    float maxx = (a.x > b.x) ? a.x : b.x;
    float minx = (a.x < b.x) ? a.x : b.x;
    float maxy = (a.y > b.y) ? a.y : b.y;
    float miny = (a.y < b.y) ? a.y : b.y;

    if ((maxx - minx) >= (maxy - miny) && a.x != b.x) {
        p.x = (a.x < b.x) ? a.x : b.x;
        for (int n = 0; p.x < maxx; p.x++) {
            p.y = stocka * p.x + stockb;
            put_pixel(framebuffer, p.x, p.y, color);
        }
    } else if ((maxy - miny) >= (maxx - minx) && a.x != b.x) {
        p.y = (a.y < b.y) ? a.y : b.y;
        for (int n = 0; p.y < maxy; p.y++) {
            p.x = (p.y - stockb) / stocka;
            put_pixel(framebuffer, p.x, p.y, color);
        }
    }
}

void draw_circle (framebuffer_t *framebuffer, sfVector2f center, int radius, 
sfColor color)
{
    sfVector2f p;

    for (p.y = 0; p.y < framebuffer->height; p.y++) {
        for (p.x = 0; p.x < framebuffer->width; p.x++) {
            if (pow((p.x - center.x), 2) + pow((p.y - center.y), 2) <= pow(radius, 2))
                put_pixel(framebuffer, p.x, p.y, color);
        }
    }
}

/*void clear(framebuffer_t *fb, int *data)
{
    long int i = 0;
    long int j = 0;

    for (j = 0; j < data[1]; j++)
        i += fb->width * 4;
    i += data[0] * 4;
    for (long int w = j; w < data[3] - data[1]; w++) {
        for (long int n = i; n < i + (data[2] * 4); n += 4)
            fb->pixels[n] = 0;
        i += (fb->width * 4) + ((fb->width - data[2]) * 4) + data[0] * 4;
    }
}*/

void clear(framebuffer_t *fb)
{
    for (long int i = 0; i < fb->width * fb->height * fb->BPP / 8; i++) {
        fb->pixels[i] = 0;
    }
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *stock = malloc(width * height * 32 / 8);

    stock->width = width;
    stock->height = height;
    stock->BPP = 32;
    stock->pixels = malloc(width * height * stock->BPP / 8);
    return (stock);
}