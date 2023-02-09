/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** not_header
*/

#include "../includes/corewar.h"

void affing(char **tab, int fd)
{
    char type = 16;
    char spe = 64;
    char value = spe_num(tab[1]);

    if (tab[2] == NULL || tab[1][0] != 'r')
        exit(84);
    write(fd, &type, 1);
    write(fd, &spe, 1);
    write(fd, &value, 1);
}

void write_info2(char **tab, int fd)
{
    if (str_compare(tab[0], "zjmp"))
        zjmping(tab, fd);
    if (str_compare(tab[0], "ldi"))
        ldiing(tab, fd);
    if (str_compare(tab[0], "sti"))
        stiing(tab, fd);
    if (str_compare(tab[0], "fork"))
        forking(tab, fd);
    if (str_compare(tab[0], "lld"))
        llding(tab, fd);
    if (str_compare(tab[0], "lldi"))
        lldiing(tab, fd);
    if (str_compare(tab[0], "lfork"))
        lforking(tab, fd);
    if (str_compare(tab[0], "aff"))
        affing(tab, fd);
    free_tab(tab);
}

void write_info(char *info, int fd)
{
    char **tab = my_str_tab(info);

    if (str_compare(tab[0], "live"))
        living(tab, fd);
    if (str_compare(tab[0], "ld"))
        lding(tab, fd);
    if (str_compare(tab[0], "st"))
        sting(tab, fd);
    if (str_compare(tab[0], "add"))
        adding(tab, fd);
    if (str_compare(tab[0], "sub"))
        subing(tab, fd);
    if (str_compare(tab[0], "and"))
        anding(tab, fd);
    if (str_compare(tab[0], "or"))
        oring(tab, fd);
    if (str_compare(tab[0], "xor"))
        xoring(tab, fd);
    write_info2(tab, fd);
}

void not_header(char **tab, int fd)
{
    char **line;

    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] != '.') {
            write_info(tab[i], fd);
        }
    }
}