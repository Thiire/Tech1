##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -g3 -ggdb

NAME = my_ls

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Linclude -lmy

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
