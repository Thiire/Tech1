/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "boogle.h"

char *restocker(char *stock, char *result, char *stack)
{
    int n = 0;
    int length = 0;
    char *restock;

    for (length = 0; result[length] != '\0'; length++);
    restock = malloc(sizeof(char) * (length + READ_SIZE + 1));
    for (int n = 0; n < READ_SIZE + length + 1; n++)
            restock[n] = '\0';
    for (int i = 0; i < length; i++)
        restock[i] = result[i];
    for (n = 0; n < READ_SIZE; n++) {
        if (stock[n] == '\n' || stock[n] == '\0')
            break;
        restock[length + n] = stock[n];
    }
    restock[length + n] = stock[n];
    if (stock[n] == '\n' && *stock != *stack)
        for (int i = 0; stock[n + 1] != '\0'; i++, n++)
            stack[i] = stock[n + 1];
    return (restock);
}

void modifie(char *stack)
{
    int score = 0;
    int n = 0;

    for (int i = 0; stack[i] != '\0'; i++)
        if (stack[i] == '\n') {
            score = i + 1;
            break;
        }
    for (n = 0; score + n < READ_SIZE; n++) {
        if (stack[score + n] != '\0' && score != 0)
            stack[n] = stack[score + n];
        else
            stack[n] = '\0';
    }
}

int to_confirm(char *result, int enter)
{
    int lg = 0;

    for (lg = 0; result[lg] != '\0'; lg++);
    if (result[lg - 1] == '\n') {
        enter = 0;
    result[lg - 1] = '\0';
    }
    return (enter);
}

char *get_length(int enter, char *stack, int of, int ft)
{
    char *stock = malloc(sizeof(char) * READ_SIZE + 2);
    char *result = malloc(sizeof(char) * READ_SIZE + 2);

    for (int n = 0; n < READ_SIZE + 2; n++)
        stock[n] = '\0';
    for (int n = 0; n < READ_SIZE + 2; n++)
        result[n] = '\0';
    while (enter != 0) {
        if (stack[0] == '\0') {
            enter = read(of, stock, READ_SIZE);
            result = restocker(stock, result, stack);
        } else {
            result = restocker(stack, result, stack);
            modifie(stack);
        }
        enter = to_confirm(result, enter);
        if (enter == -1)
            return (NULL);
    }
    return (result);
}

char *get_next_line(int fd)
{
    static int of;
    static int ft;
    static int enter;
    static char *stack;
    of = fd;
    enter = 1;
    if (ft == 0) {
        stack = malloc(sizeof(char) * READ_SIZE + 1);
        for (int n = 0; n < READ_SIZE; n++)
            stack[n] = '\0';
        ft++;
        return (get_length(enter, stack, of, ft));
    }
    return (get_length(enter, stack, of, ft));
}
