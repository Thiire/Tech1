/*
** EPITECH PROJECT, 2018
** env_fnc.c
** File description:
** env_fnc.c
*/

#include "mysh.h"

void env_fnc(char *str, char **env, listed_t *my_env)
{
    listed_t *temp = my_env;

    str += 3;
    for (; str[0] == ' ' || str[0] == '\t'; str++);
    while (temp->env != NULL && str[0] == '\0') {
        my_no_er(my_str_concat(temp->env, "\n"));
        temp = temp->next;
    }
}