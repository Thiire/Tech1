/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** stock_info
*/

#include "../include/my.h"

void alloc_values(coord_t *cord)
{
    cord->room = NULL;
    cord->connection = NULL;
    cord->error = 0;
    cord->x = 0;
    cord->y = 0;
    cord->type = 0;
}

coord_t *init_cord(char *str, int type)
{
    coord_t *cord = malloc(sizeof(coord_t));
    char **tab = NULL;
    int i = 0;

    tab = my_str_to_word_array(str, ' ');
    if (str_tab(tab) < 3) {
        alloc_values(cord);
        i = 1;
    }
    cord->room = my_strdup(tab[0]);
    cord->connection = malloc(sizeof(char *) * 4096);
    cord->error = 0;
    cord->x = i == 0 ? my_getnbr(tab[1]) : 0;
    cord->y = i == 0 ? my_getnbr(tab[2]) : 0;
    cord->type = type;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    return (cord);
}

void stock_in_cords(info_t *gen, char *str, int *i)
{
    if (my_strcmp("##start", str) == 0) {
        str = get_next_line(0);
        gen->start = init_cord(str, 1);
        gen->points[*i] = init_cord(str, 1);
        *i += 1;
    } else if (my_strcmp("##end", str) == 0) {
        str = get_next_line(0);
        gen->end = init_cord(str, 2);
        gen->points[*i] = init_cord(str, 2);
        *i += 1;
    } else {
        gen->points[*i] = init_cord(str, 0);
        *i += 1;
    }
}

void cmp_and_stock(char *tunnel, coord_t *cord, int *j)
{
    char **tab = my_str_to_word_array(tunnel, '-');

    if (my_strcmp(cord->room, tab[0]) == 0) {
        cord->connection[*j] = my_strdup(tab[1]);
        *j += 1;
    } else if (my_strcmp(cord->room, tab[1]) == 0) {
        cord->connection[*j] = my_strdup(tab[0]);
        *j += 1;
    }
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void parse_info_and_stock(coord_t *cord, char **tunnel)
{
    int j = 0;

    for (int i = 0; tunnel[i] != NULL; i++)
        cmp_and_stock(tunnel[i], cord, &j);
    cord->connection[j] = NULL;
}

void init_connection(info_t *gen)
{
    for (int i = 0; gen->points[i] != NULL; i++)
        parse_info_and_stock(gen->points[i], gen->tunnel);
}
