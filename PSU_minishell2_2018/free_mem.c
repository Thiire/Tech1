/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** free_mem.c
*/

#include "mysh.h"

node_t *free_mem(char **str, char **result)
{
    node_t *new_node = malloc(sizeof(node_t));
    int length = 0;

    new_node = malloc(sizeof(node_t));
    new_node->arg = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

char **adapt_node(char *str, char **tmp, int i, int nb)
{
    char **stock;
    int length = 1;

    if (str != NULL) {
        stock = my_double_malloc(2, my_strlen(str));
        stock[0] = str;
        stock[1] = NULL;
    } else if (nb == -1) {
        for (; tmp[length + i] != NULL; length++);
        stock = my_double_malloc(length, 200);
        for (length = 0; tmp[i + 1] != NULL; length++, i++)
            stock[length] = tmp[i + 1];
        stock[length] = NULL;
    } else {
        stock = my_double_malloc(nb - i, 200);
        for (length = 0; i + 1 < nb; length++, i++)
            stock[length] = tmp[i + 1];
        stock[length] = NULL;
    }
    return (stock);
}