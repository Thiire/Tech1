/*
** EPITECH PROJECT, 2018
** PSU_bstetris_2018
** File description:
** check_tetrimino.c
*/

#include "tetris.h"

int length_test(char **tab, char **tmp)
{
    int check = 0;
    int length = 0;
    int i = 1;

    for (i = 1; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            check += (tab[i][j] != '*' && tab[i][j] != ' ') ? 1 : 0;
        if (check != 0)
            return (84);
        length = (my_empty(tab[i]) > length) ? my_empty(tab[i]) : length;
    }
    if (i - 1 != my_getnbr(tmp[1]) || length != my_getnbr(tmp[0]))
        return (84);
}

int displayer2(char **tab, char **tmp)
{
    if (length_test(tab, tmp) == 84)
        return (84);
    my_stdout(" Size ", 1);
    my_stdout(tmp[0], 1);
    my_stdout("*", 1);
    my_stdout(tmp[1], 1);
    my_stdout(" :  Color ", 1);
    my_stdout(tmp[2], 1);
    my_stdout(" :\n", 1);
    for (int i = 1; tab[i] != NULL; i++) {
        my_stdout(tab[i], 1);
        write(1, "\n", 1);
    }
    return (0);
}

int parser(char *stack)
{
    char **tab = tab_filler(stack);
    char **tmp = NULL;
    int i = 0;

    if (tab[0] == NULL)
        return (84);
    tmp = my_str_tab(tab[0]);
    for (; tmp[i] != NULL; i++)
        if (my_getnbr(tmp[i]) == 666)
            return (84);
    if (i != 3 || my_getnbr(tmp[2]) > 15 || my_getnbr(tmp[2]) <= 0)
        return (84);
    free(stack);
    return (displayer2(tab, tmp));
}

int displayer(char *name, char *stack)
{
    int n = 0;

    for (int i = 0; name[i] != '\0'; i++)
        n = (name[i] == '/') ? i : n;
    if (n != 0)
        for (int i = 0; i <= n; name++, i++);
    my_stdout("Tetriminos :  Name ", 1);
    for (int i = 0; name[i] != '.'; i++)
        write(1, &name[i], 1);
    my_stdout(" : ", 1);
    if (parser(stack) == 84)
        my_stdout("Error\n", 1);
    return (0);
}

int print_tetrimino(char *str)
{
    struct stat board;
    char *stack = NULL;
    FILE *file;

    if (!my_fullcompare(str, ".tetrimino"))
        return (84);
    str = my_str_concat("tetriminos/", str);
    stat(str, &board);
    stack = malloc(sizeof(char) * board.st_size + 1);
    file = fopen(str, "r");
    if (file == NULL)
        return (84);
    fread(stack, board.st_size, 1, file);
    stack[board.st_size] = '\0';
    fclose(file);
    return (displayer(str, stack));
}