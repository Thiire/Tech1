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

typedef struct listed_t
{
    char *env;
    struct listed_t *prev;
    struct listed_t *next;
} listed_t;

typedef struct typer_t
{
    char *name;
    void (*fnc_call)(char *, char **, listed_t *);
} typer_t;

int my_er(char *);

int my_no_er(char *);

char *env_check(char **, listed_t *);

int my_arg_check(char *, listed_t *);

char *my_str_concat(char *, char *);

void cd_fnc(char *, char **, listed_t *);

void exit_fnc(char *, char **, listed_t *);

void setenv_fnc(char *, char **, listed_t *);

void env_fnc(char *, char **, listed_t *);

void unsetenv_fnc(char *, char **, listed_t *);

char *get_next_line(int);

int my_getnbr(char const *);

void my_printf(char *, ...);

int str_lgh(char *);

void my_create_env(char *, listed_t **);

# endif
