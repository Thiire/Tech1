/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** instru2
*/

#include "../includes/corewar.h"

void anding(char **tab, int fd)
{

}

void oring(char **tab, int fd)
{

}

void xoring(char **tab, int fd)
{

}

void zjmping(char **tab, int fd)
{
    char type = 9, spe = 0;
    char value = spe_num(tab[1]);

    if (my_tablen(tab) != 2 || tab[1][0] != '%')
        exit(84);
    write(fd, &type, 1);
    write(fd, &spe, 1);
    write(fd, &value, 1);
}

void ldiing(char **tab, int fd)
{

}