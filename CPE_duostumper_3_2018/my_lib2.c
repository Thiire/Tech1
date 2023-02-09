/*
** EPITECH PROJECT, 2019
** my_lib2.c
** File description:
** my_lib2.c
*/

#include "stump3.h"

int my_getnbr(char *str)
{
    int result = 0;
    int check = 0;

    if (str[0] == '-') {
        check = 1;
        str++;
    }
    for (; str[0] != '\0'; str++)
        result = result * 10 + str[0] - 48;
    if (check == 1)
        return (-result);
    return (result);
}

int check_num(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (2);
    return (0);
}
