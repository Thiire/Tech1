/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** input_bis
*/

#include "navy.h"

void handler_hit(int sig, siginfo_t *pid, void *context)
{
    data->hit++;
}

void handler_miss(int sig, siginfo_t *pid, void *context)
{
    data->miss++;
}

int transfer_hit(Map_t *map, int nb)
{
    if (nb == 84)
        return (84);
    usleep(10000);
    kill(map->p_id, 10);
    usleep(2);
    kill(map->p_id, nb);
    return (0);
}

int print_new_map(Map_t *map, int a, int b)
{
    int j = 2 + ((a - 1) * 2);
    int i = 1 + b;

    if (data->hit == 1) {
        my_printf("hit\n\n");
        map->map2[i][j] = 'x';
    } else if (data->miss == 1) {
        my_printf("missed\n\n");
        if (map->map2[i][j] != 'x')
            map->map2[i][j] = 'o';
    }
    return (0);
}

int receive_hit(Map_t *map, int a, int b)
{
    struct sigaction sa1;
    struct sigaction sa2;

    data->hit = -1;
    data->miss = 0;
    sigemptyset(&sa1.sa_mask);
    sigemptyset(&sa2.sa_mask);
    sa1.sa_flags = SA_SIGINFO;
    sa1.sa_sigaction = &handler_hit;
    sa2.sa_flags = SA_SIGINFO;
    sa2.sa_sigaction = &handler_miss;
    sigaction(10, &sa1, NULL);
    sigaction(12, &sa2, NULL);
    pause();
    for (long wait = 0; wait <= 1000; wait++)
        usleep(1);
    return (print_new_map(map, a, b));
}