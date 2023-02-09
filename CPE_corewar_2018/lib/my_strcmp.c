/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** Afficher une fonction
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0')
            return (0);
    }
    if (s1[i] == '\0')
        return (0);
    return (1);
}
