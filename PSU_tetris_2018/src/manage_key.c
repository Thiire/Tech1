/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** manage_key
*/

#include "tetris.h"

void size_map(char *str, input_t *key)
{
    char *tmp = my_cpy(str);
    int i = 0;

    tmp += 11;
    for (; tmp[i] != '\0' && tmp[i] != ','; i++);
    tmp[i] = '\0';
    for (; str[0] != '\0' && str[0] != ','; str++);
    str++;
    key->x = my_getnbr(tmp);
    key->y = my_getnbr(str);
}