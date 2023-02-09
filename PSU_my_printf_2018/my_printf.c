/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf.c
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

char *first_test(char *s, va_list list, char *result, int *res);

char *test(char *s, va_list list, char *result, int *res)
{
    if (result[0] == 'l' && result[1] == 'l' && result[2] == 'd') {
        my_put_nbrs(va_arg(list, long long int), res);
        return (s += 4 + res[1]);
    }
    if (result[0] == 'l' && result[1] == 'd') {
        my_put_nbrs(va_arg(list, long long int), res);
        return (s += 3 + res[1]);
    }
    if (result[0] == 'c') {
        my_putchar(va_arg(list, long long int), res);
        return (s += 2 + res[1]);
    }
    return (first_test(s, list, result, res));
}

char *to_find(char *s, va_list list)
{
    int num = 0;
    int i = 1;
    char *result = malloc(sizeof(char) * (my_strlen(s) + 1));
    char *stack = malloc(sizeof(char) * (my_strlen(s) + 1));
    int *res = malloc(sizeof(int) * 4);

    if (s[1] == '%') {
        write(1, "%%", 1);
        return (s += 2);
    }
    for (i = 1; s[i] != '\0' && s[i] != ' ' && issalpha(s[i]) == 0; i++)
        stack[i - 1] = s[i];
    res[0] = (stack[0] >= 0) ? my_getnbr(stack) : 0;
    res[1] = (stack[0] >= 0) ? my_strlen(stack) : 0;
    res[2] = (stack[0] == '0') ? 1 : 0;
    for (num = 0; issalpha(s[i]) == 1 && num < 3; i++) {
        result[num] = s[i];
        num++;
    }
    return (test(s, list, result, res));
}

int clean(char *stock)
{
    int size = my_strlen(stock);

    for (int i = 0; i < size; i++) {
        c_putchar(stock[i]);
        stock[i] = '\0';
    }
    return (0);
}

int my_printf(char *s, ...)
{
    int size = my_strlen(s);
    char *stock = malloc(sizeof(char) * (size + 1));
    va_list list;

    va_start(list, s);
    for (int i = 0; s[0] != '\0'; i++) {
        for (int y = 0; s[0] != '\0' && s[0] != '%'; s++) {
            stock[y] = s[0];
            y++;
        }
        clean(stock);
        if (s[0] == '%') {
            s = to_find(s, list);
        }
    }
    va_end(list);
    return (0);
}
