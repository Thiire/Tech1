/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** my_noder
*/

#include "../include/my.h"

void create_next(link_t *new, link_t **old)
{
    new->prev = *old;
    new->dad = (*old)->dad;
    (*old)->next = new;
    *old = new;
}

void create_child(link_t *new, link_t **old)
{
    new->dad = *old;
    (*old)->child = new;
    *old = new;
}

link_t *create_link(coord_t *coord)
{
    link_t *node = malloc(sizeof(link_t));

    node->in = coord;
    node->next = NULL;
    node->prev = NULL;
    node->child = NULL;
    node->dad = NULL;
    return (node);
}
