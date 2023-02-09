/*
** EPITECH PROJECT, 2018
** env_check.c
** File description:
** env_check.c
*/

#include "mysh.h"

char *env_check(char **env, listed_t *my_env)
{
    listed_t *temp = my_env;

    while (temp->env != NULL) {
        if (temp->env[0] == 'H' && temp->env[1] == 'O' && temp->env[2] ==
        'M' && temp->env[3] == 'E' && temp->env[4] == '=') {
            return (temp->env);
        }
        temp = temp->next;
    }
    return (NULL);
}