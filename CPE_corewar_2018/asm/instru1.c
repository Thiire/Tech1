/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** instru1
*/

#include "../includes/corewar.h"

void living(char **tab, int fd)
{
    char type = 1, spe = 0;
    char value = spe_num(tab[1]);

    if (!tab || my_tablen(tab) != 2 || tab[1][0] != '%')
        exit(84);
    write(fd, &type, 1);
    write(fd, &spe, 1);
    write(fd, &spe, 1);
    write(fd, &spe, 1);
    write(fd, &value, 1);
}

void lding(char **tab, int fd)
{
    char type = 2, spe = 144, spe1 = 208, spe2 = 0;
    char value1 = spe_num(tab[1]);
    char value2 = spe_num(tab[2]);

    if (!tab || my_tablen(tab) != 3 || tab[1][0] == 'r' || tab[2][0] != 'r')
        exit(84);
    write(fd, &type, 1);
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

void sting(char **tab, int fd)
{
    char type = 3, spe = 80, spe1 = 112, spe2 = 0;
    char value1 = spe_num(tab[1]);
    char value2 = spe_num(tab[2]);

    if (!tab || my_tablen(tab) != 3 || tab[1][0] != 'r' || tab[2][0] == '%')
        exit(84);
    write(fd, &type, 1);
    if (tab[2][0] == 'r') {
        write(fd, &spe, 1);
        write(fd, &value1, 1);
    } else {
        write(fd, &spe1, 1);
        write(fd, &value1, 1);
        write(fd, &spe2, 1);
    }
    write(fd, &value2, 1);
}

void adding(char **tab, int fd)
{
    char type = 4, spe = 84;
    char value1 = spe_num(tab[1]);
    char value2 = spe_num(tab[2]);
    char value3 = spe_num(tab[3]);

    if (!tab || my_tablen(tab) != 4 || tab[1][0] != 'r'
    || tab[2][0] != 'r' || tab[3][0] != 'r')
        exit(84);
    write(fd, &type, 1);
    write(fd, &spe, 1);
    write(fd, &value1, 1);
    write(fd, &value2, 1);
    write(fd, &value3, 1);
}

void subing(char **tab, int fd)
{
    char type = 5, spe = 84;
    char value1 = spe_num(tab[1]);
    char value2 = spe_num(tab[2]);
    char value3 = spe_num(tab[3]);

    if (!tab || my_tablen(tab) != 4 || tab[1][0] != 'r'
    || tab[2][0] != 'r' || tab[3][0] != 'r')
        exit(84);
    write(fd, &type, 1);
    write(fd, &spe, 1);
    write(fd, &value1, 1);
    write(fd, &value2, 1);
    write(fd, &value3, 1);
}