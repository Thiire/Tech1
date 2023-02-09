/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asming
*/

#include "../includes/corewar.h"

int can_open(char *name)
{
    int fd = open(name, O_RDONLY);

    if (fd == -1) {
        my_put_err("Cannot open file : ");
        my_put_err(name);
        my_put_err(".\nPlease, be sure that the file exists and that the"
        " rights are correctly set.\n");
        return (-1);
    }
    return (fd);
}

char **get_all_file(int fd)
{
    char **tab = my_double_malloc(100, 100);
    char *temp = get_next_line(fd);
    int i = 0;

    while (temp) {
        if (temp[0] != '#' && temp[0] != 0) {
            tab[i] = cn(temp);
            i++;
        }
        free(temp);
        temp = get_next_line(fd);
    }
    tab[i] = NULL;
    close(fd);
    return (tab);
}

header_t *set_header(char **tab)
{
    int verif = 0;
    header_t *header = malloc(sizeof(header_t));
    header->prog_size = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (!my_strcmp(".name", tab[i])) {
            if (setting_name(tab[i], header))
                aff_err();
            verif += 1;
        }
        if (!my_strcmp(".comment", tab[i])) {
            if (setting_comment(tab[i], header))
                aff_err();
            verif += 1;
        }
    }
    if (verif != 2)
        aff_err();
    header->magic = COREWAR_EXEC_MAGIC;
    return (header);
}

char *naming_cor(char *name)
{
    char *cor = malloc(sizeof(char) * my_strlen(name) + 5);
    int i, j;

    for (j = my_strlen(name) - 1; j != 0 && name[j - 1] != '/'; j--);
    for (i = 0; name[j] != '.'; i++, j++)
        cor[i] = name[j];
    cor[i++] = '.';
    cor[i] = 'c';
    cor[i + 1] = 'o';
    cor[i + 2] = 'r';
    cor[i + 3] = 0;
    fclose(fopen(cor, "w"));
    return (cor);
}

int asming(char *name)
{
    int fd = can_open(name);
    char **tab = NULL;
    char *nam_cor;
    header_t *header;

    if (fd == -1)
        return (84);
    tab = get_all_file(fd);
    header = set_header(tab);
    nam_cor = naming_cor(name);
    fd = display_header(header, nam_cor);
    not_header(tab, fd);
    return (0);
}