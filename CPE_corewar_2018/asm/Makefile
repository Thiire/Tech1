##
## EPITECH PROJECT, 2019
## CPE_corewar_2018
## File description:
## Makefile
##

SRC	=	main.c					\
		../lib/my_putstr.c		\
		../lib/my_strlen.c		\
		../lib/my_putchar.c		\
		../lib/my_putnbr_base.c	\
		../lib/user.c			\
		../lib/strcompare.c		\
		../lib/my_getnbr.c		\
		../lib/get_next_line.c	\
		../lib/my_strcmp.c		\
		../lib/my_revbit.c		\
		asming.c				\
		files_set.c				\
		not_header.c			\
		instru1.c				\
		instru2.c				\
		instru3.c				\
		tools.c					\

CC	=	gcc -g3

NAME	=	asm

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all