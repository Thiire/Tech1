/*
** EPITECH PROJECT, 2018
** PSU_bstetris_2018
** File description:
** tetris.h
*/

#include "../lib/lib.h"

# ifndef TETRIS_H_
    # define TETRIS_H_

    typedef struct input_s
    {
        int debug;
        char *left;
        char *right;
        char *turn;
        char *drop;
        char *quit;
        char *pause;
        int next;
        int level;
        int x;
        int y;
    } input_t;

    int debug_mode(input_t *);
    void flag_check(char **, input_t *);
    void dash_h(void);
    void size_map(char *, input_t *);
    int cmp1_2(char **, char **, int, input_t *);
    int cmp2_2(char **, char **, int, input_t *);
# endif

