/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parser
*/

#include "../include/my.h"

void stock_in_tunnels(char *str, info_t *gen, int *y)
{
    int j = 0;

    if (str == NULL)
        return;
    gen->tunnel[*y] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '#')
            break;
        gen->tunnel[*y][j] = str[i];
        j++;
    }
    gen->tunnel[*y][j] = '\0';
    *y += 1;
}

int is_link(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            return (0);
    return (1);
}

void stock_in_ants_nb(char *str, info_t *gen)
{
    if (str_tab(my_str_to_word_array(str, ' ')) == 1 ||
        str_tab(my_str_to_word_array(str, '-')) == 0) {
        gen->ants = my_getnbr(str);
    } else
        gen->ants = 0;
}

int parser(info_t *gen)
{
    char *str = get_next_line(0);
    int i = 0;
    int y = 0;

    gen->points = malloc(sizeof(coord_t *) * 4096);
    gen->tunnel = malloc(sizeof(char **) * 4096);
    while (str[0] != '\0') {
        if (!(str[0] == '#' && str[1] != '#') && is_link(str) == 0)
            stock_in_tunnels(str, gen, &y);
        else if (!(str[0] == '#' && str[1] != '#') && is_link(str) != 0)
            stock_in_cords(gen, str, &i);
        free(str);
        str = get_next_line(0);
    }
    gen->tunnel[y] = NULL;
    gen->points[i] = NULL;
    init_connection(gen);
    if (print_info(gen, i, y) == 1)
        return (84);
    return (0);
}
