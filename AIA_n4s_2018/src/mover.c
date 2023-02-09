/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** mover
*/

#include "n4s.h"

void mover3_bis(int *tab, char *str, int nb)
{
    if (tab[16] >= 200) {
        my_er("CAR_FORWARD:0.15\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:-0.35\n", 1);
        str = get_next_line(0);
    } else {
        my_er("CAR_FORWARD:0.1\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:-0.50\n", 1);
        str = get_next_line(0);
    }
}

void mover3(int *tab, char *str, int nb)
{
    if (tab[16] >= 1000 && nb < 25) {
        my_er("WHEELS_DIR:-0.01\n", 1);
        str = get_next_line(0);
        return;
    }
    if (tab[16] >= 750) {
        my_er("CAR_FORWARD:0.4\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:-0.10\n", 1);
        str = get_next_line(0);
    } else if (tab[16] >= 550) {
        my_er("CAR_FORWARD:0.35\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:-0.25\n", 1);
        str = get_next_line(0);
    } else
        mover3_bis(tab, str, nb);
}

void mover2_bis(int *tab, char *str, int nb)
{
    if (tab[16] >= 200) {
        my_er("CAR_FORWARD:0.15\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:0.35\n", 1);
        str = get_next_line(0);
    } else {
        my_er("CAR_FORWARD:0.1\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:0.50\n", 1);
        str = get_next_line(0);
    }
}

void mover2(int *tab, char *str, int nb)
{
    if (tab[16] >= 1000 && nb < 25) {
        my_er("WHEELS_DIR:0.01\n", 1);
        str = get_next_line(0);
        return;
    }
    if (tab[16] >= 750) {
        my_er("CAR_FORWARD:0.4\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:0.10\n", 1);
        str = get_next_line(0);
    } else if (tab[16] >= 550) {
        my_er("CAR_FORWARD:0.35\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:0.25\n", 1);
        str = get_next_line(0);
    } else
        mover2_bis(tab, str, nb);
}

void mover(int *tab, char *str, int left, int right)
{
    int nb = 0;

    nb = ((abs(left - right) * 100) / min(left, right));
    if (tab[16] >= 2000 && nb < 15) {
        my_er("CAR_FORWARD:0.75\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:0\n", 1);
        str = get_next_line(0);
    } else if (tab[16] >= 1000 && nb < 15) {
        my_er("CAR_FORWARD:0.65\n", 1);
        str = get_next_line(0);
        my_er("WHEELS_DIR:0\n", 1);
        str = get_next_line(0);
    } else {
        if (left > right)
            mover2(tab, str, nb);
        else
            mover3(tab, str, nb);
    }
}
