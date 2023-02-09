/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** debug_mode2
*/

#include "tetris.h"

int print_number(void)
{
    DIR *dirrep;
    struct dirent *drep;
    int check = 0;

    dirrep = opendir("./tetriminos");
    if (dirrep == NULL)
        return (84);
    while ((drep = readdir(dirrep)) != NULL)
        if (my_fullcompare(drep->d_name, ".tetrimino"))
            check++;
    my_stdout("Tetriminos :  ", 1);
    my_intout(check, 1);
    my_stdout("\n", 1);
    if (check == 0)
        return (84);
    return (check);
}

int swap(char **piece, int id)
{
    char *tmp = piece[id];

    piece[id] = piece[id + 1];
    piece[id + 1] = tmp;
    return (1);
}

int alpha_second(char **piece, int size, int i)
{
    for (int j = 0; piece[i][j] != '\0'; j++) {
        if ((piece[i + 1][j] == '\0' && piece[i][j] != '\0') ||
        piece[i][j] > piece[i + 1][j]) {
            return (swap(piece, i));
        } else if (piece[i][j] < piece[i + 1][j])
            break;
    }
    return (0);
}

void alpha_order(char **piece, int size)
{
    int check = 0;

    for (int i = 0; i < size - 1; i++) {
        check += alpha_second(piece, size, i);
    }
    if (check >= 1)
        alpha_order(piece, size);
}

void tetriminos(void)
{
    DIR *dirrep;
    struct dirent *drep;
    char **piece = NULL;
    int i = 0;
    int size = 0;


    if ((size = print_number()) == 84)
        return;
    dirrep = opendir("./tetriminos");
    piece = my_double_malloc(size + 1, 50);
    for (; (drep = readdir(dirrep)) != NULL; ) {
        if (drep->d_name[0] != '.') {
            piece[i] = drep->d_name;
            i++;
        }
    }
    piece[i] = NULL;
    alpha_order(piece, size);
    for (int j = 0; piece[j] != NULL; j++)
        print_tetrimino(piece[j]);
}