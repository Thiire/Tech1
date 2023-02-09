/*
** EPITECH PROJECT, 2018
** function3
** File description:
** printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void printf_big_x(va_list va)
{
    my_putnbr_base(va_arg(va, int), "0123456789ABCDEF");
}

void printf_percent(va_list va)
{
    ((void) va);
    my_putchar('%');
}

void printf_z(va_list va)
{
    ((void) va);
    my_putchar('%');
}