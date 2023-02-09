/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#ifndef GENERATOR_H_
    #define GENERATOR_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <time.h>
    #include <math.h>

int str_compare(char *, char *);
int my_er(char *, int);
int is_strnum(char *);
int my_getnbr(char const *);
char **my_double_malloc(int, int);
int my_strlen(char *);
int perfect(char **, int, int);
int imperfect(char **, char *);
int write_map(char **);
int way1(char **, int, int, int);
int way2(char **, int, int, int);
int way3(char **, int, int, int);
int way4(char **, int, int, int);
void var1(int, char **, int, int);

#endif /* !GENERATOR_H_ */
