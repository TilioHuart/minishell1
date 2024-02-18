##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Write a Makefile that compiles your libmy.
##

SRC = 	my_strlen.c
SRC	+=	my_putstr.c
SRC	+=	my_str_to_word_arr.c
SRC	+=	my_putnbr.c
SRC	+=	my_strdup.c
SRC	+=	my_strcmp.c
SRC	+=	my_strcat.c

CPPFLAGS	=	-I.

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@rm -f *~
	@rm -f *.gcda
	@rm -f *.gcno

fclean:	clean
	@rm -f $(NAME)
	@rm -f *.a

re:	fclean all
