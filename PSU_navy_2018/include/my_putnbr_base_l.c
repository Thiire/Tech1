/*
** EPITECH PROJECT, 2018
** putnbrbase long
** File description:
** printf
*/

void my_putchar(char c);

int my_strlen(char const *str);

long my_putnbr_base_l(long nb, char *base)
{
    long idx = 0;

    idx = nb % my_strlen(base);
    nb = nb / my_strlen(base);
    if (nb > 0)
        my_putnbr_base_l(nb, base);
    my_putchar(base[idx]);
    return (nb);
}