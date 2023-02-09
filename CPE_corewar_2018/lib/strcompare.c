/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** strcompare
*/

#include "../includes/corewar.h"

int strcomp_begin(char *str1, char *str2)
{
    if (!str1 || !str2)
        return (84);
    for (int i = 0; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    return (0);
}