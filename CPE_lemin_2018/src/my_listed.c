/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** my_listed
*/

#include "../include/my.h"

coord_t *find_room(coord_t **points, char *room_name)
{
    for (int i = 0; points[i]->room != NULL; i++) {
        if (str_compare(points[i]->room, room_name))
            return (points[i]);
    }
    return (NULL);
}

int graph_verif(link_t *link, char *room_name)
{
    link_t *tmp = malloc(sizeof(link_t));
    int check = 0;

    tmp = link;
    for (; tmp != NULL; tmp = tmp->dad) {
        check += (str_compare(tmp->in->room, room_name)) ? 1 : 0;
    }
    if (check >= 1)
        return (0);
    else
        return (1);
}

void my_auto_graph2(link_t *link, info_t *gen, int i)
{
    for (; link->dad->in->connection[i] != NULL; i++) {
        if (graph_verif(link, link->dad->in->connection[i])) {
            create_next(create_link(find_room(gen->points,
            link->dad->in->connection[i])), &link);
        }
    }
    for (; link != NULL; link = link->prev)
        my_auto_graph(link, gen);
}

void my_auto_graph(link_t *link, info_t *gen)
{
    int i = 0;

    if (str_compare(link->in->room, gen->end->room))
        return;
    for (; link->in->connection[i] != NULL; i++) {
        if (graph_verif(link->dad, link->in->connection[i])) {
            create_child(create_link(find_room(gen->points,
            link->in->connection[i])), &link);
            my_auto_graph2(link, gen, i + 1);
            break;
        }
    }
}

void my_graph(info_t *gen, path_t **path)
{
    gen->link = create_link(find_room(gen->points, gen->start->room));
    my_auto_graph(gen->link, gen);
    path_filler(path, gen->link, gen);
}
