/*
** EPITECH PROJECT, 2018
** my_compute_square_root.c
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    int x = 0;

    if (nb < 0 || nb == 0)
        return (0);
    for ( x = 0 ; x * x != nb ; x++ ) {
        if ( x > nb )
            return (0);
    }
    return (x);
}
