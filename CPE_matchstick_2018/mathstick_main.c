/*
** EPITECH PROJECT, 2019
** mathstick.c
** File description:
** mathstick.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "matchstick.h"

static int matches;
static char **tab;
static int num1;
static int num2;
static int player;

int choose_match(int number, int high, int *res)
{
    int result = 0;
    int stock = 0;

    for (int n = 1; n < high + 1 && result == 0; n++) {
        result = (res[n] >= number) ? n : 0;
    }
    if (result == 0) {
        for (int n = 1; n < high + 1; n++) {
            result = (res[n] > stock) ? n : result;
            stock = (res[n] > stock) ? res[n] : stock;
        }
        num2 = stock;
        num1 = result;
    } else {
        num2 = number;
        num1 = result;
    }
    my_printf("AI removed %d match(es) from line %d\n", num2, num1);
    return (modiffier(high));
}

int move_match(int high, int *res, int account)
{
    if (account <= matches + 1) {
        if (account == 1) {
            choose_match(1, high, res);
            return (0);
        }
        choose_match(account - 1, high, res);
        return (0);
    }
    if (account % (matches + 2) == 0) {
        if (account == (matches + 2))
            choose_match(1, high, res);
        else
            choose_match(matches, high, res);
    } else if (account % (matches + 2) >= matches) {
        choose_match(matches, high, res);
    } else {
        choose_match(account % (matches + 2), high, res);
    }
    return (0);
}

int matcher(int high)
{
    int result = 0;
    int *res = malloc(sizeof(int) * high + 2);

    for (int n = 0; n < high + 2; n++)
        res[n] = 0;
    for (int n = 1; n < high + 1; n++) {
        for (int i = 1; i < high * 2; i++) {
            result += (tab[n][i] == '|') ? 1 : 0;
            res[n] += (tab[n][i] == '|') ? 1 : 0;
        }
    }
    return (move_match(high, res, result));
}

int verif(int high)
{
    int result = 0;

    for (int n = 1; n < high + 1 && result == 0; n++)
        for (int i = 1; i < high * 2 && result == 0; i++)
            result = (tab[n][i] == '|') ? 1 : 0;
    if (result == 1) {
        return (0);
    } else {
        return (2);
    }
}

int displayer(int high)
{
    for (int i = 0; i < high + 2; i++) {
        write(1, tab[i], high * 2 + 1);
        write(1, "\n", 1);
    }
    player = (player == 1) ? 0 : 1;
    if (verif(high) == 0 && player == 0) {
        my_printf("\nYour turn:\n");
        return (0);
    } else if (verif(high) == 0 && player == 1) {
        my_printf("\nAI's turn...\n");
        return (matcher(high));
    }
    if (player == 0)
        return (3);
    else if (player == 1)
        return (4);
}

int modiffier(int high)
{
    int position = 0;
    int w = 0;

    for (int n = 0; n < high * 2; n++)
        if (tab[num1][n] == '|') {
            position = n;
            w++;
        }
    if (num2 > w && verif(high) == 0) {
        my_printf("Error: not enough matches on this line\n");
        return (input_displayer(high));
    } else if (verif(high) == 0) {
        for (int i = 0; i < num2; i++)
            tab[num1][position - i] = ' ';
        if (player == 0)
            my_printf("Player removed %d match(es) from line %d\n", num2, num1);
        return (displayer(high));
    } else if (player == 0)
        return (4);
    return (3);
}

int second_follow(int high, char *second)
{
    for (int i = 0; second[i] != '\0'; i++)
        if (second[i] < 48 || second[i] > 57) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (2);
        }
    num2 = my_getnbr(second);
    if (num2 == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (2);
    }
    if (num2 > matches) {
        my_printf("Error: you cannot remove more than %d matches"
        " per turn\n", matches);
        return (input_displayer(high));
    }
    return (0);
}

int second_input(int high)
{
    char *second;

    if (verif(high) != 0)
        return (0);
    write(1, "Matches: ", 9);
    second = get_next_line(0);
    if (second[0] == '\0')
        return (5);
    return (second_follow(high, second));
}

int first_input(int high)
{
    char *first;

    write(1, "Line: ", 6);
    first = get_next_line(0);
    if (first[0] == '\0')
        return (5);
    for (int i = 0; first[i] != '\0'; i++)
        if (first[i] < 48 || first[i] > 57) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (input_displayer(high));
        }
    num1 = my_getnbr(first);
    if (num1 > high || num1 == 0) {
        my_printf("Error: this line is out of range\n");
        return (input_displayer(high));
    }
    return (0);
}

int input_displayer(int high)
{
    int check = verif(high);
    int verif1 = 0;
    int verif2 = 0;

    if (check == 2 && player == 1) {
        return (3);
    } else if (check == 2 && player == 0) {
        return (4);
    }
    if ((verif1 = first_input(high)) == 5)
        return (5);
    if ((verif2 = second_input(high)) == 5)
        return (5);
    if (verif1 == 2 || verif2 == 2)
        return (input_displayer(high));
    if (modiffier(high) != 0)
        return (modiffier(high));
    return (input_displayer(high));
    return (0);
}

int map_creator(int high)
{
    tab = malloc(sizeof(char *) * (high + 2));
    for (int i = 0; i < high + 2; i++) {
        tab[i] = my_malloc(high * 2 + 1);
        for (int n = 0; n < high * 2; n++)
            tab[i][n] = ' ';
    }
    for (int i = 0; i < high + 2; i++) {
        tab[i][0] = '*';
        tab[i][high * 2] = '*';
    }
    for (int i = 0; i < high * 2; i++) {
        tab[0][i] = '*';
        tab[high + 1][i] = '*';
    }
    for (int n = 1; n < high; n++)
        for (int j = 0 ; j < 2 * n + 1; j++)
            tab[n + 1][high - n + j] = '|';
    tab[1][high] = '|';
    displayer(high);
    return (input_displayer(high));
}

int main(int ac, char **number)
{
    int high = my_getnbr(number[1]);
    int victory = 0;

    player = 1;
    matches = my_getnbr(number[2]);
    if (high <= 1 || matches < 1) {
        write(2, "Invalid arguments\n", 18);
        return (84);
    } else {
        victory = map_creator(high);
        if (victory == 5)
            return (0);
        if (victory == 3)
            my_printf("You lost, too bad...\n");
        else if (victory == 4)
            my_printf("I lost... snif... but I'll get you next time!!\n");
        if (player == 0)
            return (1);
        return (2);
    }
}