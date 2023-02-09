/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** check_death
*/

#include "navy.h"

void handler_life(int sig, siginfo_t *pid, void *context)
{
    data->life++;
}

void handler_death(int sig, siginfo_t *pid, void *context)
{
    data->death++;
}

int win(Map_t *map, char **pos)
{
    int j = 2;
    int i = 2;
    int check = 0;

    for (; i < 10; i++)
        for (j = 2; j < 17; j++)
            check += (pos[i][j] >= '1' && pos[i][j] <= '8') ? 1 : 0;
    usleep(100000);
    if (check != 0) {
        kill(map->p_id, 10);
        usleep(2);
        kill(map->p_id, 10);
        return (1);
    }
    kill(map->p_id, 10);
    usleep(2);
    kill(map->p_id, 12);
    initial_print(map);
    my_printf("Enemy won\n");
    return (0);
}

int checker(Map_t *map)
{
    if (data->life == 1) {
        return (1);
    } else if (data->death == 1) {
        initial_print(map);
        my_printf("I won\n");
        return (0);
    }
    return (1);
}

int win_check(Map_t *map)
{
    struct sigaction sa1;
    struct sigaction sa2;

    data->life = -1;
    data->death = 0;
    sigemptyset(&sa1.sa_mask);
    sigemptyset(&sa2.sa_mask);
    sa1.sa_flags = SA_SIGINFO;
    sa1.sa_sigaction = &handler_life;
    sa2.sa_flags = SA_SIGINFO;
    sa2.sa_sigaction = &handler_death;
    sigaction(10, &sa1, NULL);
    sigaction(12, &sa2, NULL);
    pause();
    for (long wait = 0; wait <= 1000; wait++)
        usleep(1);
    return (checker(map));
}