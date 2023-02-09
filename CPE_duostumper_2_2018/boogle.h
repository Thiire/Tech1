/*
** EPITECH PROJECT, 2018
** boogle.h
** File description:
** boogle.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

# ifndef BOOGLE_H_
    # define BOOGLE_H_
    # define READ_SIZE (1)

typedef struct info_s
{
    int nb;
    int way;
    int size;
    char *list;
    char *word;
    char **map;
} info_t;

char *get_next_line(int);

int valid_map(info_t *, int, int, char *);

int check_input(info_t *, int);

int map_filler(info_t *);

int my_strlen(char *);

char *str_cpy(char *);

int str_compare(char *, char *);

char *my_str_concat(char *, char *);

char **my_double_malloc(int, int);

void my_er(char *, int);

int my_getnbr(char *);

# endif
