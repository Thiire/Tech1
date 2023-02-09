/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** my_sort_int_array.c
*/

void my_swap(int *, int *);

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int y = 0;

    for (i = 0 ; i < size ; i++) {
        for (y = 0 ; y < size - 1 -i ; y++) {
            my_swap(&array[y], &array[y+1]);
        }
    }
}
