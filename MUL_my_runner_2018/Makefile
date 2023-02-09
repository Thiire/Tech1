##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Iinclude -g3 -ggdb

NAME = my_runner

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
