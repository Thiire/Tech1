/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "../include/get_next_line.h"

char *rt(char *st, int i)
{
    char *tmp = NULL;
    int j = 0;

    tmp = malloc(sizeof(char) * (READ_SIZE + 1));
    if (!tmp)
        return (tmp);
    for (; st[i] != '\0'; i++, j++)
        tmp[j] = st[i];
    free(st);
    tmp[j] = '\0';
    return (tmp);
}

char *my_strcot(char *dest, char *src)
{
    char *st = "\0";
    int i = 0;

    for (; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0'; j++, i++);
    st = malloc(sizeof(char) * i + 2);
    if (!st) {
        free(dest);
        return (st);
    }
    for (i = 0; dest[i] != '\0'; i++)
        st[i] = dest[i];
    for (int j = 0; src[j] != '\0'; j++, i++)
        st[i] = src[j];
    st[i] = '\0';
    free(dest);
    return (st);
}

char *init(void)
{
    char *buff = malloc(sizeof(char) * 10000);

    if (!buff) {
        free(buff);
        return (NULL);
    }
    for (int i = 0; i < 10000; i++)
        buff[i] = '\0';
    return (buff);
}

char *get_next_line(int fd)
{
    static char *tmp = "\0";
    char *st = malloc(sizeof(char) * READ_SIZE + 1);
    char *tmp2 = init();
    int j = 0;

    for (; tmp[j] != '\0'; j++)
        tmp2[j] = tmp[j];
    for (int check = 0; check != 1;) {
        st[read(fd, st, READ_SIZE)] = '\0';
        if (st[0] == 0)
            return (tmp2);
        for (int i = 0; st[i] != '\0' && !check; i++, j++) {
            tmp2[j] = st[i];
            check = st[i] == '\n' || st[i] == '\0';
            tmp = (st[i] == '\n' && st[i + 1] != '\0') ? rt(st, i + 1) : "\0";
        }
    }
    tmp2 = my_strcot(tmp2, tmp);
    tmp2[j - 1] = '\0';
    return (tmp2);
}
