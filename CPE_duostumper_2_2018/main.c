/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "boogle.h"

int check_info2(info_t *info, char **av, int ac)
{
    int check = 0;

    for (int i = 0;info->list != NULL && info->list[i] != '\0'; i++)
        check += (info->list[i] < 'a' || info->list[i] > 'z') ? 1 : 0;
    for (int i = 0;info->word != NULL && info->word[i] != '\0'; i++)
        check += (info->word[i] < 'a' || info->word[i] > 'z') ? 1 : 0;
    if (info->list != NULL && my_strlen(info->list) != info->size * 4)
        return (84);
    if (check >= 1)
        return (84);
    return (map_filler(info));
}

int check_info(info_t *info, char **av, int ac)
{
    for (int i = 1; i < ac; i += 2) {
       	if (str_compare(av[i], "-s"))
    	    info->size = my_getnbr(av[i + 1]);
        if (str_compare(av[i], "-g") && av[i + 1] != NULL)
            info->list = str_cpy(av[i + 1]);
        else if (str_compare(av[i], "-g"))
            return (84);
        if (str_compare(av[i], "-w") && av[i + 1] != NULL)
            info->word = str_cpy(av[i + 1]);
        else if (str_compare(av[i], "-w"))
            return (84);
        if (!str_compare(av[i], "-w") && !str_compare(av[i], "-s") && !str_compare(av[i], "-g"))
            return (84);
    }
    if (info->size == 0)
        return (84);
    return (check_info2(info, av, ac));
}

int init_struct(info_t *info)
{
    info->way = 0;
    info->nb = 0;
    info->list = '\0';
    info->size = 4;
    info->word = '\0';
    return (0);
}

int main(int ac, char **av)
{
    info_t *info = malloc(sizeof(info_t));

    init_struct(info);
    if (check_info(info, av, ac) == 84) {
        my_er("Error: bad arguments\n", 2);
        return (84);
    }
    return (0);
}
