##
## EPITECH PROJECT, 2018
## makefile
## File description:
## day10 task01
##

NAME =	libmy.a

SRC =	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_putnbr_base.c \
	my_putnbr_base_un.c \
	function.c \
	function2.c \
	usefull_printf.c \
	my_strlen.c \
	function3.c \
	my_putstr_s.c \
	my_putnbr_base_l.c \

CFLAGS = -W -Wall -Wextra -Werror

OBJ =	$(SRC:.c=.o)

LIBCOMP =	ar rc

GCC =	gcc

RMO =	rm -vf

NAME2 =	my.h

all: $(NAME)

$(NAME):	$(OBJ)
		$(LIBCOMP) $(NAME) $(OBJ)

clean:
		$(RMO) $(OBJ)

fclean: clean
		$(RMO) $(NAME)

re: fclean all
