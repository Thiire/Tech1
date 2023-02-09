/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** check_flag2.c
*/

#include "tetris.h"

int cmp2_3(char **tab, char **tmp2, int i, input_t *key)
{
    if (i == 6 && my_strlen(tab[0]) == 13) {
        key->pause = my_cpy(&tab[0][12]);
        key->pause[1] = '\0';
    }
    if (i == 7) {
        size_map(tab[0], key);
    }
    if (i == 8 || i == 10) {
        key->next = 0;
    }
    if (i == 9 || i == 11) {
        key->debug = 1;
    }
    return (1);
}

int cmp2_2(char **tab, char **tmp2, int i, input_t *key)
{
    if (i == 2 && my_strlen(tab[0]) == 13) {
        key->right = my_cpy(&tab[0][12]);
        key->right[1] = '\0';
    }
    if (i == 3 && my_strlen(tab[0]) == 12) {
        key->turn = my_cpy(&tab[0][11]);
        key->turn[1] = '\0';
    }
    if (i == 4 && my_strlen(tab[0]) == 12) {
        key->drop = my_cpy(&tab[0][11]);
        key->drop[1] = '\0';
    }
    if (i == 5 && my_strlen(tab[0]) == 12) {
        key->quit = my_cpy(&tab[0][11]);
        key->quit[1] = '\0';
    }
    return (cmp2_3(tab, tmp2, i, key));
}

int cmp1_2(char **tab, char **tmp1, int i, input_t *key)
{
    if (i == 4 && tab[1] != NULL && my_strlen(tab[1]) == 1) {
        key->drop = my_cpy(tab[1]);
        return (2);
    }
    if (i == 5 && tab[1] != NULL && my_strlen(tab[1]) == 1) {
        key->quit = my_cpy(tab[1]);
        return (2);
    }
    if (i == 6 && tab[1] != NULL && my_strlen(tab[1]) == 1) {
        key->pause = my_cpy(tab[1]);
        return (2);
    }
    return (0);
}