/*
** EPITECH PROJECT, 2018
** putnbrbase
** File description:
** printf
*/

void my_putchar(char c);

int my_strlen(char const *str);

int my_putnbr_base(int nb, char *base)
{
    int idx = 0;

    idx = nb % my_strlen(base);
    nb = nb / my_strlen(base);
    if (nb > 0)
        my_putnbr_base(nb, base);
    my_putchar(base[idx]);
    return (nb);
}