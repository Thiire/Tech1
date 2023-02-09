/*
** EPITECH PROJECT, 2018
** verification.c
** File description:
** verification.c
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char, int *);

void c_putchar(char);

int my_put_nbrs(long long int, int *);

int my_putstr(char const *, int *);

int c_putstr(char const *);

int my_strlen(char const *);

int my_getnbr(char const *);

int issalpha(char);

long long int absolute(long long int);

int my_putnbr_base(int, char const *, int *);

int my_putnbr_p(unsigned long int, char const *, int *);

int showstr(char const *str, int *);

char *third_test(char *s, va_list list, char *result, int *res)
{
    if (result[0] == 'b') {
        my_putnbr_base(va_arg(list, long long int), "01\n", res);
        return (s += 2 + res[1]);
    }
    if (result[0] == 'S') {
        showstr(va_arg(list, char *), res);
        return (s += 2 + res[1]);
    }
    exit(0);
}

char *second_test(char *s, va_list list, char *result, int *res)
{
    if (result[0] == 'x') {
        my_putnbr_base(va_arg(list, long long int), "0123456789abcdef\n", res);
        return (s += 2 + res[1]);
    }
    if (result[0] == 'p') {
        write(1, "0x", 2);
        my_putnbr_p(va_arg(list, unsigned long int), "0123456789abcdef\n", res);
        return (s += 2 + res[1]);
    }
    if (result[0] == 'o') {
        my_putnbr_base(va_arg(list, long long int), "01234567\n", res);
        return (s += 2 + res[1]);
    }
    return (third_test(s, list, result, res));
}

char *first_test(char *s, va_list list, char *result, int *res)
{
    if (result[0] == 's') {
        my_putstr(va_arg(list, char *), res);
        return (s += 2 + res[1]);
    }
    if (result[0] == 'd' || result[0] == 'i' || result[0] == 'u') {
        my_put_nbrs(va_arg(list, long long int), res);
        return (s += 2 + res[1]);
    }
    if (result[0] == 'X') {
        my_putnbr_base(va_arg(list, long long int), "0123456789ABCDEF\n", res);
        return (s += 2 + res[1]);
    }
    return (second_test(s, list, result, res));
}