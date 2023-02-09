/*
** EPITECH PROJECT, 2018
** list_creator.c
** File description:
** list_creator.c
*/

#include "mysh.h"

void my_create_env(char *env, listed_t **last)
{
    listed_t *new_node = malloc(sizeof(listed_t));

    new_node->env = env;
    new_node->next = NULL;
    new_node->prev = *last;
    (*last)->next = new_node;
    *last = new_node;
}