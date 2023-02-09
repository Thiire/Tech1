/*
** EPITECH PROJECT, 2018
** showstr.c
** File description:
** showstr.c
*/

#include <unistd.h>
#include <stdlib.h>

int my_putnbr_base(int, char const *);

int c_putstr(char const *);

char *trade(int, char const *);

int my_strlen(char const *);

int col(char *result, char *res, int y)
{
    for (int i = 0; res[i] != '\0'; i++) {
        result[y] = res[i];
        y++;
    }
    return (y);
}

int my_display(int str, char *result, char *base, int y)
{
    char *res = malloc(sizeof(char) * 4);

    result[y] = '\\';
    y++;
    if (str < 32) {
        result[y] = '0';
        y++;
    }
    if (str < 8) {
        result[y] = '0';
        y++;
    }
    res = trade(str, base);
    y = col(result, res, y);
    return (0);
}

char *my_showstr(char const *str)
{
    char base[9] = "01234567";
    char *result = malloc(sizeof(char) * my_strlen(str) * 2);
    int i = 0;
    int y = 0;

    for (i = 0; str[i] != '\0' ; i++) {
        if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127) {
            y += my_display(str[i], result, base, y);
        }
        else {
            result[y] = str[i];
        }
        y++;
    }
    return (result);
}

int showstr(char const *str, int *nombre)
{
    char *result;

    result = my_showstr(str);
    if (nombre[0] > 0) {
        for (int i = 0; i < nombre[0] - my_strlen(result); i++) {
            write(1, " ", 1);
        }
        c_putstr(result);
        return (0);
    } else if (nombre[0] < 0) {
        c_putstr(result);
        for (int i = 0; i > nombre[0] + my_strlen(result); i--) {
            write(1, " ", 1);
        }
        return (0);
    }
    c_putstr(result);
    return (0);
}
