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
	$(CC) menu.c my_popup.c my_cut.c do_the_check.c my_coloring.c game_menu.c menu_bis.c map_editor.c $(FLAG) -o my_sokoban

fclean:
	rm -rf my_sokoban

re:
	fclean
	all

.PHONY: clean fclean all re
