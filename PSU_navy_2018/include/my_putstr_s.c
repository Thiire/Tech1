/*
** EPITECH PROJECT, 2018
** putstr
** File description:
** printf
*/

void my_putchar(char c);

int my_putnbr_base(int nb, char *base);

int my_putstr_s(unsigned char const *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 8 && s[i] <= 31) || s[i] == 177) {
            my_putchar('\\');
            my_putchar('0');
            my_putnbr_base(s[i], "01234567");
        } else if (s[i] < 8) {
            my_putchar('\\');
            my_putchar('0');
            my_putchar('0');
            my_putnbr_base(s[i], "01234567");
        } else
            my_putchar(s[i]);
    }
    return (0);
}
