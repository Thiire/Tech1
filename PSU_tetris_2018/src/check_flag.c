/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** check_flag.c
*/

#include "tetris.h"

char **list2(void)
{
    char **tmp = my_double_malloc(13, 15);

    tmp[0] = my_cpy("--level=");
    tmp[1] = my_cpy("--key-left=");
    tmp[2] = my_cpy("--key-right=");
    tmp[3] = my_cpy("--key-turn=");
    tmp[4] = my_cpy("--key-drop=");
    tmp[5] = my_cpy("--key-quit=");
    tmp[6] = my_cpy("--key-pause=");
    tmp[7] = my_cpy("--map-size=");
    tmp[8] = my_cpy("-w");
    tmp[9] = my_cpy("-D");
    tmp[10] = my_cpy("--without-next");
    tmp[11] = my_cpy("--debug");
    tmp[12] = NULL;
    return (tmp);
}

char **list1(void)
{
    char **tmp = my_double_malloc(8, 15);

    tmp[0] = my_cpy("-L");
    tmp[1] = my_cpy("-l");
    tmp[2] = my_cpy("-r");
    tmp[3] = my_cpy("-t");
    tmp[4] = my_cpy("-d");
    tmp[5] = my_cpy("-q");
    tmp[6] = my_cpy("-p");
    tmp[7] = NULL;
    return (tmp);
}

int cmp2(char **tab, char **tmp2, int i, input_t *key)
{
    int j = 0;

    if (i < 8 && !my_fullcompare(tab[0], tmp2[i]))
        return (0);
    else if (i >= 8 && !str_compare(tmp2[i], tab[0]))
        return (0);
    if (i == 0 && my_strlen(tab[0]) >= 9) {
        tab[0] += 8;
        key->level = my_getnbr(tab[0]);
    }
    if (i == 1 && my_strlen(tab[0]) == 12) {
        key->left = my_cpy(&tab[0][11]);
        key->left[1] = '\0';
    }
    return (cmp2_2(tab, tmp2, i, key));
}

int cmp1(char **tab, char **tmp1, int i, input_t *key)
{
    if (!str_compare(tmp1[i], tab[0]))
        return (0);
    if (i == 0 && tab[1] != NULL && is_alpha(tab[1])) {
        key->level = my_getnbr(tab[1]);
        return (2);
    }
    if (i == 1 && tab[1] != NULL && my_strlen(tab[1]) == 1) {
        key->left = my_cpy(tab[1]);
        return (2);
    }
    if (i == 2 && tab[1] != NULL && my_strlen(tab[1]) == 1) {
        key->right = my_cpy(tab[1]);
        return (2);
    }
    if (i == 3 && tab[1] != NULL && my_strlen(tab[1]) == 1) {
        key->turn = my_cpy(tab[1]);
        return (2);
    }
    return (cmp1_2(tab, tmp1, i, key));
}

void flag_check(char **tab, input_t *key)
{
    char **tmp1 = list1();
    char **tmp2 = list2();
    int check = 0;

    tab++;
    while (tab[0] != NULL) {
        check = 0;
        if (tab[0][0] == '-') {
            for (int i = 0; tmp1[i] != NULL &&
            !(check += cmp1(tab, tmp1, i, key)); i++);
            for (int i = 0; tmp2[i] != NULL &&
            !(check += cmp2(tab, tmp2, i, key)); i++);
        }
        if (check == 0)
            exit(84);
        else
            tab += check;
    }
}