/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** my_create_map
*/

#include "navy.h"

void filler_bis(char **map)
{
    for (int i = 2; i < 10; i++) {
        map[i][0] = 47 + i;
        map[i][1] = '|';
        for (int n = 2; n < 16; n += 2) {
            map[i][n] = '.';
            map[i][n + 1] = ' ';
        }
        map[i][16] = '.';
    }
}

char **filler(void)
{
    char **map = my_double_malloc();

    map[0][0] = ' ';
    map[0][1] = '|';
    for (int i = 2, n = 0; i < 16; i += 2, n++) {
        map[0][i] = 65 + n;
        map[0][i + 1] = ' ';
    }
    map[0][16] = 'H';
    map[1][0] = '-';
    map[1][1] = '+';
    for (int i = 2; i < 17; i++)
        map[1][i] = '-';
    filler_bis(map);
    map[10] = NULL;
    return (map);
}

void reader(char **map, char *str)
{
    char nb = str[0];
    char pos1 = str[2];
    char pos2 = str[5];
    char num1 = str[3];
    char num2 = str[6];

    if (pos1 == pos2 && num2 >= num1)
        for (int i = 0; i < num2 - num1 + 1; i++)
            map[num1 - 47 + i][2 + ((pos1 - 65) * 2)] = nb;
    if (pos1 == pos2 && num1 > num2)
        for (int i = 0; i < num1 - num2 + 1; i++)
            map[num2 - 47 + i][2 + ((pos1 - 65) * 2)] = nb;
    if (num1 == num2 && pos2 >= pos1)
        for (int i = 0; i < pos2 - pos1 + 1; i++)
            map[num2 - 47][2 + ((pos1 - 65) * 2) + i + i] = nb;
    if (num1 == num2 && pos1 >= pos2)
        for (int i = 0; i < pos1 - pos2 + 1; i++)
            map[num2 - 47][2 + ((pos2 - 65) * 2) + i + i] = nb;
}

char **my_create_map(char *name)
{
    char **map = filler();
    int fd = 0;
    char *str;
    int *result = malloc(sizeof(int) * 8);

    fd = open(name, O_RDONLY);
    for (int i = 0; 1; i++) {
        str = get_next_line(fd);
        if (str[0] == '\0')
            break;
        if (check_map(str) == 84)
            return (NULL);
        result[i] += str[0] - 48;
        if (result_check(result) == 84)
            return (NULL);
        reader(map, str);
    }
    if (check_map3(map, result) == 84)
        return (NULL);
    return (map);
}

char **enemy_map(void)
{
    char **map = filler();

    return (map);
}