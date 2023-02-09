/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** turn_gestion
*/

#include "navy.h"

int print_update_map(char **map, int column, int line)
{
    int j = 2 + ((column - 1) * 2);
    int i = 1 + line;

    if (column == 1 && line == 0)
        return (84);
    my_printf("%c%c:  ", column + 64, line + 48);
    if (map[i][j] >= '1' && map[i][j] <= '8') {
        my_printf("hit\n\n");
        map[i][j] = 'x';
        return (10);
    } else if ( map[i][j] == 'x') {
        my_printf("missed\n\n");
        return (12);
    } else {
        my_printf("missed\n\n");
        map[i][j] = 'o';
        return (12);
    }
    return (0);
}

void initial_print(Map_t *map)
{
    my_printf("my positions:\n");
    for (int i = 0; map->map1[i] != NULL; i++)
        my_printf("%s\n", map->map1[i]);
    my_printf("\nenemy's positions:\n");
    for (int i = 0; map->map2[i] != NULL; i++)
        my_printf("%s\n", map->map2[i]);
    my_printf("\n");
}

int turn_gestion2(Map_t *map)
{
    char *str;
    int verif = 1;

    while (1) {
        if (transfer_hit(map, defense(map)) == 84)
            return (0);
        if (!win(map, map->map1))
            return (1);
        while (verif == 1) {
            my_printf("attack: ");
            str = get_next_line(0);
            if (str[0] == '\0')
                return (0);
            verif = check_input(map, str);
        }
        if (!win_check(map))
            return (0);
        initial_print(map);
        verif = 1;
    }
}

int turn_gestion1(Map_t *map)
{
    char *str;
    int verif = 1;

    while (1) {
        while (verif == 1) {
            my_printf("attack: ");
            str = get_next_line(0);
            if (str[0] == '\0')
                return (0);
            verif = check_input(map, str);
        }
        if (!win_check(map))
            return (0);
        verif = 1;
        if (transfer_hit(map, defense(map)) == 84)
            return (0);
        if (!win(map, map->map1))
            return (1);
        initial_print(map);
    }
}
