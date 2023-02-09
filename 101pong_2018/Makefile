##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

FIND = $(shell find -name "*.c")

OBJS = $(FIND:.c=.o)

TEMP = $(shell find -name "*.gc*" -name "*.o" -name "*~" -name "#*#")

FLAGS = -lm

NAME = make

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o 101pong $(FLAGS)
 
clean:
	rm $(OBJS)

fclean:
	rm -rf $(OBJS) 101pong

re:
	fclean
	all

.PHONY: clean fclean all re
