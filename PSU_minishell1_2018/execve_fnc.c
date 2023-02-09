/*
** EPITECH PROJECT, 2018
** execve_fnc.c
** File description:
** execve_fnc.c
*/

#include "mysh.h"

char **my_double_malloc(char *str)
{
    char **stock = malloc(sizeof(char *) * str_lgh(str));

    for (int i = 0; i < str_lgh(str); i++) {
        stock[i] = malloc(sizeof(char) * (str_lgh(str) + 1));
        for (int n = 0; n < str_lgh(str) + 1; n++)
            stock[i][n] = '\0';
    }
    return (stock);
}

int my_execve_tester(char **stock, char **stack)
{
    int diff = 0;

    for (int i = 0; stack[i] != NULL; i++) {
        if (execve(my_str_concat(stack[i], stock[0]), stock, NULL) != -1) {
            diff = 1;
            break;
        }
    }
    if (diff != 1) {
        my_er(my_str_concat(stock[0], ": Command not found.\n"));
    }
    return (0);
}

int my_path_filler(char **stock, char **stack, char *name)
{
    char *str = name;
    int i = 0;
    int n = 0;

    str += 5;
    while (str[0] != '\0') {
        for (n = 0; str[0] != '\0' && str[0] != ':'; n++, str++)
            stack[i][n] = str[0];
        stack[i][n] = '/';
        n++;
        stack[i][n] = '\0';
        if (str[0] == ':')
            str++;
        i++;
    }
    stack[i] = NULL;
    my_execve_tester(stock, stack);
    return (0);
}

int my_path_check(char **stock, listed_t *my_env)
{
    char **stack;
    char *name = "PATH\0";
    int i = 0;
    int diff = 0;

    while (my_env->env != NULL) {
        for (i = 0, diff = 0; name[i] != '\0' && diff == 0; i++)
            diff += (my_env->env[i] != name[i]) ? 1 : 0;
        if (diff == 0 && my_env->env[i] == '=') {
            break;
        }
        my_env = my_env->next;
    }
    stack = my_double_malloc(my_env->env);
    my_path_filler(stock, stack, my_env->env);
    while (my_env->prev != NULL)
        my_env = my_env->prev;
    return (0);
}

int my_arg_check(char *str, listed_t *my_env)
{
    char **stock = my_double_malloc(str);
    int i = 0;
    int error;

    for (int n = 0; str[0] != '\0'; i++) {
        for (n = 0; str[0] != '\0' && str[0] != ' ' && str[0] != '\t';
        n++, str++)
            stock[i][n] = str[0];
        stock[i][n] = '\0';
        for (; str[0] == ' ' || str[0] == '\t'; str++);
    }
    stock[i] = NULL;
    execve(stock[0], stock, NULL);
    error = errno;
    if (error == EACCES)
        my_er(my_str_concat(stock[0], ": Permission denied.\n"));
    else
        my_path_check(stock, my_env);
    return (0);
}