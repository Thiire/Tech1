/*
** EPITECH PROJECT, 2018
** stump3.h
** File description:
** stump3.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef _STUMP_H_
# define _STUMP_H_

int my_getnbr(char *);
char *my_str_concat(char *, char *);
char **my_double_malloc(int, int);
int str_compare(char *, char *);
void my_er(char *, int);
int check_num(char);
int my_strlen(char *);

# endif
