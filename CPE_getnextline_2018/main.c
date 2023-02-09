#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int of = open("test", O_RDONLY);
    char *str;
    while (str = get_next_line(of))
    {
        puts(str);
        free(str);
    }
    return (0);
}