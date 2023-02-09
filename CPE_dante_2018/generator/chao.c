/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** chao.c
*/

#include "generator.h"

void var4(int nb, char **tab, int i, int j)
{
    if (nb == 18)
        way4(tab, i, j, way1(tab, i, j, way2(tab, i, j,
        way3(tab, i, j, 0))));
    if (nb == 19)
        way4(tab, i, j, way1(tab, i, j, way3(tab, i, j,
        way2(tab, i, j, 0))));
    if (nb == 20)
        way4(tab, i, j, way2(tab, i, j, way1(tab, i, j,
        way3(tab, i, j, 0))));
    if (nb == 21)
        way4(tab, i, j, way2(tab, i, j, way3(tab, i, j,
        way1(tab, i, j, 0))));
    if (nb == 22)
        way4(tab, i, j, way3(tab, i, j, way1(tab, i, j,
        way2(tab, i, j, 0))));
    if (nb == 23)
        way4(tab, i, j, way3(tab, i, j, way2(tab, i, j,
        way1(tab, i, j, 0))));
}

void var3(int nb, char **tab, int i, int j)
{
    if (nb == 12)
        way3(tab, i, j, way1(tab, i, j, way2(tab, i, j,
        way4(tab, i, j, 0))));
    if (nb == 13)
        way3(tab, i, j, way1(tab, i, j, way4(tab, i, j,
        way2(tab, i, j, 0))));
    if (nb == 14)
        way3(tab, i, j, way2(tab, i, j, way1(tab, i, j,
        way4(tab, i, j, 0))));
    if (nb == 15)
        way3(tab, i, j, way2(tab, i, j, way4(tab, i, j,
        way1(tab, i, j, 0))));
    if (nb == 16)
        way3(tab, i, j, way4(tab, i, j, way1(tab, i, j,
        way2(tab, i, j, 0))));
    if (nb == 17)
        way3(tab, i, j, way4(tab, i, j, way2(tab, i, j,
        way1(tab, i, j, 0))));
    var4(nb, tab, i, j);
}

void var2(int nb, char **tab, int i, int j)
{
    if (nb == 6)
        way2(tab, i, j, way1(tab, i, j, way3(tab, i, j,
        way4(tab, i, j, 0))));
    if (nb == 7)
        way2(tab, i, j, way1(tab, i, j, way4(tab, i, j,
        way3(tab, i, j, 0))));
    if (nb == 8)
        way2(tab, i, j, way3(tab, i, j, way1(tab, i, j,
        way4(tab, i, j, 0))));
    if (nb == 9)
        way2(tab, i, j, way3(tab, i, j, way4(tab, i, j,
        way1(tab, i, j, 0))));
    if (nb == 10)
        way2(tab, i, j, way4(tab, i, j, way1(tab, i, j,
        way3(tab, i, j, 0))));
    if (nb == 11)
        way2(tab, i, j, way4(tab, i, j, way3(tab, i, j,
        way1(tab, i, j, 0))));
    var3(nb, tab, i, j);
}

void var1(int nb, char **tab, int i, int j)
{
    if (nb == 0)
        way1(tab, i, j, way2(tab, i, j, way3(tab, i, j,
        way4(tab, i, j, 0))));
    if (nb == 1)
        way1(tab, i, j, way2(tab, i, j, way4(tab, i, j,
        way3(tab, i, j, 0))));
    if (nb == 2)
        way1(tab, i, j, way3(tab, i, j, way2(tab, i, j,
        way4(tab, i, j, 0))));
    if (nb == 3)
        way1(tab, i, j, way3(tab, i, j, way4(tab, i, j,
        way2(tab, i, j, 0))));
    if (nb == 4)
        way1(tab, i, j, way4(tab, i, j, way2(tab, i, j,
        way3(tab, i, j, 0))));
    if (nb == 5)
        way1(tab, i, j, way4(tab, i, j, way3(tab, i, j,
        way2(tab, i, j, 0))));
    var2(nb, tab, i, j);
}