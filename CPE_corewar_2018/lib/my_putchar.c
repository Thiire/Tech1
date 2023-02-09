/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** putchar
*/

# include <unistd.h>
# include <stdlib.h>

int my_putchar(char c)
{
    write (1, &c, 1);
    return (0);
}

void putchar_err(char c)
{
    write (2, &c, 1);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}