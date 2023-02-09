/*
** EPITECH PROJECT, 2018
** lib.h
** File description:
** lib.h
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <fcntl.h>
#include <dirent.h>

# ifndef LIB_H_
    # define LIB_H_
    # define READ_SIZE (1)

void my_putchar(char, int);
void my_intout(int, int);
int my_getnbr(char const *);
void my_stdout(char *, int);
int str_compare(char *, char *);
char **my_double_malloc(int, int);
char *my_str_concat(char *, char *);
int my_strlen(char *);
char **tab_filler(char *);
int my_fullcompare(char *, char *);
char **my_str_tab(char *);
char *my_cpy(char *);
int print_tetrimino(char *);
void tetriminos(void);
int is_alpha(char *);
int my_empty(char *);
# endif
