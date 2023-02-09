/*
** EPITECH PROJECT, 2018
** mysh.h
** File description:
** mysh.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

# ifndef MYSH_H_
    # define MYSH_H_
    # define READ_SIZE (1)

typedef struct env_s
{
    char *stock;
    struct env_s *prev;
    struct env_s *next;
} env_t;

typedef struct node_s
{
    char **arg;
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef struct main_s main_t;

typedef struct flag_s
{
    char *name;
    void (*fnc_call)(main_t *);
} flag_t;

typedef struct main_s
{
    char **all_arg;
    node_t *node;
    env_t *env;
} main_t;

main_t *init_struct(int, char **, char **);

char **my_double_malloc(int, int);

char *my_str_concat(char *, char *);

int my_strlen(char *);

void cd_fnc(main_t *);

void exit_fnc(main_t *);

void setenv_fnc(main_t *);

void env_fnc(main_t *);

void unsetenv_fnc(main_t *);

void my_er(char *, int);

char *get_next_line(int);

char **my_str_tab(char *);

int str_compare(char *, char *);

int parser(main_t *, int, char **);

char **result_maker(void);

void create_node(char **, node_t **, int);

node_t *free_mem(char **, char **);

char **adapt_node(char *, char **, int, int);

int arg_fail(main_t *, int, char **);

# endif