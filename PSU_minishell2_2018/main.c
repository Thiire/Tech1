/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "mysh.h"

flag_t const flag[6] = {{"cd", &cd_fnc}, {"setenv", &setenv_fnc},
    {"unsetenv", &unsetenv_fnc}, {"env", &env_fnc}, {"exit", &exit_fnc},
    {0, NULL}};

char *env_check(env_t *my_env)
{
    env_t *tmp = my_env;

    while (tmp->stock != NULL) {
        if (tmp->stock[0] == 'H' && tmp->stock[1] == 'O' && tmp->stock[2] ==
        'M' && tmp->stock[3] == 'E' && tmp->stock[4] == '=') {
            return (tmp->stock);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

int tilt_fnc(main_t *main)
{
    int length = 0;
    char *cwd = malloc(sizeof(char) * 1000);
    char *named = env_check(main->env);

    cwd = getcwd(cwd, 1000);
    if (named == NULL) {
        my_er("> ", 1);
        return (0);
    }
    named += 5;
    for (; named[length] != '\0'; length++);
    my_er(my_str_concat("~", cwd + length), 1);
    my_er("> ", 1);
    free(cwd);
    return (0);
}

int princip_func(char **env, main_t *main, char **result)
{
    char *str;

    if (isatty(0) != 0)
        tilt_fnc(main);
    str = get_next_line(0);
    if (str[0] == '\0') {
        if (isatty(0) == 0)
            exit(0);
        else
            princip_func(env, main, result);
    }
    for (; str[0] == ' ' || str[0] == '\t'; str++);
    main->all_arg = my_str_tab(str);
    if (arg_fail(main, 0, result))
        princip_func(env, main, result);
    create_node(adapt_node(NULL, main->all_arg, -1, -1), &main->node, 1);
    /*for (; main->node->left != NULL; main->node = main->node->left) {
        printf("arg = ");
        for (int i = 0; main->node->arg[i] != NULL; i++)
            printf("%s, ", main->node->arg[i]);
        printf("\nlist = ");
        for (int i = 0; main->node->right != NULL && main->node->right->arg[i] != NULL; i++)
            printf("%s, ", main->node->right->arg[i]);
        printf("\n");
    }*/
    main->node = free_mem(main->all_arg, result);
    princip_func(env, main, result);
}

int main(int ac, char **av, char **env)
{
    main_t *main;
    char **result = result_maker();

    if (env[0] == NULL) {
        my_er("Error: No env\n", 2);
        return (84);
    }
    main = init_struct(ac, av, env);
    princip_func(env, main, result);
}