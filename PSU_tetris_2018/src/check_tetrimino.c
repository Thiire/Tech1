/*
** EPITECH PROJECT, 2018
** PSU_bstetris_2018
** File description:
** check_tetrimino.c
*/

#include "tetris.h"

void dash_h(void)
{
    my_stdout("Usage: ./tetris [options]\nOptions:\n  --help        "
    "       Display this help\n  -L --level={num}     Start Tetris a"
    "t level num (def: 1)\n  -l --key-left={K}    Move the tetrimino"
    " LEFT using the K key (def: left arrow)\n  -r --key-right={K}  "
    " Move the tetrimino RIGHT using the K key (def: right arrow)\n "
    " -t --key-turn={K}    TURN teh tetrimino  clockwise 90d using t"
    "he K key (def: top arrow)\n  -d --key-drop={K}    DROP the tetr"
    "imino using the K key (def: down arrow)\n  -q --key-quit={K}   "
    " QUIT the game using the K key (def: 'q' key)\n  -p --key-pause"
    "={K}   PAUSE/RESTART the game using the K key (def: space bar)"
    "\n  --map-size{row, col} Set the numbers of rows and columns o"
    "f the map (def: 20,10)\n  -w --without-next    Hide next tetrim"
    "ino (def: false)\n  -D --debug           Debug mode (def: false)\n", 1);
}

input_t *key_filler(void)
{
    input_t *tmp = malloc(sizeof(input_t));

    tmp->debug = 0;
    tmp->level = 1;
    tmp->next = 1;
    tmp->x = 20;
    tmp->y = 10;
    tmp->drop = my_cpy("^EOB");
    tmp->left = my_cpy("^EOD");
    tmp->right = my_cpy("^EOC");
    tmp->turn = my_cpy("^EOA");
    tmp->pause = my_cpy(" ");
    tmp->quit = my_cpy("q");
    return (tmp);
}

int main(int ac, char **av)
{
    input_t *key = key_filler();

    if (ac == 2 && str_compare(av[1], "--help")) {
        dash_h();
        return (0);
    }
    flag_check(av, key);
    if (key->debug == 1)
        debug_mode(key);
    return (0);
}