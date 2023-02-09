/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** cheking_map
*/

#include "solver.h"

tab_t *my_create_node(void)
{
    tab_t *node = malloc(sizeof(tab_t));

    node->fcost = 0;
    node->gcost = 0;
    node->hcost = 0;
    node->status = 0;
    return (node);
}

tab_t ***create_tab(char *buff)
{
    int height = find_height(buff);
    int width = find_width(buff, height);
    tab_t ***tab = malloc(sizeof(tab_t **) * height);

    for (int i = 0; i < height; i++) {
        tab[i] = malloc(sizeof(tab_t *) * width);
        for (int j = 0; j < width; j++)
            tab[i][j] = my_create_node();
    }
    return (tab);
}

int find_height(char *buff)
{
    int nb = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            nb++;
    }
    return (nb + 1);
}

int find_width(char *buff, int height)
{
    int nb = 0;

    if (height == 1)
        return (my_strlen(buff));
    for (; buff[nb] != '\n'; nb++);
    for (int i = nb, j = 0; j < height; j++) {
        if (j != 0 )
            i += 1;
        if (j < height)
            i += nb;
    }
    return (nb);
}

char **map_filling(char *buff, char **map)
{
    int height = find_height(buff);
    int width = find_width(buff, height);
    int j = 0;

    map = my_double_malloc(height + 1, width + 1);
    for (int i = 0, k = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\0' || buff[i] == '\n') {
            map[j][k] = '\0';
            j += 1;
            k = 0;
        } else {
            map[j][k] = buff[i];
            k++;
        }
    }
    map[j + 1] = NULL;
    return (map);
}