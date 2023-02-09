/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** my_check
*/

#include "navy.h"

int check_input(Map_t *map, char *str)
{
    int line = 0;
    int column = 0;

    if ((str[0] < 'A' || str[0] > 'H') || (str[1] < '1' || str[1] > '8')
    || str[2] != '\0') {
        my_er("wrong position\n", 1);
        return (1);
    }
    my_printf("%c%c:  ", str[0], str[1]);
    column = str[0] - 64;
    line = str[1] - 48;
    return (attack(map, column, line));
}

int result_check(int *result)
{
    int check = 0;

    for (int i = 0; i < 8 && check != 1; i++) {
        for (int n = 0; i < 8 && check != 1; i++) {
            check = (result[i] == result[n] && result[i] != 0
            && result[n] != 0 && n != i) ? 1 : 0;
        }
    }
    if (check == 1)
        return (84);
    return (0);
}

int check_map3(char **map, int *result)
{
    int j = 2;
    int i = 2;
    int check = 0;
    int nb = 0;

    for (int i = 0; i < 8; i++)
        nb += result[i];
    if (nb > 14)
        return (84);
    for (; i < 10; i++)
        for (j = 2; j < 17; j++)
            check += (map[i][j] >= '1' && map[i][j] <= '8') ? 1 : 0;
    if (check != nb)
        return (84);
    return (0);
}

int check_map2(char *str)
{
    int check = 0;

    if ((str[2] == str[5]) && (MAX(str[3], str[6]) - MIN(str[3], str[6]) + 1 ==
    str[0] - 48)) {
        return (0);
    } else if ((str[3] == str[6]) && (MAX(str[2], str[5]) - MIN(str[2], str[5])
    + 1 == str[0] - 48)) {
        return (0);
    } else {
        return (84);
    }
}

int check_map(char *str)
{
    if (my_strlen(str) != 7)
        return (84);
    if (str[0] <= '1' || str[0] >= '6')
        return (84);
    if (str[1] != ':')
        return (84);
    if (str[2] < 'A' || str[2] > 'H')
        return (84);
    if (str[3] < '1' || str[3] > '8')
        return (84);
    if (str[4] != ':')
        return (84);
    if (str[5] < 'A' || str[5] > 'H')
        return (84);
    if (str[6] < '1' || str[6] > '8')
        return (84);
    return (check_map2(str));
}
