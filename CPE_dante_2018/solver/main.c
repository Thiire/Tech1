/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "solver.h"

int dash_h(void)
{
    my_er("USAGE\n  ./solver maze.txt\n\nDESCRPTION\n  maze.txt   file represe"
    "nting the maze map, containing 'X' for walls and '*' for "
    "the space.\n", 1);
    return (0);
}

int main(int ac, char **av)
{
    int file = open(av[1], O_RDONLY);
    struct stat board;
    char *buff = NULL;

    stat(av[1], &board);
    buff = malloc(sizeof(char) * (board.st_size + 1));
    read(file, buff, board.st_size);
    buff[board.st_size] = '\0';
    if (ac != 2)
        return (my_er("Error: Bad arguments.\n", 2));
    if (str_compare(av[1], "-h"))
        return (dash_h());
    if (file == -1)
        return (my_er("Error: Bad files.\n", 2));
    else
        solve_maze(buff);
    return (0);
}