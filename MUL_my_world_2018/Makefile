##
## EPITECH PROJECT, 2019
## MUL_my_world_2018
## File description:
## Makefile
##

NAME =	my_world

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

CC =	gcc

CFLAGS =	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -g3 -lm

RM =	rm -f

RULE =	all

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re: fclean all