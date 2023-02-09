/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** instru3
*/

#include "../includes/corewar.h"

void stiing(char **tab, int fd)
{

}

void forking(char **tab, int fd)
{
    char type = 12, spe = 0;
    char value = spe_num(tab[1]);

    if (my_tablen(tab) != 2 || tab[1][0] != '%')
        exit(84);
    write(fd, &type, 1);
    write(fd, &spe, 1);
    write(fd, &value, 1);
}

void llding(char **tab, int fd)
{
    char type = 13, spe = 144, spe1 = 208, spe2 = 0;
    char value1 = spe_num(tab[1]);
    char value2 = spe_num(tab[2]);

    write(fd, &type, 1);
    if (!tab || my_tablen(tab) != 3 || tab[2][0] != 'r' || tab[1][0] == 'r')
        exit(84);
    if (tab[1][0] == '%') {
        write(fd, &spe, 1);
        write(fd, &spe2, 1);
        write(fd, &spe2, 1);
        write(fd, &spe2, 1);
    } else {
        write(fd, &spe1, 1);
        write(fd, &spe2, 1);
    }
    write(fd, &value1, 1);
    write(fd, &value2, 1);
}

void lldiing(char **tab, int fd)
{

}

void lforking(char **tab, int fd)
{
    char type = 15;
    char spe = 0;
    char value = spe_num(tab[1]);

    if (!tab || my_tablen(tab) != 2 || tab[1][0] != '%')
        exit(84);
    write(fd, &type, 1);
    write(fd, &spe, 1);
    write(fd, &value, 1);
}