##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## number 1
##

RULE =	all

NAME = make

MAKELIB = make

all: $(NAME)

$(NAME):
		$(MAKELIB) -C ./generator
		$(MAKELIB) -C ./solver

clean:
		$(MAKELIB) clean -C ./generator
		$(MAKELIB) clean -C ./solver

fclean: clean
		$(MAKELIB) fclean -C ./generator
		$(MAKELIB) fclean -C ./solver

re: fclean all
