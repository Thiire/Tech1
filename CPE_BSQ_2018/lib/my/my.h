/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_

void    my_putchar(char);

void    my_sort_int_array(int *, int);

void    my_swap(int *, int *);

void    swap_handler(int *, int *);

int my_compute_power_rec(int, int);

int my_compute_square_root(int);

int my_find_prime_sup(int);

int my_getnbr_base(char const *, char const *);

int my_getnbr(char const *);

int my_isneg(int);

int my_is_prime(int);

int my_print_params(char **);

int my_putnbr_base(int, char const *);

int my_put_nbr(int);

int my_putstr(char const *);

int my_showmem();

int my_showstr(char const *);

int my_strcmp(char const *, char const *);

int my_str_isalpha(char const *);

int my_str_islower(char const *);

int my_str_isnum(char const *);

int my_str_isprintable(char const *);

int my_str_isupper(char const *);

int my_strncmp(char const *, char const *, int);

int my_show_word_array(char *const *);

int my_ignore(char const *, int);

int convert(int, char const *);

int my_strlen(char const *);

int to_findlen(char const *);

int ifneg(int, int);

char my_rev_params(int, char **);

char *my_revstr(char *);

char *my_strcat(char *, char const *);

char *my_strcpy(char *, char const *);

char *my_strncat(char *, char const *, int);

char *my_strncpy(char *, char const *, int);

char *my_strstr(char *, char const *);

char **my_str_to_word_array(char const *);

char *concat_params(int, char **);

char *my_strdup(char const *);

#endif