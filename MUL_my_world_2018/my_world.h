/*
** EPITECH PROJECT, 2019
** my_world.c
** File description:
** my_world.c
*/

#ifndef MY_WORLD_H_
    #define MY_WORLD_H_
    #define READ_SIZE (1)
    #define MAP_Y (10)
    #define MAP_X (10)

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>

typedef struct input_s {
    float sec_scale_x;
    float sec_scale_y;
    float sec_scale;
    int rot_x;
    int rot_y;
    float scale;
} input_t;

typedef struct Map_s {
    input_t *input;
    char **buffer;
    int **tab;
    sfRenderWindow *window;
    sfVideoMode mode;
    int x;
    int y;
    int max_y;
    int max_x;
    int type;
    unsigned int *perm;
} Map_t;

typedef struct texture_s
{
    sfTexture *tshovel;
    sfTexture *tshovel_l;
    sfTexture *thand;
    sfTexture *thand_l;
    sfTexture *tback;
    sfTexture *tmouse_h;
    sfTexture *tmouse_s;
    sfTexture *tplus;
    sfTexture *tmoins;
    sfTexture *treset;
    sfTexture *thelp;
    sfTexture *thelp_open;
}   texture_t;

typedef struct sprite_s
{
    sfSprite *shovel;
    sfSprite *hand;
    sfSprite *back;
    sfSprite *mouse_hand;
    sfSprite *mouse_sho;
    sfSprite *plus;
    sfSprite *moins;
    sfSprite *help;
    sfSprite *reset;
} sprite_t;

typedef struct vector_s
{
    sfVector2f reset;
    sfVector2f shovel;
    sfVector2f main;
    sfVector2i mouse;
    sfVector2f pos_main;
    sfVector2f pos_shovel;
    sfVector2f pos_plus;
    sfVector2f pos_moins;
} vector_t;

typedef struct perlin_s
{
    float x;
    float y;
    float tempX;
    float tempY;
    int x0;
    int y0;
    int ii;
    int jj;
    int gi0;
    int gi1;
    int gi2;
    int gi3;
    float unit;
    float tmp;
    float s;
    float t;
    float u;
    float v;
    float Cx;
    float Cy;
    float Li1;
    float Li2;
} perlin_t;

typedef struct all_s
{
    texture_t *tex;
    sprite_t *sprite;
    vector_t *vector;
    int mode;
    int help;
} all_t;

char *get_next_line(int);

int md(Map_t *, sfEvent, all_t *);

int md5(Map_t *, sfEvent, all_t *);

int md10(Map_t *, sfEvent, all_t *);

int drawing(all_t *, sfRenderWindow *, Map_t *);

all_t *init_struct(void);

float Perlin(float, float, float, Map_t *);

unsigned int *perm_filler(void);

int perm_test(unsigned int *, int);

void int_filler(Map_t *, int, int);

void malloc_filler(Map_t *);

void map_rng(Map_t *, int);

void manage_map(Map_t *, int, int);

void move_map(Map_t *, int, int, int);

void raise(Map_t *, sfRenderWindow *);

Map_t *map_filler(void);

sfVector2f project_iso_point(Map_t *, int, int, int);

void vertex_filler(Map_t *);

sfColor block_text(int);

void draw_y(Map_t *, int, int);

void draw_x(Map_t *, int, int);

void draw_texture(Map_t *, int, int);

void ground_y(Map_t *, int);

void ground_x(Map_t *, int);

#endif /* !MY_WORLD_H_ */
