/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** n4s
*/

#ifndef N4S_H_
    #define N4S_H_
    #define READ_SIZE 1

    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

    char *get_next_line(int);

    int str_compare(char *, char *);

    int my_er(char *, int);

    int my_parsing(char *, char *);

    void mover(int *, char *, int, int);

    int min(int, int);

    int my_strlen(char *);

#endif /* !N4S_H_ */
