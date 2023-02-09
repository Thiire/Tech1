/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** astar
*/

#include "solver.h"

int find_lower2(tab_t ***tab, int x, int y, char **map)
{
    int nb = nb_path(tab, map, x, y);
    int check = 2;

    if (y > 0 && tab[x][y - 1]->status != 1 && nb == tab[x][y - 1]->gcost) {
        tab[x][y - 1]->status = 1;
        check = check_cost(tab, x, y - 1, map);
    } else if (x > 0 && tab[x - 1][y]->status != 1 &&
    nb == tab[x - 1][y]->gcost) {
        tab[x - 1][y]->status = 1;
        check = check_cost(tab, x - 1, y, map);
    }
    return (check);
}

int find_lower(tab_t ***tab, int x, int y, char **map)
{
    int nb = nb_path(tab, map, x, y);
    int check = 2;

    if (y < tab[0][0]->fcost - 1 && tab[x][y + 1]->status != 1 &&
    nb == tab[x][y + 1]->gcost) {
        tab[x][y + 1]->status = 1;
        check = check_cost(tab, x, y + 1, map);
    } else if (x < tab[0][0]->hcost - 1 && tab[x + 1][y]->status != 1 &&
    nb == tab[x + 1][y]->gcost) {
        tab[x + 1][y]->status = 1;
        check = check_cost(tab, x + 1, y, map);
    } else {
        check = find_lower2(tab, x, y, map);
    }
    if (check == 0)
        find_lower(tab, x, y, map);
    return (check);
}

void check_cost2(tab_t ***tab, int x, int y, char **map)
{
    if (y > 0 && map[x][y - 1] == '*' &&
    tab[x][y - 1]->status != 1 && (tab[x][y]->gcost + 1 <
    tab[x][y - 1]->gcost || tab[x][y - 1]->gcost == 0)) {
        tab[x][y - 1]->gcost = tab[x][y]->gcost + 1;
        tab[x][y - 1]->hcost = (tab[0][0]->hcost + tab[0][0]->fcost) -
        (x + y - 1);
        tab[x][y - 1]->fcost = tab[x][y - 1]->gcost + tab[x][y - 1]->hcost;
    }
    if (x > 0 && map[x - 1][y] == '*' &&
    tab[x - 1][y]->status != 1 && (tab[x][y]->gcost + 1 <
    tab[x - 1][y]->gcost || tab[x - 1][y]->gcost == 0)) {
        tab[x - 1][y]->gcost = tab[x][y]->gcost + 1;
        tab[x - 1][y]->hcost = (tab[0][0]->hcost + tab[0][0]->fcost) -
        (x + y - 1);
        tab[x - 1][y]->fcost = tab[x - 1][y]->gcost + tab[x - 1][y]->hcost;
    }
}

int check_cost(tab_t ***tab, int x, int y, char **map)
{
    if (y < tab[0][0]->fcost - 1 && map[x][y + 1] == '*' &&
    tab[x][y + 1]->status != 1 && (tab[x][y]->gcost + 1 <
    tab[x][y + 1]->gcost || tab[x][y + 1]->gcost == 0)) {
        tab[x][y + 1]->gcost = tab[x][y]->gcost + 1;
        tab[x][y + 1]->hcost = (tab[0][0]->hcost + tab[0][0]->fcost) -
        (x + y + 1);
        tab[x][y + 1]->fcost = tab[x][y + 1]->gcost + tab[x][y + 1]->hcost;
    }
    if (x < tab[0][0]->hcost - 1 && map[x + 1][y] == '*' &&
    tab[x + 1][y]->status != 1 && (tab[x][y]->gcost + 1 <
    tab[x + 1][y]->gcost || tab[x + 1][y]->gcost == 0)) {
        tab[x + 1][y]->gcost = tab[x][y]->gcost + 1;
        tab[x + 1][y]->hcost = (tab[0][0]->hcost + tab[0][0]->fcost) -
        (x + y + 1);
        tab[x + 1][y]->fcost = tab[x + 1][y]->gcost + tab[x + 1][y]->hcost;
    }
    check_cost2(tab, x, y, map);
    find_lower(tab, x, y, map);
    return (0);
}

int solve_maze(char *buff)
{
    char **map = NULL;
    tab_t ***tab = create_tab(buff);

    tab[0][0]->status = 1;
    tab[0][0]->hcost = find_height(buff);
    tab[0][0]->fcost = find_width(buff, tab[0][0]->hcost);
    map = map_filling(buff, map);
    check_cost(tab, 0, 0, map);
    printf("There is no solution\n");
    return (84);
}