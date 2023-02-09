/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** my_strstr.c
*/

#include <unistd.h>

int str_length1(char *str)
{
    int i;

    for ( i = 0 ; str[i] != '\0' ; i++ ) {
    }
    return (i);
}

int str_length2(char const *to_find)
{
    int k;

    for ( k = 0 ; to_find[k] != '\0' ; k++ ) {
    }
    return (k);
}

char    *my_strstr(char *str, char const *to_find)
{
    int n = 0;
    int j = 0;
    int m = 0;
    int i = str_length1(str);
    int k = str_length2(to_find);

    j = k;
    for (m = 0 ; m < i ; m++) {
        for (j = k ; to_find[n] == str[n + m] && j != 0 ; j--) {
            n++;
        }
        n = 0;
        if ( j == 0 )
            return (str + m);
    }
    return (NULL);
}
