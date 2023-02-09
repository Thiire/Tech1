/*
** EPITECH PROJECT, 2019
** lib_p2.c
** File description:
** lib_p2.c
*/

#include "lib.h"

int zero(int calcul, int nombre)
{
    if (calcul == -1)
        nombre = nombre * -1;
    return (nombre);
}

int my_getnbr(char const *str)
{
    int calcul = 1;
    long nombre = 0;
    int i;

    if (str == NULL)
        return (0);
    for (i = 0 ; str[i] == '-' || str[i] == '+' ; i++)
        if (str[i] == '-')
            if (str[i + 1] >= '0' && str[i + 1] <= '9')
                calcul = -1;
    for (int j = i; (str[j] != '\0') && (str[j] >= '0' && str[j] <= '9'); j++)
        nombre = nombre * 10 + str[j] - 48;
    return (zero(calcul, nombre));
}

char **tab_filler(char *str)
{
    char **tab = NULL;
    int n = 2;
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++)
        n += (str[i] == '\n') ? 1 : 0;
    tab = my_double_malloc(n, 100);
    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            y += 1;
            j = 0;
        } else {
            tab[y][j] = str[i];
            j += 1;
        }
    }
    tab[y + 1] = NULL;
    return (tab);
}

int my_fullcompare(char *str1, char *str2)
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

void my_intout(int nb, int output)
{
    if (output != 1 && output != 2)
        output = 1;
    if (nb > 9)
        my_intout(nb / 10, output);
    my_putchar(nb % 10 + 48, output);
}