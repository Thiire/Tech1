/*
** EPITECH PROJECT, 2018
** framebuffer.h
** File description:
** framebuffer.h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>

typedef struct framebuffer_t
{
    unsigned int width;
    unsigned int height;
    unsigned int BPP;
    sfUint8 *pixels;
} framebuffer_t;

void put_pixel(framebuffer_t *, unsigned int, unsigned int, sfColor);

void draw_line(framebuffer_t *, sfVector2f, sfVector2f, sfColor);

void draw_circle(framebuffer_t *, sfVector2f, int, sfColor);

void clear(framebuffer_t *);

framebuffer_t *framebuffer_create(unsigned int, unsigned int);

#endif