/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** my_putchar.c
*/
#include <unistd.h>

void my_putchar(char c, int *nombre)
{
    char check = (nombre[2] == 1) ? '0' : ' ';

    if (nombre[0] > 0) {
        for (int i = 1; i < nombre[0]; i++) {
            write(1, &check, 1);
        }
        write(1, &c, 1);
    } else if (nombre[0] < 0) {
        write(1, &c, 1);
        for (int i = -1; i > nombre[0]; i--) {
            write(1, " ", 1);
        }
    } else
        write(1, &c, 1);
}
