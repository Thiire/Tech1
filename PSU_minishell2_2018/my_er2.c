/*
** EPITECH PROJECT, 2019
** my_er2.c
** File description:
** my_er2.c
*/

#include "mysh.h"

int move_concat(main_t *main, int i, char **result)
{
    int nb = i + 1;
    int test = 0;

    if (str_compare(main->all_arg[i], ";")) {
        create_node(adapt_node(main->all_arg[i], NULL, 0, 0), &main->node, 1);
        create_node(adapt_node(NULL, main->all_arg, i, -1), &main->node, 0);
        for (int n = 0; main->all_arg[i + n] != NULL; n++)
            main->all_arg[i + n] = NULL;
        return (0);
    }
    for (; main->all_arg[nb] != NULL; nb++) {
        for (int j = 0; j < 6; j++)
            test += str_compare(main->all_arg[nb], result[j]);
        if (test >= 1)
            break;
    }
    create_node(adapt_node(main->all_arg[i], NULL, 0, 0), &main->node, 1);
    if (test >= 1) {
        create_node(adapt_node(NULL, main->all_arg, i, nb), &main->node, 0);
        for (int n = 0; main->all_arg[nb + n] != NULL; n++, i++) {
            main->all_arg[i] = main->all_arg[nb + n];
        }
        main->all_arg[i] = NULL;
    }
    if (test == 0 && main->all_arg[nb] == NULL)
        create_node(adapt_node(NULL, main->all_arg, i, -1), &main->node, 0);
        for (int n = 0; main->all_arg[i + n] != NULL; n++)
            main->all_arg[i + n] = NULL;
    return (0);
}

int move_concat_bis(main_t *main, int i, char **result)
{
    int nb = i;
    int test = 0;
    int y = 0;

    for (; main->all_arg[nb] != NULL; nb++) {
        for (int j = 0; j < 6; j++)
            test = (str_compare(main->all_arg[nb], result[j])) ? nb : test;
        if (test >= 1)
            break;
    }
    create_node(adapt_node(main->all_arg[nb], NULL, 0, 0), &main->node, 1);
    if (test >= 1) {
        create_node(adapt_node(NULL, main->all_arg, -1, nb), &main->node, 0);
        for (int n = 1; main->all_arg[nb + n] != NULL; n++, i++, y++) {
            main->all_arg[y] = main->all_arg[nb + n];
        }
        main->all_arg[y] = NULL;
    }
    if (test == 0 && main->all_arg[nb] == NULL) {
        create_node(adapt_node(NULL, main->all_arg, 0, -1), &main->node, 0);
        for (int n = 0; main->all_arg[n] != NULL; n++)
            main->all_arg[n] = NULL;
    }
    return (0);
}

char **result_maker(void)
{
    char **result = my_double_malloc(7, 3);

    result[0][0] = ';';
    result[1][0] = '>';
    result[1][1] = '>';
    result[2][0] = '>';
    result[3][0] = '<';
    result[3][1] = '<';
    result[4][0] = '<';
    result[5][0] = '|';
    result[6][0] = '\0';
    return (result);
}

int parser(main_t *main, int nb, char **res)
{
    int length = 0;

    for (int i = 0; main->all_arg[i] != NULL; i++)
        if (str_compare(main->all_arg[i], res[0])) {
            move_concat(main, i, res);
            break;
        }
    for (; main->all_arg[length] != NULL; length++);
    for (int i = length - 1; i >= 0; i--)
        if (str_compare(main->all_arg[i], res[1])
        || str_compare(main->all_arg[i], res[2]))
            move_concat(main, i, res);
    for (; main->all_arg[length] != NULL; length++);
    for (int i = length - 1; i >= 0; i--)
        if (str_compare(main->all_arg[i], res[5]))
            move_concat(main, i, res);
    for (int i = 0; main->all_arg[i] != NULL; i++)
        if (str_compare(main->all_arg[i], res[3])
        || str_compare(main->all_arg[i], res[4])) {
            move_concat_bis(main, i - 1, res);
            i--;
        }
    return (0);
}

int arg_fail(main_t *main, int nb, char **result)
{
    for (int i = 0, check1 = 0, check2 = 0; main->all_arg[i] != NULL; i++) {
        check1 += (str_compare(main->all_arg[i], result[1])
        || str_compare(main->all_arg[i], result[2])) ? 1 : 0;
        check2 += (str_compare(main->all_arg[i], result[3])
        || str_compare(main->all_arg[i], result[4])) ? 1 : 0;
        if (check1 > 1) {
            my_er("Ambiguous output redirect.\n", 2);
            return (1);
        } else if (check2 > 1) {
            my_er("Ambiguous input redirect.\n", 2);
            return (1);
        }
        check1 = (str_compare(main->all_arg[i], ";")) ? 0 : check1;
        check2 = (str_compare(main->all_arg[i], ";")) ? 0 : check2;
    }
    return (parser(main, 0, result));
}
