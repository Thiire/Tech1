/*
** EPITECH PROJECT, 2018
** my_main_sh.c
** File description:
** my_main_sh.c
*/

#include "mysh.h"

typer_t static const flag[6] = {{"cd", &cd_fnc}, {"setenv", &setenv_fnc},
{"unsetenv", &unsetenv_fnc}, {"env", &env_fnc}, {"exit", &exit_fnc},
{0, NULL}};

void check_error(char *str, listed_t *my_env)
{
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        my_arg_check(str, my_env);
        exit (0);
    } else
        waitpid(pid, &status, 0);
    if (WIFSIGNALED(status) && WCOREDUMP(status)) {
        if (status == SIGSEGV) {
            my_er("Segmentation fault (core dumped)\n");
        } else if (status == SIGFPE)
            my_er("Floating exception (core dumped)\n");
    } else if (WIFSIGNALED(status)) {
        if (status == SIGSEGV) {
            my_er("Segmentation fault\n");
        } else if (status == SIGFPE)
            my_er("Floating exception\n");
    }
}

int tilt_fnc(char *named, char *cwd)
{
    int length = 0;

    if (named == NULL) {
        my_no_er("> ");
        return (0);
    }
    named += 5;
    if (named[0] == '/' && named[1] == 'r' && named[2] == 'o'
    && named[3] == 'o' && named[4] == 't' && named[5] == '\0') {
        my_no_er("> ");
        return (0);
    }
    for (; named[length] != '\0'; length++);
    my_no_er(my_str_concat("~", cwd + length));
    my_no_er("> ");
    return (0);
}

int my_check(char *str, char **env, listed_t *my_env)
{
    int d = -1;
    int verif = 0;
    int i = 0;
    int y = 0;

    for (i = 0; i < 5; i++) {
        d = -1;
        for (y = 0; d == -1 && flag[i].name[y] != '\0'; y++) {
            d += (flag[i].name[y] != str[y]) ? 1 : 0;
        }
        if (d == -1 && (str[y] == ' ' || str[y] == '\0' || str[y] == '\t')) {
            verif++;
            flag[i].fnc_call(str, env, my_env);
            break;
        }
    }
    if (verif == 0)
        check_error(str, my_env);
    return (0);
}

int princip_func(char **env, listed_t *my_env)
{
    char *str;
    char *cwd = malloc(sizeof(char) * 1000);
    char *named = env_check(env, my_env);

    cwd = getcwd(cwd, 1000);
    if (isatty(0) != 0)
        tilt_fnc(named, cwd);
    str = get_next_line(0);
    for (; str[0] == ' ' || str[0] == '\t'; str++);
    if (str[0] == '\0')
        exit(0);
    my_check(str, env, my_env);
    princip_func(env, my_env);
}

int main(int ac, char **av, char **env)
{
    listed_t *my_env = malloc(sizeof(listed_t));

    my_env->env = env[0];
    my_env->next = NULL;
    my_env->prev = NULL;
    for (int i = 1; env[i] != NULL; i++) {
        my_create_env(env[i], &my_env);
    }
    my_create_env(NULL, &my_env);
    while (my_env->prev != NULL)
        my_env = my_env->prev;
    princip_func(env, my_env);
    return (0);
}