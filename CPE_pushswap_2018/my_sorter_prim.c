/*
** EPITECH PROJECT, 2018
** my_sorter_bis.c
** File description:
** my_sorter_bis.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void big_swap(int *, int *, int);

int check(int *, int);

void rotate_right(int *, int);

void rotate_left(int *, int);

void swap(int *);

void writer(char *str, char *stock)
{
    long int length = 0;

    for (length = 0; str[length] != '\0'; length++);
    if (length < 9999980) {
        for (int n = 0; stock[0] != '\0'; n++) {
            str[length + n] = stock[0];
            stock++;
        }
    }
}

void my_third(int *l_a, int *l_b, long int size, char *str)
{
    swap(l_a);
    big_swap(l_b, l_a, size);
    swap(l_a);
    big_swap(l_b, l_a, size);
    swap(l_b);
    big_swap(l_a, l_b, size);
    big_swap(l_a, l_b, size);
    writer(str, "sa pb sa pb sb pa pa ");
}

int displayer(char *str)
{
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n + 1] == '\0' && str[n] == ' ') {
        } else {
            write(1, &str[n], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
