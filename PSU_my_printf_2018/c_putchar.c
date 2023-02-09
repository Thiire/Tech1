/*
** EPITECH PROJECT, 2018
** c_putchar.c
** File description:
** c_putchar.c
*/
#include <unistd.h>

void c_putchar(char c)
{
    write(1, &c, 1);
}
