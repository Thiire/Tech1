/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** my_listed
*/

#include "../include/my.h"

path_t *create_path(void)
{
    path_t *res = malloc(sizeof(path_t));

    res->way = my_double_malloc(50, 20);
    res->result = 0;
    return (res);
}

void push_path(char *room, path_t *path)
{
    int i = 0;

    for (i = 0; path->way[i][0] != '\0'; i++);
    path->way[i] = room;
}

path_t *path_dad(path_t *stock, path_t *path, char *room)
{
    int i = 0;

    for (i = 0; stock->way[i][0] != '\0'
    && !str_compare(stock->way[i], room); i++) {
        path->way[i] = stock->way[i];
    }
    return (path);
}

void my_auto_path(path_t **path, link_t *link, int nb)
{
    if (link->child != NULL) {
        push_path(link->in->room, path[nb]);
        my_auto_path(path, link->child, nb);
    } else if (link->child == NULL) {
        push_path(link->in->room, path[nb]);
        path[nb + 1] = create_path();
        return;
    }
    if (link->next == NULL)
        return;
    link = link->next;
    for (int lg = 0; link != NULL; link = link->next) {
        for (lg = 0; path[lg]->way[0][0] != '\0'; lg++);
        path[lg] = path_dad(path[lg - 1], create_path(), link->prev->in->room);
        push_path(link->in->room, path[lg]);
        path[lg + 1] = create_path();
        if (link->child != NULL)
            my_auto_path(path, link->child, lg);
    }
}

void path_filler(path_t **path, link_t *link, info_t *gen)
{
    int stock = 0;
    int n = 0;

    my_auto_path(path, link, 0);
    for (int i = 0; path[i]->way[0][0] != '\0'; i++) {
        for (n = 0, path[i]->result = 1000; path[i]->way[n][0] != '\0'; n++);
        stock = (n < path[i]->result &&
        str_compare(path[i]->way[n - 1], gen->end->room)) ? i : stock;
        path[stock]->result = (n < path[stock]->result && str_compare(
        path[i]->way[n - 1], gen->end->room)) ? n : path[stock]->result;
    }
    if (path[stock]->result == 1000)
        return;
    if (gen->ants == 1)
        print_one(path[stock]);
    else
        ants_pushing(path[stock], gen->ants);
}