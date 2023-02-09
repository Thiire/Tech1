/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** input
*/

#include "navy.h"

void handler_usr1(int sig, siginfo_t *pid, void *context)
{
    data->letter++;
}

void handler_usr2(int sig, siginfo_t *pid, void *context)
{
    data->number++;
}

int defense(Map_t *map)
{
    struct sigaction sa1;
    struct sigaction sa2;

    data->number = 0;
    data->letter = 0;
    sigemptyset(&sa1.sa_mask);
    sigemptyset(&sa2.sa_mask);
    sa1.sa_flags = SA_SIGINFO;
    sa1.sa_sigaction = &handler_usr1;
    sa2.sa_flags = SA_SIGINFO;
    sa2.sa_sigaction = &handler_usr2;
    sigaction(10, &sa1, NULL);
    sigaction(12, &sa2, NULL);
    my_printf("waiting for enemy's attack...\n");
    pause();
    for (long wait = 0; wait <= 10000; wait++)
        usleep(1);
    return (print_update_map(map->map1, data->letter, data->number));
}

int attack(Map_t *map, int a, int b)
{
    int usr1 = a;
    int usr2 = b;

    usleep(100000);
    kill(map->p_id, 10);
    for (; usr1 > 0 || usr2 > 0; usr1--, usr2--) {
        if (usr1 > 0) {
            kill(map->p_id, 10);
            usleep(2);
        }
        if (usr2 > 0) {
            kill(map->p_id, 12);
            usleep(2);
        }
    }
    return (receive_hit(map, a, b));
}
