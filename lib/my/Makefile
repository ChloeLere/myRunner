##
## EPITECH PROJECT, 2020
## makefile
## File description:
## task01
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAMECP	=	my.h


$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mkdir -p  ../../include
		cp $(NAME) ../
		cp $(NAMECP) ../../include/

clean:
		rm $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re:		fclean $(NAME)
