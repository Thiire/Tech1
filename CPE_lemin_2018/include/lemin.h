/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** lemin.h
*/

#ifndef LEMIN_H
#define LEMIN_H

typedef struct coord_s
{
    char *room;
    char **connection;
    int error;
    int x;
    int y;
    int type;
} coord_t;

typedef struct link_s
{
    coord_t *in;
    struct link_s *next;
    struct link_s *prev;
    struct link_s *child;
    struct link_s *dad;
} link_t;

typedef struct info_s
{
    int ants;
    int error;
    char **tunnel;
    link_t *link;
    coord_t *start;
    coord_t *end;
    coord_t **points;
} info_t;

typedef struct path_s
{
    char **way;
    int result;
} path_t;

#endif
