/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "generator.h"

char **filler(int i, int j)
{
    char **tab = my_double_malloc(i + 1, j + 1);

    if (tab == NULL)
        return (NULL);
    for (int n = 0; n < i; n++) {
        for (int k = 0; k < j; k++) {
            tab[n][k] = 'X';
        }
    }
    return (tab);
}

int dash_h(int ac, char **av)
{
    if (ac == 2 && str_compare(av[1], "-h")) {
        my_er("USAGE\n  ./generator x y [perfect]\n  ./generator x y"
        " [difficulty]\n  ./generator x y\n\n"
        "DESCRIPTION\n  The first compilation is for generate perfect maze "
        "and the other one is for generate imperfect maze.\n  The second"
        " compilation is to put a difficulty between 2 and 10 for"
        " imperfect maze\n", 1);
        exit(0);
    }
    if (ac < 3 || ac > 4)
        exit(my_er("Error: Bad arguments.\n", 2));
    return (0);
}

int perfect(char **tab, int i, int j)
{
    int nb = rand() % 24;

    if (tab == NULL)
        exit(my_er("Error: Bad arguments.\n", 2));
    var1(nb, tab, i, j);
    return (0);
}

int imperfect(char **tab, char *arg)
{
    int nb = 0;
    int rd = 5;

    if (arg != NULL && !str_compare(arg, "imperfect")) {
        if (!is_strnum(arg))
            exit(my_er("Error: Bad arguments.\n", 2));
        rd = my_getnbr(arg);
    }
    rd = (rd > 10) ? 10 : rd;
    rd = (rd <= 1) ? 2 : rd;
    if (tab == NULL)
        exit(my_er("Error: Bad arguments.\n", 2));
    perfect(tab, 0, 0);
    for (int i = 0; tab[i][0] != '\0'; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            nb = rand() % rd;
            tab[i][j] = (tab[i][j] == 'X' && nb == 1) ? '*' : tab[i][j];
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    char **tab;
    char *test = malloc(sizeof(char));

    srand((unsigned long)(test));
    dash_h(ac, av);
    tab = filler(atoi(av[1]), atoi(av[2]));
    tab[0][0] = '*';
    if (ac == 4 && str_compare("perfect", av[3])) {
        perfect(tab, 0, 0);
    } else {
        if (ac == 4)
            imperfect(tab, av[3]);
        else
            imperfect(tab, NULL);
    }
    if (tab[atoi(av[1]) - 1][atoi(av[2]) - 1] == 'X')
        return (main(ac, av));
    return (write_map(tab));
}