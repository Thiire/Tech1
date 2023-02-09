/*
** EPITECH PROJECT, 2018
** subject.h
** File description:
** subject.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

typedef struct flag_t
{
    int l;
    int R;
    int d;
    int r;
    int t;
} flag_t;

void my_printf(char *, ...);

static char **name;
static flag_t flg;
static int position;

#endif