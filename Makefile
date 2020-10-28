##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Project compilation file
##

NAME	=	infin_add

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Werror -Wextra -Wpedantic

SRC	=	InfinAdd.c\
		src/libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
