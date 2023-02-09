##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

SRCS = 	$(wildcard src/*.c)	\
		$(wildcard lib/*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -g3 -ggdb -lncurses

NAME = tetris

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
