/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "../includes/corewar.h"

int not_asm(char **av)
{
    for (int i = 1; av[i]; i++) {
        if (av[i][my_strlen(av[i]) - 1] != 's' ||
        av[i][my_strlen(av[i]) - 2] != '.')
            return (i);
    }
    return (0);
}

int not_good_arg(char *argument)
{
    my_put_err("Error on arguments\n");
    my_put_err(argument);
    my_put_err(" does not finish by .s.\n"
    "Retry with -h for more informations\n");
    return (84);
}

int error_on_arg(int ac)
{
    my_put_err("Error on arguments.\n");
    my_putnbr_base_error(ac - 1, "0123456789");
    my_put_err(" argument given when 1 is"
    " required.\nRetry with -h for more information\n");
    return (84);
}

int help(char *binary)
{
    my_putstr("USAGE\n\t");
    my_putstr(binary);
    my_putstr(" file_name[.s]\n\nDESCRIPTION\n\tfile_name\tfile in assembly"
    " language to be converted into file_name.cor, an\n\t\t\texecutable in "
    " the Virtual Machine.\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (error_on_arg(ac));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        return (help(av[0]));
    for (int i = 1; av[i]; i++) {
        if (av[i][my_strlen(av[i]) - 1] != 's' ||
        av[i][my_strlen(av[i]) - 2] != '.')
            return (not_good_arg(av[i]));
    }
    return (asming(av[1]));
}