##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

FIND = $(shell find -name "*.c" )

OBJS = $(FIND:.c=.o)

TEMP = $(shell find -name "*.gc*" -name "*.o" -name "*~" -name "#*#" )

NAME = make

all: $(NAME)

$(NAME):$(OBJS)
	ar rc libmy.a $(OBJS)

clean:
	rm $(OBJS)

fclean:
	rm -rf $(OBJS) libmy.a a.out

re:
	fclean
	all

.PHONY: clean fclean all re
