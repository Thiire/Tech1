/*
** EPITECH PROJECT, 2018
** init_struct.c
** File description:
** init_struct.c
*/

#include "mysh.h"

void create_node(char **arg, node_t **prev, int nb)
{
    node_t *last = *prev;
    node_t *new_node = malloc(sizeof(node_t));

    if (nb == 0) {
        for (; last->left->left != NULL; last = last->left);
        new_node->arg = arg;
        new_node->left = NULL;
        new_node->right = NULL;
        last->right = new_node;
    } else if (nb == 1) {
        for (; last->arg != NULL; last = last->left);
        last->arg = arg;
        new_node->arg = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
        last->left = new_node;
    }
}

void my_create_env(char *env, env_t **last)
{
    env_t *new_node = malloc(sizeof(env_t));

    new_node->stock = env;
    new_node->next = NULL;
    new_node->prev = *last;
    (*last)->next = new_node;
    *last = new_node;
}

void init_all(main_t *main, char **env)
{
    main->env = malloc(sizeof(env_t));
    main->env->stock = env[0];
    main->env->next = NULL;
    main->env->prev = NULL;
    main->node = malloc(sizeof(node_t));
    main->node->arg = NULL;
    main->node->left = NULL;
    main->node->right = NULL;
} 

main_t *init_struct(int ac, char **av, char **env)
{
    main_t *main = malloc(sizeof(main_t));
    
    main->all_arg = my_double_malloc(ac, 100);
    init_all(main, env);
    for (int i = 1; env[i] != NULL; i++)
        my_create_env(env[i], &main->env);
    while (main->env->prev != NULL)
        main->env = main->env->prev;
    return (main);
}