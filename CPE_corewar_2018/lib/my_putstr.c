/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char *str);

void my_put_err(char *str)
{
    write(2, str, my_strlen(str));
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_puttab(char  **tab)
{
    int i = 0;

    for (; tab[i + 1]; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    my_putstr(tab[i]);
}