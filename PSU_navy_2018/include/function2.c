/*
** EPITECH PROJECT, 2018
** function2
** File description:
** printf
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void printf_p(va_list va)
{
    my_putstr("0x");
    my_putnbr_base_l(va_arg(va, long), "0123456789abcdef");
}

void printf_b(va_list va)
{
    my_putnbr_base(va_arg(va, int), "01");
}

void printf_c(va_list va)
{
    my_putchar(va_arg(va, int));
}

void printf_s(va_list va)
{
    my_putstr(va_arg(va, char *));
}

void printf_big_s(va_list va)
{
    my_putstr_s(va_arg(va, unsigned char *));
}
