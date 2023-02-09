/*
** EPITECH PROJECT, 2018
** getnextline.h
** File description:
** header for getnextline
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef GET_NEXT_LINE
#   define GET_NEXT_LINE
    int my_strlen(char *str);
    char *my_strcat(char *dest, char *src);

    #ifndef READ_SIZE
    #   define READ_SIZE (1)
    #endif /* READ_SIZE */
#endif /* GET_NEXT_LINE */