/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** tools2
*/

#include "../includes/corewar.h"

char *cni(int number)
{
    char *array;
    int i = 0;

    for (int tmp = number; tmp != 0; i++, tmp /= 10);
    array = malloc(sizeof(char) * (i + 3));
    if (number <= 0)
        return ("0");
    if (number <= 9) {
        array[0] = number + 48;
        array[1] = '\0';
        return (array);
    }
    array[i] = '\0';
    array[0] = '0';
    for (; i != 0; i--, number /= 10)
        array[i - 1] = number % 10 + 48;
    return (array);
}

char *my_revstr(char *str)
{
    char stock;
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++);
    i--;
    for (j = 0; j < i / 2 + 1; j++) {
        stock = str[j];
        str[j] = str[i - j];
        str[i - j] = stock;
    }
    return (str);
}

char *trade(long nbr, char *base)
{
    char *number = malloc(sizeof(char) * 100);
    int	x = 0;
    int i;
    int	diff = 0;
    int high = my_strlen(base);

    for (i = 0; nbr != 0; i++) {
        diff = nbr % high;
        nbr = nbr / high;
        for (x = 0; x < diff; x++);
        if (diff != 0)
            number[i] = base[x];
        else if (diff == 0)
            number[i] = base[0];
    }
    number[i] = '\0';
    return (my_revstr(number));
}

char *nega(long nbr)
{
    char *nombre = cni(11111111);
    char *result = trade(nbr - 1, "01");
    char *zero = malloc(sizeof(char) * 9);

    zero[0] = '0';
    zero[1] = '0';
    zero[2] = '0';
    zero[3] = '0';
    zero[4] = '0';
    zero[5] = '0';
    zero[6] = '0';
    zero[7] = '0';
    zero[8] = '\0';
    result = summ_calc(nombre, summ_calc(zero, result, 1), 2);
    result = bin_hex(result);
    return (result);
}

char *my_getnbr_base(long nbr, char *base)
{
    if (nbr == 0)
        return ("0");
    if (nbr < 0)
        return (nega(nbr * -1));
    else
        return (trade(nbr, base));
    return (0);
}