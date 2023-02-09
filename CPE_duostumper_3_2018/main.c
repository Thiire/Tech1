/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "stump3.h"

char change_str(int count, int state)
{
    if (state == 1) {
        while (check_num(count) != 1) {
            count += (count < 'a') ? 26 : 0;
            count -= (count > 'z') ? 26 : 0;
        }
    } else if (state == 2) {
        while (check_num(count) != 2) {
            count += (count < 'A') ? 26 : 0;
            count -= (count > 'Z') ? 26 : 0;
        }
    }
    return (count);
}

void file_writer(char *result)
{
    FILE *file;

    file = fopen("crypt", "w");
    if (file == NULL)
        return;
    fwrite(result, my_strlen(result), 1, file);
    fclose(file);
}

void cesar_code(char *str, char *result, int key)
{
    int count = 0;
    int i = 0;

    result = malloc(sizeof(char) * my_strlen(str) + 1);
    for (i = 0; str[i] != 0; i++) {
        count = str[i] + key;
        if (check_num(str[i]) == 1) {
            result[i] = change_str(count, 1);
        } else if (check_num(str[i]) == 2) {
            result[i] = change_str(count, 2);
        } else
            result[i] = str[i];
    }
    result[i] = '\0';
    file_writer(result);
}

int file_opener(char *av, char *result, int key)
{
    char *tmp = malloc(sizeof(char) * 100000);
    FILE *file;

    file = fopen(av, "r");
    if (file == NULL)
        return (1);
    for (int i = 0; i < 100000; i++)
        tmp[i] = '\0';
    fread(tmp, 100000, 1, file);
    fclose(file);
    cesar_code(tmp, result, key);
    return (0);
}

int main(int ac, char **av)
{
    char *result;

    if (ac != 4)
        return (84);
    if (av[3][0] != '-' && (av[3][0] < '0' || av[3][0] > '9'))
        return (84);
    for (int i = 1; av[3][i] != '\0'; i++)
        if (av[3][i] < '0' || av[3][i] > '9')
            return (84);
    if (str_compare(av[1], "-f")) {
        if (file_opener(av[2], result, my_getnbr(av[3])))
            return (84);
    } else if (str_compare(av[1], "-s")) {
        cesar_code(av[2], result, my_getnbr(av[3]));
    } else
        return (84);
    return (0);
}
