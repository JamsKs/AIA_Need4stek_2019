##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC     =	src/main.c

OBJ     =       $(SRC:.c=.o)

RM      =       rm -f

NAME    =	ai

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) -g3 $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
