/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver
*/

#ifndef SOLVER_H_
    #define SOLVER_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    typedef struct tab_s
    {
        int hcost;
        int gcost;
        int fcost;
        int status;
    } tab_t;

int check_cost(tab_t ***, int, int, char **);
int str_compare(char *, char *);
int my_er(char *, int);
char **my_double_malloc(int, int);
int my_strlen(char *);
char **map_filling(char *, char **);
int solve_maze(char *);
int find_width(char *, int);
int find_height(char *);
int solving(tab_t ***, char **, int, int);
tab_t ***create_tab(char *);
int nb_path(tab_t ***, char **, int, int);
void print_solved(tab_t ***, char **);
void print_path(tab_t ***, char **, int, int);
int number_path(tab_t ***, int, int, int);

#endif /* !SOLVER_H_ */
