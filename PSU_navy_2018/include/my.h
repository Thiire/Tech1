/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** lib
*/

#include <stdio.h>
#include <stdarg.h>

void printf_z(va_list va);
int my_putnbr_base_l(long nb, char *base);
int my_putstr_s(unsigned char const *s);
void printf_percent(va_list va);
void printf_big_x(va_list va);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_putnbr_base(int nb, char *base);
unsigned int my_putnbr_base_un(unsigned int nb, char *base);
void my_putchar(char c);
int my_put_nbr(int nb);
void printf_p(va_list va);
void printf_b(va_list va);
void printf_c(va_list va);
void printf_s(va_list va);
void printf_big_s(va_list va);
void printf_d(va_list va);
void printf_i(va_list va);
void printf_o(va_list va);
void printf_x(va_list va);
void printf_u(va_list va);
void my_printf(char *s, ...);
int flag(char c, va_list);

typedef struct flag
{
    char type;
    void (*fptr)(va_list);
} flag_t;