##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME =	navy

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

CC =	gcc

CFLAGS =	-g3

RM =	rm -f

MAKELIB =	make

CLEANLIB =	clean

LIBFLAGS =	-C

LIBPATH =	./include

INCLUDELIB =	-Linclude -lmy

RULE =	all

all:	$(NAME)

$(NAME):	$(OBJ)
			$(MAKELIB) $(LIBFLAGS) $(LIBPATH)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDELIB)

clean:
		$(RM) $(OBJ)
		$(MAKELIB) $(CLEANLIB) $(LIBFLAGS) $(LIBPATH)

fclean:	clean
		$(RM) $(NAME)

re: fclean all
