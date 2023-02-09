/*
** EPITECH PROJECT, 2019
** my_er.c
** File description:
** my_er.c
*/

#include "n4s.h"

int my_parsing(char *str1, char *str2)
{
    int j = 0;

    for (int i = 0; str1[i] != '\0';) {
        for (j = 0; str2[j] != '\0' && str1[i] == str2[j]; j++, i++);
        if (str2[j] == '\0') {
            return (1);
        } else if (j == 0)
            i++;
    }
    return (0);
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int str_compare(char *c1, char *c2)
{
    if (c1 == NULL || c2 == NULL)
        return (0);
    if (my_strlen(c1) != my_strlen(c2))
        return (0);
    for (int i = 0; c1[i] != '\0' && c2[i] != '\0'; i++) {
        if (c1[i] != c2[i]) {
            return (0);
        }
    }
    return (1);
}

void my_nputchar(char c, int output)
{
    write(output, &c, 1);
}

int my_er(char *str, int output)
{
    if (output != 1 && output != 2)
        output = 1;
    for (int i = 0; str[i] != '\0'; i++)
        my_nputchar(str[i], output);
    if (output == 2)
        return (84);
    return (0);
}