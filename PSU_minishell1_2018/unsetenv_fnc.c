/*
** EPITECH PROJECT, 2018
** unsetenv_fnc.c
** File description:
** unsetenv_fnc.c
*/

#include "mysh.h"

int replacer_unset(char *name, listed_t *my_env)
{
    char *stock = malloc(sizeof(char) * 100);

    while (my_env->next->env != NULL) {
        my_env->env = my_env->next->env;
        my_env = my_env->next;
    }
    my_env->env = NULL;
    return (0);
}

int mover_unset(char *name, char **env, listed_t *my_env)
{
    int diff = 0;
    int i = 0;

    while (my_env->env != NULL) {
        for (i = 0, diff = 0; name[i] != '\0' && diff == 0; i++)
            diff += (my_env->env[i] != name[i]) ? 1 : 0;
        if (diff == 0 && my_env->env[i] == '=') {
            replacer_unset(name, my_env);
            break;
        }
        my_env = my_env->next;
    }
    while (my_env->prev != NULL)
        my_env = my_env->prev;
    return (0);
}

int looper_unset(char *str, char **env, listed_t *my_env)
{
    char *name = malloc(sizeof(char) * 100);
    int n = 0;

    while (str[0] != '\0') {
        for (n = 0; str[0] != '\0' && str[0] != ' ' && str[0] != '\t';
        n++, str++)
            name[n] = str[0];
        name[n] = '\0';
        for (; str[0] == ' ' || str[0] == '\t'; str++);
        mover_unset(name, env, my_env);
    }
    return (0);
}

void unsetenv_fnc(char *str, char **env, listed_t *my_env)
{
    str += 8;
    for (; str[0] == ' ' || str[0] == '\t'; str++);
    if (str[0] == '\0') {
        my_er("unsetenv: Too few arguments.\n");
    } else {
        looper_unset(str, env, my_env);
    }
}