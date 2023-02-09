/*
** EPITECH PROJECT, 2018
** usefull
** File description:
** printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

flag_t const tab[30] = {
    {'d', &printf_d},
    {'i', &printf_i},
    {'o', &printf_o},
    {'x', &printf_x},
    {'u', &printf_u},
    {'p', &printf_p},
    {'b', &printf_b},
    {'c', &printf_c},
    {'s', &printf_s},
    {'S', &printf_big_s},
    {'X', &printf_big_x},
    {'%', &printf_percent},
    {'z', &printf_z},
    {'a', &printf_z},
    {'e', &printf_z},
    {'f', &printf_z},
    {'g', &printf_z},
    {'h', &printf_z},
    {'j', &printf_z},
    {'k', &printf_z},
    {'l', &printf_z},
    {'m', &printf_z},
    {'n', &printf_z},
    {'q', &printf_z},
    {'r', &printf_z},
    {'t', &printf_z},
    {'v', &printf_z},
    {'w', &printf_z},
    {'y', &printf_z},
    {0, NULL}
};

void my_printf(char *s, ...)
{
    va_list va;
    va_start(va, s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            flag(s[i + 1], va);
            i++;
    } else
            my_putchar(s[i]);
    }
}

int flag(char c, va_list va)
{
    for (int i = 0; tab[i].type != 0; i++) {
        if (tab[i].type == c) {
            tab[i].fptr(va);
        return (0);
        }
    }
    return (0);
}