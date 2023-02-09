/*
** EPITECH PROJECT, 2018
** user.c
** File description:
** gérer user
*/

#include "../includes/corewar.h"

int word_counter(char *str, char delimiteur)
{
    int index = 0;
    int compt2 = 0;

    while (str[index] != '\0' && str[index] != '\n') {
        while (str[index] == delimiteur || str[index] == '\t') {
            index += 1;
            if (str[index] == '\n' || str[index] == '\0')
                return (compt2);
        }
        compt2 += 1;
        while (str[index] != delimiteur && str[index] != '\t') {
            index += 1;
            if (str[index] == '\n' || str[index] == '\0')
                return (compt2);
        }
    }
    return (compt2);
}

int letter(char *str, char delimiteur, int index)
{
    int compt = 0;

    while ((str[index] != delimiteur && str[index] != '\t') \
    && str[index] != '\n' && str[index] != '\0') {
        compt += 1;
        index += 1;
    }
    return (compt);
}

char *useful(char *str, char delimiteur, int *index)
{
    char *word = malloc(sizeof(char) * letter(str, delimiteur, *index) + 1);
    int compt = 0;

    while ((str[*index] != delimiteur && str[*index] != '\t') \
    && str[*index] != '\n' && str[*index] != '\0') {
        word[compt] = str[*index];
        compt += 1;
        *index += 1;
    }
    word[compt] = '\0';
    return (word);
}

char **str_to_wordtab(char *str, char delimiteur)
{
    int index = 0;
    char **tab = malloc(sizeof(char *) * (word_counter(str, delimiteur) + 1));
    int word = 0;

    tab[word_counter(str, delimiteur)] = NULL;
    while (str[index] != '\0' && str[index] != '\n') {
        while (str[index] == delimiteur || str[index] == '\t') {
            index++;
            if (str[index] == '\0' || str[index] == '\n')
                return (tab);
        }
        tab[word] = useful(str, delimiteur, &index);
        word += 1;
    }
    return (tab);
}