/*
** EPITECH PROJECT, 2018
** my_sorter.c
** File description:
** my_sorter.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void big_swap(int *, int *, int);

int check(int *, int);

void rotate_right(int *, int);

void rotate_left(int *, int);

void swap(int *);

void my_third(int *, int *, int, char *);

void writer(char *, char *);

int displayer(char *);

void letter_2(int *l_a, int *l_b, long int size, char *str)
{
    if (l_a[0] > l_a[1]) {
        swap(l_a);
        writer(str, "sa ");
    }
    big_swap(l_b, l_a, size);
    writer(str, "pb ");
}

void my_second(int *l_a, int *l_b, long int size, char *str)
{
    big_swap(l_b, l_a, size);
    swap(l_a);
    big_swap(l_a, l_b, size);
    writer(str, "pb sa pa ");
    if (l_a[0] > l_a[2]) {
        swap(l_a);
        writer(str, "sa ");
    }
}

void letter_3(int *l_a, int *l_b, long int size, char *str)
{
    if (l_a[0] > l_a[1] && l_a[1] <= l_a[2]) {
        swap(l_a);
        writer(str, "sa ");
        if (l_a[0] > l_a[2]) {
            big_swap(l_b, l_a, size);
            swap(l_a);
            big_swap(l_a, l_b, size);
            writer(str, "pb sa pa ");
        }
    } else if (l_a[0] > l_a[1] && l_a[1] > l_a[2]) {
        my_third(l_a, l_b, size, str);
    } else if (l_a[0] < l_a[1] && l_a[1] > l_a[2]) {
        my_second(l_a, l_b, size, str);
    }
    big_swap(l_b, l_a, size);
    big_swap(l_b, l_a, size);
    writer(str, "pa pa ");
}

int my_sorter(int *l_a, int *l_b, long int size, char *str)
{
    if (size == 1)
        return (0);
    while (check(l_a, size) != 0 && size % 2 != 0) {
        for (int i = 0; i <= size / 2 - 1; i++)
            letter_3(l_a, l_b, size, str);
        for (int i = 0; i <= size - 2; i++) {
            big_swap(l_a, l_b, size);
            writer(str, "pb ");
        }
    }
    while (check(l_a, size) != 0 && size % 2 == 0) {
        for (int i = 0; i < size / 2 - 1; i++)
            letter_3(l_a, l_b, size, str);
        letter_2(l_a, l_b, size, str);
        for (int i = 0; i <= size - 2; i++) {
            big_swap(l_a, l_b, size);
            writer(str, "pb ");
        }
    }
    return (0);
}

int main(int ac, char **ag)
{
    int l_a[ac - 1];
    int l_b[ac - 1];
    char *str = malloc(sizeof(char) * 10000000);

    for (int i = 0; i < ac; i++) {
        l_a[i] = 0;
        l_b[i] = 0;
    }
    if (ac == 1)
        return (84);
    for (int i = 0; i < ac - 1; i++)
        for (int y = 0; ag[i + 1][y] != '\0'; y++)
            l_a[i] = l_a[i] * 10 + (ag[i + 1][y] - 48);
    if (ac == 3 && check(l_a, ac - 1) != 0) {
        swap(l_a);
        writer(str, "sa ");
    }
    my_sorter(l_a, l_b, ac - 1, str);
    return (displayer(str));
}
