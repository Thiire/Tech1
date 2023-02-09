/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** my_isneg.c
*/

void    my_putchar(char);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else if (n >= 0)
        my_putchar('P');
    my_putchar('\n');
    return (0);
}