/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** files_set
*/

#include "../includes/corewar.h"

void aff_err(void)
{
    my_put_err("Error on Name / Comment\n");
    exit(84);
}

int setting_name(char *name, header_t *header)
{
    int index = 0;
    int i = 1;

    for (; name[i] != '\0' && name[i - 1] != '"'; i++);
    for (; name[i] != '\0' && name[i] != '"' &&
    index < PROG_NAME_LENGTH + 1; i++, index++)
        header->prog_name[index] = name[i];
    if (name[i] == '\0' || index == PROG_NAME_LENGTH + 1)
        return (1);
    for (int k = index; k < PROG_NAME_LENGTH + 1; k++)
        header->prog_name[k] = '\0';
    return (0);
}

int setting_comment(char *comment, header_t *header)
{
    int index = 0;
    int i = 1;

    for (; comment[i] != '\0' && comment[i - 1] != '"'; i++);
    for (; comment[i] != '\0' && comment[i] != '"' &&
    index < COMMENT_LENGTH + 1; i++, index++) {
        header->comment[index] = comment[i];
    }
    if (comment[i] == '\0' || index == COMMENT_LENGTH + 1)
        return (1);
    for (int k = index; k < COMMENT_LENGTH + 1; k++)
        header->comment[k] = '\0';
    return (0);
}

int display_header(header_t *header, char *name_cor)
{
    int fd = open(name_cor, O_WRONLY);
    union reverse reversing;

    reversing.number = header->magic;
    my_revbit(reversing.letter);
    header->magic = reversing.number;
    write(fd, header, sizeof(header_t));
    return (fd);
}