/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** task05
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}