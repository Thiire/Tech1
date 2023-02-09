/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** ln
*/

#include "../include/my.h"

bool push_elem(list_t *list, char *data, int pos, int *cords)
{
    elem_t *new_elem = create_new_elem(data, cords[0], cords[1]);
    int i = 0;

    if (list->back == NULL && new_elem != NULL)
        push_back(list, data, cords[0], cords[1]);
    else if (list->front == NULL && new_elem != NULL)
        push_front(list, data, cords[0], cords[1]);
    else {
        for (elem_t *elem = list->front; elem != NULL
            && i < pos; elem = elem->next, i++) {
            new_elem->next = elem->next;
            new_elem->prev = elem;
            elem->next = new_elem;
            new_elem->next->prev = new_elem;
            list->size++;
        }
    }
    return (true);
}

bool push_back(list_t *list, char *data, int x, int y)
{
    elem_t *elem = create_new_elem(data, x, y);

    if (elem == NULL)
        return (false);
    if (list->back == NULL) {
        list->back = elem;
        list->front = elem;
        list->size++;
    } else {
        list->back->next = elem;
        elem->prev = list->back;
        list->back = elem;
        list->size++;
    }
    return (true);
}

bool push_front(list_t *list, char *data, int x, int y)
{
    elem_t *elem = create_new_elem(data, x, y);

    if (elem == NULL)
        return (false);
    if (list->front == NULL) {
        list->back = elem;
        list->front = elem;
        list->size++;
    } else {
        list->front->prev = elem;
        elem->next = list->front;
        list->front = elem;
        list->size++;
    }
    return (true);
}
