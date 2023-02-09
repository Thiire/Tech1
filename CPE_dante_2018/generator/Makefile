##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## number 1
##

NAME =	generator

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

CC =	gcc

CFLAGS = -Wall -W -Wextra -O3

RM =	rm -f

RULE =	all

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
