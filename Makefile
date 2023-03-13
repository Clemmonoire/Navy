##
## EPITECH PROJECT, 2022
## B-MUL-100-LYN-1-1-myradar-clement.monnoire
## File description:
## Makefile
##

SRC			= 	$(addprefix $(DIRECTORY), $(SRC_FILE))

DIRECTORY 		= 	src/

SRC_FILE = my_navy.c \
	signal.c \
	my_putstr.c \
	get_nbr.c \
	create_map.c \
	attack.c \
	players.c \
	error.c

OBJ	=	$(SRC:.c=.o)

FLAG = -O3

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(FLAG)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
