##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

FLAG = -Iinclude -lm -l csfml-graphics -l csfml-window

NAME = make

$(NAME):
	$(CC) main.c form.c météorite.c pluie_de_ligne.c pluie_de_rond.c rond_grand.c -g $(FLAG) -o my_screensaver

fclean:
	rm -rf my_screensaver

re:
	fclean
	all

.PHONY: clean fclean all re
