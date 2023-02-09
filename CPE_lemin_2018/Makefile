##
## EPITECH PROJECT, 2019
## CPE_lemin_2018
## File description:
## Makefile
##

NAME	=	lem_in

CFLAGS	+=	-W -Wextra -g -Wall -I./include

SRC	=	$(wildcard lib/*.c)	\
		$(wildcard linkedlist/*.c)	\
		$(wildcard src/*.c)

PRINTF	=	$(wildcard my_printf/src/*.c)	\
			$(wildcard my_printf/lib/*.c)

OBJ	=	$(SRC:.c=.o) $(PRINTF:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

bin: fclean all
	rm -f $(OBJ)

.PHONY : all clean fclean re
