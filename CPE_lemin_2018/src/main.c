/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main.c
*/

#include "../include/my.h"

int main(void)
{
    info_t *general = malloc(sizeof(info_t));
    path_t **path = malloc(sizeof(path_t *) * 100);

    path[0] = create_path();
    general->ants = my_getnbr(get_next_line(0));
    if (general->ants <= 0)
        return (84);
    if (parser(general) == 84)
        return (84);
    my_printf("#moves\n");
    my_graph(general, path);
    free_struct(general, path);
    return (0);
}
