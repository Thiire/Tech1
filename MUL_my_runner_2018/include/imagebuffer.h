/*
** EPITECH PROJECT, 2018
** framebuffer.h
** File description:
** framebuffer.h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <termios.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

typedef enum type_t
{
    FONT,
    PLAYER,
    OBSTACLE,
    ENNEMIES,
    EMPTY,
    VICTORY,
} type_t;

typedef struct imagebuffer_t
{
    type_t name;
    sfIntRect base;
    sfTexture *layer;
    sfSprite *font;
    sfVector2f position;
    float speed;
    void (*ptr_move)(struct imagebuffer_t *);
} imagebuffer_t;

imagebuffer_t *tri_text1(imagebuffer_t *, char **, int, int);

imagebuffer_t *image_ctr(char *, sfIntRect, sfVector2f, type_t);

imagebuffer_t **creator(char **);

imagebuffer_t **texture_mover(imagebuffer_t **, char **);

void move_image(imagebuffer_t *);

void move_block(imagebuffer_t *);

void move_player(imagebuffer_t *);

int check(sfRenderWindow *, sfClock *, int, imagebuffer_t **);

int check_death(imagebuffer_t **);

int platform(char **, imagebuffer_t **, sfRenderWindow *);

int displayer(sfRenderWindow *, imagebuffer_t **, sfClock *, int);

int faller(imagebuffer_t **, sfClock *);

int jump(imagebuffer_t **, float, int, sfClock *);

int jump_bis(imagebuffer_t **, float, int, sfClock *);

int fall(imagebuffer_t **, int, sfClock *);

int move_decal(imagebuffer_t **);

int scorer(sfRenderWindow *, int);

int victory(sfRenderWindow *);

#endif