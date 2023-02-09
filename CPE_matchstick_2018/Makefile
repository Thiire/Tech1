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

NAME = matchstick

MAKELIB = make

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKELIB) -C ./include
	$(CC) -o $@ $^ -Linclude -lmy

clean:
	rm -rf $(OBJS)
	$(MAKELIB) clean -C ./include

fclean: clean
	rm -rf $(NAME)
	$(MAKELIB) fclean -C ./include

re: fclean all

.PHONY: clean fclean all re
