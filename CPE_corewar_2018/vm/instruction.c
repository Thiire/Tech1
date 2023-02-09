/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** instruction
*/

#include "../includes/corewar.h"

instru_t *tab(void)
{
    instru_t *tab = malloc(sizeof(instru_t) * 17);

    tab[0] = (instru_t){"01", &clive};
    tab[1] = (instru_t){"02", &cld};
    tab[2] = (instru_t){"03", &cst};
    tab[3] = (instru_t){"04", &cadd};
    tab[4] = (instru_t){"05", &csub};
    tab[5] = (instru_t){"06", &cand};
    tab[6] = (instru_t){"07", &cor};
    tab[7] = (instru_t){"08", &cxor};
    tab[8] = (instru_t){"09", &czjmp};
    tab[9] = (instru_t){"0a", &cldi};
    tab[10] = (instru_t){"0b", &csti};
    tab[11] = (instru_t){"0c", &cfork};
    tab[12] = (instru_t){"0d", &clld};
    tab[13] = (instru_t){"0e", &clldi};
    tab[14] = (instru_t){"0f", &clfork};
    tab[15] = (instru_t){"10", &caff};
    tab[16] = (instru_t){0, NULL};
    return (tab);
}

void caff(char *str, int type)
{

}

void comp(char **buffer, int pos)
{
    instru_t *board = tab();
    int type = 0;

    for (int i = 0; buffer[i] != NULL; i++)
        for (int j = 0; board[j].type != 0; j++)
            if (str_compare(buffer[i], board[j].type))
                board[i].fptr(buffer[i], type);
}