/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** debu_mode3
*/

#include "tetris.h"

void manage_key2(input_t *key)
{
    my_stdout("\nNext :  ", 1);
    if (key->next == 1)
        my_stdout("Yes\n", 1);
    else
        my_stdout("False\n", 1);
    my_stdout("Level :  ", 1);
    my_intout(key->level, 1);
    my_stdout("\nSize :  ", 1);
    my_intout(key->x, 1);
    my_stdout("*", 1);
    my_intout(key->y, 1);
    my_stdout("\n", 1);
}

void manage_key(input_t *key)
{
    my_stdout("Key Left :  ", 1);
    my_stdout(key->left, 1);
    my_stdout("\nKey Right :  ", 1);
    my_stdout(key->right, 1);
    my_stdout("\nKey Turn :  ", 1);
    my_stdout(key->turn, 1);
    my_stdout("\nKey Drop :  ", 1);
    my_stdout(key->drop, 1);
    my_stdout("\nKey Quit :  ", 1);
    my_stdout(key->quit, 1);
    my_stdout("\nKey Pause :  ", 1);
    if (str_compare(key->pause, " "))
        my_stdout("(space)", 1);
    else
        my_stdout(key->pause, 1);
    return (manage_key2(key));
}

int debug_mode(input_t *key)
{
    my_stdout("*** DEBUG MODE ***\n", 1);
    manage_key(key);
    tetriminos();
    my_stdout("Press any key to start Tetris\n", 1);
    return (0);
}