/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** signal_gestion
*/

#include "navy.h"

void hdl(int sig, siginfo_t *pid, void *context)
{
    data->p_id = pid->si_pid;
}

int signal_manager1(Map_t *map)
{
    struct sigaction sa;

    data->p_id = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &hdl;
    my_printf("waiting for enemy connection...\n\n");
    sigaction(10, &sa, NULL);
    pause();
    map->p_id = data->p_id;
    kill(data->p_id, 10);
    my_printf("enemy connected\n\n");
    return (0);
}

int signal_manager2(Map_t *map, int p1_id)
{
    struct sigaction sa;

    data->p_id = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &hdl;
    kill(p1_id, 10);
    sigaction(10, &sa, NULL);
    usleep(100);
    map->p_id = p1_id;
    if (map->p_id != data->p_id) {
        my_er("Can't connect\n", 2);
        return (84);
    }
    my_printf("successfully connected\n\n");
    return (0);
}
