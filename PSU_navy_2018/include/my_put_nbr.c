/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** task03
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return (0);
}