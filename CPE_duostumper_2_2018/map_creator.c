/*
** EPITECH PROJECT, 2019
** map_creator.c
** File description:
** map_creator.c
*/

#include "boogle.h"

int valid_map(info_t *info, int j, int i, char *str)
{
    int result = my_strlen(str);

    if (result == info->nb)
        return (1);
    if (info->map[j + 1][i] == str[info->nb] && info->way != 1) {
        info->nb += 1;
        info->way = 3;
        return (valid_map(info, j + 1, i, str));
    }
    if (info->map[j - 1][i] == str[info->nb] && info->way != 3) {
        info->nb += 1;
        info->way = 1;
        return (valid_map(info, j - 1, i, str));
    }
    if (info->map[j][i + 2] == str[info->nb] && info->way != 2) {
        info->nb += 1;
        info->way = 4;
        return (valid_map(info, j, i + 2, str));
    }
    if (info->map[j][i - 2] == str[info->nb] && info->way != 4) {
        info->nb += 1;
        info->way = 2;
        return (valid_map(info, j, i - 2, str));
    }
    return (0);
}

int test_map(info_t *info, char *str)
{
    int check = 0;

    for (int j = 1; j <= info->size && check == 0; j++) {
        for (int i = 2; i <= info->size * 2 && check == 0; i += 2) {
            info->nb = 1;
            check += (str[0] == info->map[j][i] && valid_map(info, j, i, str)) ? 1 : 0;
        }
    }
    if (check >= 1)
        return (check_input(info, 3));
    if (info->word == NULL)
        my_er("> ", 1);
    printf("The word \"%s\" is not in the grid.\n", str);
    return (check_input(info, 1));
}

int fill_input(info_t *info, char *str)
{
    int check = 0;

    if (my_strlen(str) > info->size) {
        if (info->word == NULL)
            my_er("> ", 1);
        printf("The word \"%s\" is not in the grid.\n", str);
        if (info->word != NULL || str == NULL)
            return (0);
        return (check_input(info, 1));
    }
    for (int i = 0; str[i] != '\0'; i++)
        check += (str[i] < 'a' || str[i] > 'z') ? 1 : 0;
    if (check >= 1) {
        if (info->word == NULL)
            my_er("> ", 1);
        printf("The word \"%s\" is not in the grid.\n", str);
        if (info->word != NULL || str == NULL)
            return (0);
        return (check_input(info, 1));
    }
    return (test_map(info, str));
}

int end_return(info_t *info, int nb)
{
    if (nb != 3)
        return (0);
    printf("win\n");
    return (0);
}

int check_input(info_t *info, int nb)
{
    char *str = NULL;
    
    if (nb == 0 && info->word == NULL) {
        for (int i = 0; info->map[i] != NULL; i++)
            printf("%s\n", info->map[i]);
        check_input(info, 1);
    }
    else if ((nb == 1 && isatty(0) == 0) || (nb == 0 && info->word != NULL)) {
        if (isatty(0) == 0)
            str = get_next_line(0);
        else
            str = info->word;
    } else if (nb != 3) {
        my_er("> ", 1);
        str = get_next_line(0);
    }
    if (str != NULL && nb != 3)
        return (fill_input(info, str));
    return (end_return(info, nb));
}

int map_filler(info_t *info)
{
    info->map = my_double_malloc(info->size + 3, info->size * 2 + 4);
    int j = 1;
    int n = 0;

    for (int i = 0; i < info->size * 2 + 3; i++)
        info->map[0][i] = '+';
    for (; j < info->size + 1; j++) {
        info->map[j][0] = '|';
        for (int i = 1; i < info->size * 2; i += 2) {
            info->map[j][i] = ' ';
            info->map[j][i + 1] = info->list[n];
            n++;
        }
        info->map[j][info->size * 2 + 1] = ' ';
        info->map[j][info->size * 2 + 2] = '|';
    }
    for (int i = 0; i < info->size * 2 + 3; i++)
        info->map[info->size + 1][i] = '+';
    info->map[info->size + 2] = NULL;
    return (check_input(info, 0));
}
