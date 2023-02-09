/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** way
*/

#include "generator.h"

int way1(char **tab, int i, int j, int check)
{
    if (i != 0 && tab[i - 1][j] == 'X' && (i == 1 || tab[i - 2][j] == 'X')) {
        if ((j == 0 && tab[i - 1][j + 1] == 'X') || (tab[i][j + 1] == '\0'
        && tab[i - 1][j - 1] == 'X')) {
            tab[i - 1][j] = '*';
            perfect(tab, i - 1, j);
        } else if (j != 0 && tab[i][j + 1] != '\0' && tab[i - 1][j - 1] == 'X'
        && tab[i - 1][j + 1] == 'X') {
            tab[i - 1][j] = '*';
            perfect(tab, i - 1, j);
        }
    }
    return (check);
}

int way2(char **tab, int i, int j, int check)
{
    if (tab[i + 1][0] != '\0' && tab[i + 1][j] == 'X' && (tab[i + 2][0] == '\0'
    || tab[i + 2][j] == 'X')) {
        if ((j == 0 && tab[i + 1][j + 1] == 'X') || (tab[i][j + 1] == '\0'
        && tab[i + 1][j - 1] == 'X')) {
            tab[i + 1][j] = '*';
            perfect(tab, i + 1, j);
        } else if (j != 0 && tab[i][j + 1] != '\0' && tab[i + 1][j - 1] == 'X'
        && tab[i + 1][j + 1] == 'X') {
            tab[i + 1][j] = '*';
            perfect(tab, i + 1, j);
        }
    }
    return (check);
}

int way3(char **tab, int i, int j, int check)
{
    if (j != 0 && tab[i][j - 1] == 'X' && (j == 1 || tab[i][j - 2] == 'X')) {
        if ((i == 0 && tab[i + 1][j - 1] == 'X') || (tab[i + 1][0] == '\0'
        && tab[i - 1][j - 1] == 'X')) {
            tab[i][j - 1] = '*';
            perfect(tab, i, j - 1);
        } else if (i != 0 && tab[i + 1][0] != '\0' && tab[i + 1][j - 1] == 'X'
        && tab[i - 1][j - 1] == 'X') {
            tab[i][j - 1] = '*';
            perfect(tab, i, j - 1);
        }
    }
    return (check);
}

int way4(char **tab, int i, int j, int check)
{
    if (tab[i][j + 1] != '\0' && tab[i][j + 1] == 'X' && (tab[i][j + 2] == '\0'
    || tab[i][j + 2] == 'X')) {
        if ((i == 0 && tab[i + 1][j + 1] == 'X') || (tab[i + 1][0] == '\0'
        && tab[i - 1][j + 1] == 'X')) {
            tab[i][j + 1] = '*';
            perfect(tab, i, j + 1);
        } else if (i != 0 && tab[i + 1][0] != '\0' && tab[i + 1][j + 1] == 'X'
        && tab[i - 1][j + 1] == 'X') {
            tab[i][j + 1] = '*';
            perfect(tab, i, j + 1);
        }
    }
    return (check);
}

int write_map(char **tab)
{
    int i = 0;

    for (i = 0; tab[i + 1][0] != '\0'; i++)
        printf("%s\n", tab[i]);
    printf("%s", tab[i]);
    return (0);
}
