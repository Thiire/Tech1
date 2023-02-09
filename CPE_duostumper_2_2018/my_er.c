/*
** EPITECH PROJECT, 2019
** my_er.c
** File description:
** my_er.c
*/

#include "boogle.h"

int my_strlen(char *str)
{
    int length = 0;

    for (; str[length] != '\0'; length++);
    return (length);
}

char *my_str_concat(char *a, char *b)
{
    char *result = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));
    int i = 0;

    for (int n = 0; a[n] != '\0'; n++, i++) {
        result[i] = a[n];
    }
    for (int n = 0; b[n] != '\0'; n++, i++) {
        result[i] = b[n];
    }
    result[i] = '\0';
    return (result);
}

char **my_double_malloc(int a, int b)
{
    char **stock = malloc(sizeof(char *) * a);

    for (int i = 0; i < a; i++) {
        stock[i] = malloc(sizeof(char) * b);
        for (int n = 0; n < b; n++)
            stock[i][n] = '\0';
    }
    return (stock);
}

void my_nputchar(char c, int output)
{
    write(output, &c, 1);
}

void my_er(char *str, int output)
{
    if (output != 1 && output != 2)
        output = 1;
    for (int i = 0; str[i] != '\0'; i++)
        my_nputchar(str[i], output);
}