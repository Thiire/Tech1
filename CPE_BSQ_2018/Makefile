##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

FIND = $(shell find lib/my/ -name "*.c" )

OBJS = $(FIND:.c=.o)

TEMP = $(shell find lib/my/ -name "*.gc*" -name "*.o" -name "*~" -name "#*#" )

FLAG = -Include -Llib -lmy -g

NAME = make

all: $(NAME)

$(NAME):$(OBJS)
	ar rc lib/libmy.a $(OBJS)
	$(CC) bsq.c display.c $(OBJS) $(FLAG) -o bsq

clean:
	rm $(OBJS)

fclean:
	rm -rf $(OBJS) lib/libmy.a bsq

re:
	fclean
	all

.PHONY: clean fclean all re
