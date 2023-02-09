/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** gnl
*/

#ifndef READ_SIZE

#define READ_SIZE (1)

#endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *get_next_line(int);
