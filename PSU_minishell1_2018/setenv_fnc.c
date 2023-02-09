/*
** EPITECH PROJECT, 2018
** setenv_fnc.c
** File description:
** setenv_fnc.c
*/

#include "mysh.h"

char *env_replacer(char *name, char *arg)
{
    char *result = malloc(sizeof(char) * 100);
    int i = 0;

    for (i = 0; name[i] != '\0'; i++)
        result[i] = name[i];
    result[i] = '=';
    i += 1;
    for (int n = 0; arg[n] != '\0'; n++, i++)
        result[i] = arg[n];
    result[i] = '\0';
    return (result);
}

int env_fuller(listed_t *my_env, char *name, char *arg)
{
    int diff = 0;
    int i = 0;

    while (my_env->env != NULL) {
        for (i = 0, diff = 0; name[i] != '\0' && diff == 0; i++)
            diff += (my_env->env[i] != name[i]) ? 1 : 0;
        if (diff == 0 && my_env->env[i] == '=') {
            my_env->env = env_replacer(name, arg);
            break;
        }
        my_env = my_env->next;
    }
    if (my_env->env == NULL) {
        my_env->env = env_replacer(name, arg);
        my_create_env(NULL, &my_env);
    }
    while (my_env->prev != NULL)
        my_env = my_env->prev;
    return (0);
}

int valid_env(char *nm, char **env, char *str, listed_t *my_env)
{
    int i = 0;
    char *arg = malloc(sizeof(char) * 100);

    for (int j = 0; nm[j] != '\0'; j++) {
        if ((nm[j] < 48 || nm[j] > 57) && (nm[j] < 65 || nm[j] > 122)) {
            my_er("setenv: Variable name must contain"
            " alphanumeric characters.\n");
            return (0);
        }
    }
    for (; str[0] != '\0' && str[0] != ' ' && str[0] != '\t'; i++, str++)
        arg[i] = str[0];
    for (int y = 0; str[y] != '\0'; y++) {
        if (str[y] != ' ' && str[y] != '\t' && str[y] != '\0') {
            my_er("setenv: Too many arguments.\n");
            return (0);
        }
    }
    arg[i] = '\0';
    return (env_fuller(my_env, nm, arg));
}

void setenv_fnc(char *str, char **env, listed_t *my_env)
{
    char *name = malloc(sizeof(char) * 100);
    int n = 0;

    str += 6;
    for (; str[0] == ' ' || str[0] == '\t'; str++);
    if (str[0] == '\0') {
        env_fnc(str, env, my_env);
    } else {
        for (n = 0; str[0] != '\0' && str[0] != ' ' && str[0] != '\t';
        n++, str++)
            name[n] = str[0];
        name[n] = '\0';
        for (; str[0] == ' ' || str[0] == '\t'; str++);
        if (name[0] >= 48 && name[0] <= 57)
            my_er("setenv: Variable name must begin with a letter.\n");
        else
            valid_env(name, env, str, my_env);
    }
}