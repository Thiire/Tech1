/*
** EPITECH PROJECT, 2018
** my_sorter_bis.c
** File description:
** my_sorter_bis.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void big_swap(int *l_a, int *l_b, long int size)
{
    int result = l_b[0];
    int i = 0;

    for (i = 0; i + 1 < size; i++) {
        l_b[i] = l_b[i + 1];
    }
    l_b[i] = 0;
    for (int y = 0; y < size; y++) {
        l_a[size - 1 - y] = l_a[size - 2 - y];
    }
    l_a[0] = result;
}

int check(int *array, long int size)
{
    int result = 0;

    for (int i = 0; i + 1 < size; i++) {
        result += (array[i] > array[i + 1]) ? 1 : 0;
    }
    return (result);
}

void rotate_right(int *array, long int size)
{
    int result = array[size - 1];

    for (int i = 0; i < size; i++) {
        array[size - 1 - i] = array[size - 2 - i];
    }
    array[0] = result;
}

void rotate_left(int *array, long int size)
{
    int result = array[0];

    for (int i = 0; i + 1 < size; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = result;
}

void swap(int *array)
{
    int stack = 0;

    stack = array[0];
    array[0] = array[1];
    array[1] = stack;
}
