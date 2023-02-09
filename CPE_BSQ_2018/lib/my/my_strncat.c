/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** cat
*/

int my_strlen(char *);

char *my_strncat(char *dest, char const *src, int nb)
{
    int size = my_strlen(dest);
    int j;

    for (j = 0 ; j < nb && src[j] != '\0' ; j++)
        dest[size + j] = src[j];
    dest[size + j] = '\0';
    return (dest);
}
