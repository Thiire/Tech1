/*
** EPITECH PROJECT, 2018
** exit_fnc.c
** File description:
** exit_fnc.c
*/

#include "mysh.h"

int verifier_exit(char *str, char *name)
{
    for (int y = 0; name[y] != '\0'; y++) {
        if (name[y] < 48 || name[y] > 57) {
            my_er("exit: Expression Syntax.\n");
            return (2);
        }
    }
    for (int y = 0; str[y] != '\0'; y++) {
        if (str[y] != ' ' && str[y] != '\t' && str[y] != '\0') {
            my_er("exit: Expression Syntax.\n");
            return (2);
        }
    }
    return (0);
}

void exit_fnc(char *str, char **env, listed_t *my_env)
{
    char *name = malloc(sizeof(char) * 100);
    int n = 0;
    int door = 0;

    str += 4;
    for (; str[0] == ' ' || str[0] == '\t'; str++);
    for (n = 0; str[0] != '\0' && str[0] != ' ' && str[0] != '\t';
    n++, str++)
        name[n] = str[0];
    name[n] = '\0';
    if (verifier_exit(str, name) == 2) {
        door = 1;
    }
    if (door == 0) {
        if (isatty(0) != 0)
            my_no_er("exit\n");
        exit(my_getnbr(name));
    }
}