/*
** EPITECH PROJECT, 2018
** cd_fnc.c
** File description:
** cd_fnc.c
*/

#include "mysh.h"

char *replace_cd(char *cwd, listed_t *my_env, char *preced)
{
    int diff = 0;
    int diff2 = 0;
    char *name = "OLDPWD=\0";
    char *name2 = "PWD=\0";
    char *cwd2 = malloc(sizeof(char) * 1000);

    cwd2 = getcwd(cwd2, 1000);
    for (int i = 0; my_env->env != NULL;) {
        for (i = 0, diff = 0; name[i] != '\0' && diff == 0; i++)
            diff += (my_env->env[i] != name[i]) ? 1 : 0;
        for (i = 0, diff2 = 0; name2[i] != '\0' && diff2 == 0; i++)
            diff2 += (my_env->env[i] != name2[i]) ? 1 : 0;
        if (diff == 0) {
            my_env->env = my_str_concat(name, cwd);
        } else if (diff2 == 0) {
            my_env->env = my_str_concat(name2, cwd2);
        }
        my_env = my_env->next;
    }
    return (cwd);
}

int may_folder(char *name)
{
    struct stat folder;

    if (name[0] == 'C' && name[1] == 'd' && name[2] == 'M' && name[3] == 'i'
    && name[4] == 'n' && name[5] == '\0') {
        my_er(": No such file or directory.\n");
        return (0);
    }
    if (stat(name, &folder) != -1)
        my_er(my_str_concat(name, ": Not a directory.\n"));
    else
        my_er(my_str_concat(name, ": No such file or directory.\n"));
    return (0);
}

char *home_check(char *str, char **env, listed_t *my_env)
{
    if (str[0] == '-' && str[1] == '\0')
        return ("CdMin");
    if (str[0] == 'h' && str[1] == 'o' && str[2] == 'm' && str[3] == 'e'
    && str[4] == '\0') {
        my_no_er("~ \n");
        return (env_check(env, my_env) + 5);
    }
    return (str);
}

char *verifier_cd(char *str, char **env, listed_t *my_env, char *preced)
{
    char *name = malloc(sizeof(char) * 100);
    int n = 0;

    for (n = 0; str[0] != '\0' && str[0] != ' ' && str[0] != '\t'; n++, str++)
        name[n] = str[0];
    name[n] = '\0';
    if (name[0] == '\0')
        return (env_check(env, my_env) + 5);
    for (int y = 0; str[y] != '\0'; y++) {
        if (str[y] != ' ' && str[y] != '\t' && str[y] != '\0') {
            my_er("cd: Too many arguments.\n");
            return (NULL);
        }
    }
    if (name[0] == '-' && name[1] == '\0' && preced != NULL)
        return (preced);
    return (home_check(name, env, my_env));
}

void cd_fnc(char *str, char **env, listed_t *my_env)
{
    static int stock;
    static char *preced;
    char *name;
    char *cwd = malloc(sizeof(char) * 1000);

    cwd = getcwd(cwd, 1000);
    if (stock == 0) {
        stock = 1;
        preced = malloc(sizeof(char) * 1000);
        preced = NULL;
    }
    for (str += 2; str[0] == ' ' || str[0] == '\t'; str++);
    if ((name = verifier_cd(str, env, my_env, preced)) != NULL) {
        if (chdir(name) == -1)
            may_folder(name);
        else {
            preced = replace_cd(cwd, my_env, preced);
            for (;my_env->prev != NULL; my_env = my_env->prev);
        }
    }
}