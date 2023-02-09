##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

FLAG = -lncurses

NAME = make

$(NAME):
	$(CC) my_sorter.c my_sorter_bis.c my_sorter_prim.c $(FLAG) -o push_swap

fclean:
	rm -rf push_swap

re:
	fclean
	all

.PHONY: clean fclean all re
