/*
** EPITECH PROJECT, 2018
** function
** File description:
** printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void printf_d(va_list va)
{
    my_put_nbr(va_arg(va, int));
}

void printf_i(va_list va)
{
    my_put_nbr(va_arg(va, int));
}

void printf_o(va_list va)
{
    my_putnbr_base(va_arg(va, int), "01234567");
}

void printf_x(va_list va)
{
    my_putnbr_base(va_arg(va, int), "0123456789abcdef");
}

void printf_u(va_list va)
{
    my_putnbr_base_un(va_arg(va,unsigned int), "0123456789");
}
