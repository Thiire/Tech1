/*
** EPITECH PROJECT, 2018
** my_strcapitalize.c
** File description:
** my_strcapitalize.c
*/

char    *my_strcapitalize(char *str)
{
    int i = 1;

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    for (i = 1 ; str[i] != '\0' ; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if ((str[i-1] >= '0' && str[i-1] <= '9') || (str[i-1] >= 'a' &&
            str[i-1] <= 'z') || (str[i-1] >= 'A' && str[i-1] <= 'Z')) {
            }
            else
                str[i] = str[i] - 32;
        }
        if (str[i] >= 'A' && str[i] <= 'Z' && str[i] != '\0') {
            if ((str[i-1] >= '0' && str[i-1] <= '9') || (str[i-1] >= 'a' &&
            str[i-1] <= 'z') || (str[i-1] >= 'A' && str[i-1] <= 'Z'))
                str[i] = str[i] + 32;
        }
    }
    return (str);
}
