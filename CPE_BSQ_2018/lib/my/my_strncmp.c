/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n <= 0)
        return (0);
    for (i = 0 ; (s1[i] == s2[i]) && (s1[i] != '\0') && (n != 0)
    && (s2[i] != '\0') ; i++) {
        n--;
    }
    return (s1[i] - s2[i]);
}
