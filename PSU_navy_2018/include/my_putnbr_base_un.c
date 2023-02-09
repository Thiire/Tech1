/*
** EPITECH PROJECT, 2018
** putnbr_base
** File description:
** printf
*/

void my_putchar(char c);

int my_strlen(char const *str);

unsigned int my_putnbr_base_un(unsigned int nb, char *base)
{
    unsigned int idx = 0;

    idx = nb % my_strlen(base);
    nb = nb / my_strlen(base);
    if (nb > 0)
        my_putnbr_base_un(nb, base);
    my_putchar(base[idx]);
    return (nb);
}