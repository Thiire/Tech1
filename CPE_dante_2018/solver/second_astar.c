/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** second_astar.c
*/

#include "solver.h"

void print_solved(tab_t ***tab, char **map)
{
    map[tab[0][0]->hcost - 1][tab[0][0]->fcost - 1] = 'o';
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == 'X')
                printf("\033[41m  ");
            else if (map[i][j] == '*')
                printf("\033[107m  ");
            else if (map[i][j] == 'o')
                printf("\033[42m  ");
        }
        printf("\033[49m\n");
    }
}

int number_path(tab_t ***tab, int nb, int y, int x)
{
    nb = (y < tab[0][0]->fcost - 1 && nb > tab[x][y + 1]->gcost &&
    tab[x][y + 1]->status == 1) ? tab[x][y + 1]->gcost : nb;
    nb = (y > 0 && nb > tab[x][y - 1]->gcost && nb > tab[x][y - 1]->gcost
    && tab[x][y - 1]->status == 1) ? tab[x][y - 1]->gcost : nb;
    nb = (x < tab[0][0]->hcost - 1 && nb > tab[x + 1][y]->gcost &&
    tab[x + 1][y]->status == 1) ? tab[x + 1][y]->gcost : nb;
    nb = (x > 0 && nb > tab[x - 1][y]->gcost && nb > tab[x - 1][y]->gcost
    && tab[x - 1][y]->status == 1) ? tab[x - 1][y]->gcost : nb;
    return (nb);
}

int print_path2(tab_t ***tab, int x, int y)
{
    int nb = 1000000;

    nb = number_path(tab, nb, y, x);
    if (x > 0 && tab[x - 1][y]->status == 1 && nb == tab[x - 1][y]->gcost)
        return (0);
    if (y > 0 && tab[x][y - 1]->status == 1 && nb == tab[x][y - 1]->gcost)
        return (1);
    if (x < tab[0][0]->hcost - 1 && tab[x + 1][y]->status == 1 &&
    nb == tab[x + 1][y]->gcost)
        return (2);
    if (y < tab[0][0]->fcost - 1 && tab[x][y + 1]->status == 1 &&
    nb == tab[x][y + 1]->gcost)
        return (3);
    return (4);
}

void print_path(tab_t ***tab, char **map, int x, int y)
{
    for (int stock = 0; x != 0 || y != 0;) {
        stock = print_path2(tab, x, y);
        if (stock == 0) {
            map[x - 1][y] = 'o';
            x--;
        } else if (stock == 1) {
            map[x][y - 1] = 'o';
            y--;
        }
        if (stock == 2) {
            map[x + 1][y] = 'o';
            x++;
        } else if (stock == 3) {
            map[x][y + 1] = 'o';
            y++;
        }
    }
    print_solved(tab, map);
    exit(0);
}

int nb_path(tab_t ***tab, char **map, int x, int y)
{
    int nb = 1000000;

    nb = (y < tab[0][0]->fcost - 1 && nb > tab[x][y + 1]->gcost &&
    tab[x][y + 1]->status != 1 && tab[x][y]->gcost < tab[x][y + 1]->gcost)
    ? tab[x][y + 1]->gcost : nb;
    nb = (x < tab[0][0]->hcost - 1 && nb > tab[x + 1][y]->gcost &&
    tab[x + 1][y]->status != 1 && tab[x][y]->gcost < tab[x + 1][y]->gcost)
    ? tab[x + 1][y]->gcost : nb;
    nb = (y > 0 && nb > tab[x][y - 1]->gcost && tab[x][y - 1]->status != 1 &&
    tab[x][y]->gcost < tab[x][y - 1]->gcost) ? tab[x][y - 1]->gcost : nb;
    nb = (x > 0 && nb > tab[x - 1][y]->gcost && tab[x - 1][y]->status != 1 &&
    tab[x][y]->gcost < tab[x - 1][y]->gcost) ? tab[x - 1][y]->gcost : nb;
    if (x == tab[0][0]->hcost - 2 && y == tab[0][0]->fcost - 1) {
        map[x][y] = 'o';
        print_path(tab, map, tab[0][0]->hcost - 1, tab[0][0]->fcost - 1);
    }
    return (nb);
}