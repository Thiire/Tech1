/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "navy.h"

void dot_h(void)
{
    my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\nDESCRIPTION"
    "\n\tfirst_player_pid:  only for the 2nd player.  pid of the first player"
    ".\n\tnavy_positions:  file representing the positions of the ships.\n");
}

int player1_setup(char **av, Map_t *map)
{
    int fd = open(av[1], O_RDONLY);

    if (fd == -1) {
        my_printf("Error: Bad files\n");
        return (84);
    }
    if ((map->map1 = my_create_map(av[1])) == NULL) {
        my_er("Error: Invalid map\n", 2);
        return (84);
    }
    my_printf("my_pid:  %d\n", getpid());
    if (signal_manager1(map) == 84)
        return (84);
    map->map2 = enemy_map();
    initial_print(map);
    return (turn_gestion1(map));
}

int player2_setup(char **av, Map_t *map)
{
    int fd = open(av[2], O_RDONLY);

    if (fd == -1) {
        my_printf("Error: Bad files\n");
        return (84);
    }
    if ((map->map1 = my_create_map(av[2])) == NULL) {
        my_er("Error: Invalid map\n", 2);
        return (84);
    }
    my_printf("my_pid:  %d\n", getpid());
    if (signal_manager2(map, my_getnbr(av[1])) == 84)
        return (84);
    map->map2 = enemy_map();
    initial_print(map);
    return (turn_gestion2(map));
}

int main(int ac, char **av)
{
    Map_t *map = malloc(sizeof(Map_t));
    data = malloc(sizeof(data_t));
    int tmp = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        dot_h();
    } else if (ac < 2 || ac > 3) {
        my_er("Error: Bad argument(s)\n", 2);
        return (84);
    } else {
        if (ac == 2 && (tmp = player1_setup(av, map)) == 84)
            return (84);
        else if (ac == 3 && (tmp = player2_setup(av, map)) == 84)
            return (84);
    }
    usleep(100000);
    kill(data->p_id, 10);
    return (tmp);
}
