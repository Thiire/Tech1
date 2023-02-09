/*
** EPITECH PROJECT, 2018
** AIA_n4s_2018
** File description:
** main.c
*/

#include "n4s.h"

int min(int a, int b)
{
    if (a <= b)
        return (b);
    return (a);
}

char *tab_filler(char *str, int *tab, int i)
{
    char result = 0;

    for (int i = 0; str[i] != '.'; i++) {
        result = result * 10 + (str[i] - 48);
    }
    for (; str[0] != ':'; str++);
    str++;
    tab[i] = result;
    return (str);
}

void my_mover2(int *tab, char *str, int left, int right)
{
    for (int i = 0; i < 14; i++)
        left += tab[i];
    for (int i = 17; i < 30; i++)
        right += tab[i];
    mover(tab, str, left, right);
}

int my_mover(char *str)
{
    char *string = NULL;
    int tab[32];
    int result = 0;
    int i = 0;

    if (my_parsing(str, "Track Cleared:"))
        return (1);
    for (i = 0; str[0] != '\0' && (str[0] >= '0' && str[0] <= '9'); i++) {
        for (int i = 0; str[i] != '.'; i++)
            result = result * 10 + (str[i] - 48);
        for (; str[0] != ':'; str++);
        str++;
        tab[i] = result;
        result = 0;
    }
    tab[i] = 0;
    my_mover2(tab, string, 0, 0);
    return (0);
}

int main(void)
{
    char *str = NULL;

    my_er("START_SIMULATION\n", 1);
    str = get_next_line(0);
    my_er("CAR_FORWARD:0.5\n", 1);
    str = get_next_line(0);
    while (1) {
        my_er("GET_INFO_LIDAR\n", 1);
        str = get_next_line(0);
        if (my_mover(str + 22))
            break;
    }
    my_er("CAR_FORWARD:0\n", 1);
    usleep(100000);
    my_er("STOP_SIMULATION\n", 1);
    return (0);
}