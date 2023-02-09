/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** cat
*/

int my_strlen(char *);

char *my_strcat(char *dest, char const *src)
{
    int size = my_strlen(dest);
    int i;

    for (i = 0 ; src[i] != '\0' ; i++)
        dest[size + i] = src[i];
    dest[size + i] = '\0';

    return (dest);
}
