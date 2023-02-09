/*
** EPITECH PROJECT, 2018
** pong_main.c
** File description:
** pong_main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int my_strcmp(char const *, char const *);

int check(char **av, float *v)
{
    double result = 0;
    if (av[6][0] < 48 && (v[2] * (av[7][0] - 48) + (float)av[6][0]) < 48)
    {
        printf("The ball won’t reach the bat.\n");
        return (0);
    }
    if (av[6][0] > 48 && (v[2] * (av[7][0] - 48) + (float)av[6][0]) > 48)
    {
        printf("The ball won’t reach the bat.\n");
        return (0);
    }
    result = sqrt(pow(v[0], 2) + pow(v[1], 2)) / 
    sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
    printf("The incidence angle is:\n");
    printf("%0.2f degrees\n", acosf(result) * (180 / PI));
    return (0);
}

int display_help()
{
    printf("USAGE\n\t");
    printf("./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    printf("DESCRIPTION\n");
    printf("\tx0\tball abscissa at time t - 1\n");
    printf("\ty0\tball ordinate at time t - 1\n");
    printf("\tz0\tball altitude at time t - 1\n");
    printf("\tx1\tball abscissa at time t\n");
    printf("\ty1\tball ordinate at time t\n");
    printf("\tz1\tball altitude at time t\n");
    printf("\tn\ttime shift (greater than or equal to zero, integer)\n");
    exit (0);
}

int main(int ac, char **av)
{
    float vector[3];

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_help();
        exit (0);
    } else if (ac != 8)
        exit (84);
    vector[0] = atof(av[4]) - atof(av[1]);
    vector[1] = atof(av[5]) - atof(av[2]);
    vector[2] = atof(av[6]) - atof(av[3]);
    printf("The velocity vector of the ball is:\n");
    printf("(%0.2f, %0.2f, %0.2f)\n", vector[0], vector[1], vector[2]);
    printf("At time t + %d, ball coordinates will be:\n", av[7][0] - 48);
    printf("(%0.2f, ", (vector[0] * (av[7][0] - 48) + atof(av[4])));
    printf("%0.2f, ", (vector[1] * (av[7][0] - 48) + atof(av[5])));
    printf("%0.2f)\n", (vector[2] * (av[7][0] - 48) + atof(av[6])));
    return (check(av, vector));
}