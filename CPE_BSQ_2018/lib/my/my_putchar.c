/*
** EPITECH PROJECT, 2018
** putchar.c
** File description:
** putchar.c
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
