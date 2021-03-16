##
## EPITECH PROJECT, 2020
## makefile
## File description:
## bsq
##

NAME	=	my_runner

SRC	=	$(wildcard *.c)

all :	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -o $(NAME) -g $(SRC) -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window -l csfml-network -L./lib -lmy

clean:
	make -C ./lib/my
	rm -f *~
	rm -f *#

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:	fclean all
	make re -C ./lib/my
