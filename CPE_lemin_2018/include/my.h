/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/wait.h>
#include "get_next_line.h"
#include "my_printf.h"
#include "linked_list.h"
#include "lemin.h"

void free_struct(info_t *, path_t **);
int str_tab(char **);
int str_compare(char *, char *);
int tab_size(char **);
int my_strcmp(char *, char *);
char *my_strdup(char *);
char *my_strcat(char *, char *);
char **my_str_to_word_array(char *, char);
int my_strncmp(char *, char *, int);
int parser(info_t *);
int check_map(info_t *, int, int);
int print_info(info_t *, int, int);
int check_name(coord_t **, int);
void init_connection(info_t *);
void stock_in_cords(info_t *, char *, int *);
int check_start(info_t *, int, int);
void my_graph(info_t *, path_t **);
void create_next(link_t *, link_t **);
void create_child(link_t *, link_t **);
link_t *create_link(coord_t *);
void my_auto_graph(link_t *, info_t *);
void path_filler(path_t **, link_t *, info_t *);
path_t *create_path(void);
char **my_double_malloc(int, int);
void ants_pushing(path_t *, int);
void print_one(path_t *);

#endif /* MY_H */
