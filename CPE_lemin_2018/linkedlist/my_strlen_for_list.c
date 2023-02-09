/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** ln
*/

#include "../include/my.h"

int my_strlen_for_list(list_t *list)
{
    size_t n = 0;
    elem_t *elem = list->front;

    while (elem != NULL) {
        n++;
        elem = elem->next;
    }
    return (n);
}
