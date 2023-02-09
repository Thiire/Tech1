/*
** EPITECH PROJECT, 2018
** issalpha.c
** File description:
** issalpha.c
*/

int issalpha(char str)
{
    if (str >= 'a' && str <= 'z');
    else if (str >= 'A' && str <= 'Z');
    else
        return (0);
    return (1);
}
