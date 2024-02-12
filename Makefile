##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC	=	src/main.c
SRC	+=	src/minishell.c

OBJ = $(SRC:.c=.o)

NAME = my_sh

CC = gcc -g

CFLAGS	=	-I include
CFLAGS	+=	-W -Wall -Wextra -Wpedantic

LIB	=	-L lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/my
	@make clean -C lib/my
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	@rm -f $(OBJ)
	@find . -name "*~" -delete

fclean: clean
	@rm -f $(NAME)
	@make fclean -C lib/my

re: fclean all

.PHONY:	all clean fclean re
