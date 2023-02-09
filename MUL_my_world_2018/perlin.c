/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** perlin
*/

#include "my_world.h"

int perm_test(unsigned int *tab, int result)
{
    for (int i = 0; i < 255; i++) {
        if (tab[i] == result) {
            return (0);
        }
    }
    return (1);
}

unsigned int *perm_filler(void)
{
    int nb = 0;
    int result = 0;
    unsigned int *tab = malloc(sizeof(unsigned int) * 500);
    char *test = malloc(sizeof(char) * 10);

    for (int i = 0; i < 500; tab[i++] = 0);
    srand((unsigned long)&test);
    for (; nb < 255;) {
        result = rand() % 255;
        if (perm_test(tab, result) == 1) {
            tab[nb] = result;
            nb++;
        }
        if (nb == 254)
            break;
    }
    free (test);
    return (tab);
}

float Perlin2(perlin_t *s, Map_t *map)
{
    float gradient2[][2] = {{s->unit,s->unit},{-s->unit,-s->unit},
    {-s->unit,-s->unit},{-s->unit,-s->unit},{1,0},{-1,0},{0,1},{0,-1}};

    s->s = gradient2[s->gi0][0] * s->tempX + gradient2[s->gi0][1] * s->tempY;
    s->tempX = s->x - (s->x0 + 1);
    s->tempY = s->y - s->y0;
    s->t = gradient2[s->gi1][0] * s->tempX + gradient2[s->gi1][1] * s->tempY;
    s->tempX = s->x - s->x0;
    s->tempY = s->y - (s->y0 + 1);
    s->u = gradient2[s->gi2][0] * s->tempX + gradient2[s->gi2][1] * s->tempY;
    s->tempX = s->x - (s->x0 + 1);
    s->tempY = s->y - (s->y0 + 1);
    s->v = gradient2[s->gi3][0] * s->tempX + gradient2[s->gi3][1] * s->tempY;
    s->tmp = s->x - s->x0;
    s->Cx = 3 * s->tmp * s->tmp - 2 * s->tmp * s->tmp * s->tmp;
    s->Li1 = s->s + s->Cx * (s->t - s->s);
    s->Li2 = s->u + s->Cx*(s->v - s->u);
    s->tmp = s->y - s->y0;
    s->Cy = 3 * s->tmp * s->tmp - 2 * s->tmp * s->tmp * s->tmp;
    return (s->Li1 + s->Cy*(s->Li2 - s->Li1));
}

float Perlin(float x, float y, float res, Map_t *map)
{
    perlin_t *s = malloc(sizeof(perlin_t));
    s->x = x;
    s->y = y;
    s->unit = 1.0f/sqrt(2);
    float gradient2[][2] = {{s->unit,s->unit},{-s->unit,-s->unit},
    {-s->unit,-s->unit},{-s->unit,-s->unit},{1,0},{-1,0},{0,1},{0,-1}};

    s->x /= res;
    s->y /= res;
    s->x0 = (int)(s->x);
    s->y0 = (int)(s->y);
    s->ii = s->x0 & 255;
    s->jj = s->y0 & 255;
    s->gi0 = map->perm[s->ii + map->perm[s->jj]] % 8;
    s->gi1 = map->perm[s->ii + 1 + map->perm[s->jj]] % 8;
    s->gi2 = map->perm[s->ii + map->perm[s->jj + 1]] % 8;
    s->gi3 = map->perm[s->ii + 1 + map->perm[s->jj + 1]] % 8;
    s->tempX = s->x - s->x0;
    s->tempY = s->y - s->y0;
    return (Perlin2(s, map));
}