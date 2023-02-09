##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

SRCS = 	main.c \
		tools.c \
		tools2.c \
		tools3.c \
		instruction.c \
		instru1.c \
		instru2.c \
		instru3.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -g3 -ggdb

NAME = corewar

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re