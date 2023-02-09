/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** my_strncpy.c
*/

char    *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (int m = n ; m != 0 && src[i] != '\0' ; m--) {
        dest[i] = src[i];
        i++;
    }
    if ( n > i )
        dest[i + 1] = '\0';
    return (dest);
}
