/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}