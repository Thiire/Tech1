/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0' ; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
        }
        else
            return (0);
    }
    return (1);
}
