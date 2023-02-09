/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "../includes/corewar.h"

int dash_h(char **av)
{
    my_er("USAGE\n\t", 1);
    my_er(av[0], 1);
    my_er(" [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name]"
    " ...\n\nDESCRIPTION\n\t-dump nbr_cycle\tdumps the memory after the nbr_"
    "cycle execution (if the round isn't\n\t\t\talready over) with the follo"
    "wing format: 32 bytes/line in\n\t\t\thexadecimal (AOBCDEFE1DD3...)\n\t-"
    "n prog_number\tsets the next program's number. By default, the first fr"
    "ee number\n\t\t\tin the parameter order\n\t-a load_address\tsets the ne"
    "xt program's loading address. When no address is\n\t\t\tspecified, opti"
    "mize the addresses so that processes are as far\n\t\t\taway from each o"
    "ther as possible. The addresses are MEM_SIZE modulo\n", 1);
}

void vm_machine(void)
{

}

char **hex_parsing(char *name)
{
    FILE *file;
    char **buffer = malloc(sizeof(char *) * 10000);
    char *tmp = malloc(sizeof(char));
    int lgt = 0;

    file = fopen(name, "r+");
    if (file == NULL)
        return (NULL);
    for (; 1; lgt++) {
        buffer[lgt] = malloc(sizeof(char) * 1);
        if (fread(tmp, 1, 1, file) == 0)
            break;
        buffer[lgt][0] = tmp[0];
    }
    buffer += PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
    for (int i = 0; i < lgt - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16); i++)
        buffer[i] = my_getnbr_base((int)buffer[i][0], "0123456789abcdef");
    return (buffer);
}

int main(int ac, char **av)
{
    char **stock;

    if (ac == 2 && str_compare("-h", av[1]))
        return (dash_h(av));
    else if (ac == 2)
        stock = hex_parsing(av[1]);
    return (0);
}