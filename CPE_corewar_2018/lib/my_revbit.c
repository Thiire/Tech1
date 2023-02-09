/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_revbit
*/

#include "../includes/corewar.h"

void my_revbit(char *str)
{
    char tmp;

    tmp = str[0];
    str[0] = str[3];
    str[3] = tmp;
    tmp = str[1];
    str[1] = str[2];
    str[2] = tmp;
}