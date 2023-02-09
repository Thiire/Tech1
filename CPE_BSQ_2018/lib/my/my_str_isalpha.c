/*
** EPITECH PROJECT, 2018
** my_str_isalpha.c
** File description:
** my_str_isalpha.c
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0' ; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
        } else
            return (0);
    }
    return (1);
}
