##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC	=	src/main_functions/main.c
SRC	+=	src/main_functions/minishell.c
SRC	+=	src/display/display_functions.c
SRC	+=	src/main_functions/recup_function.c
SRC	+=	src/builtins/builtin.c
SRC	+=	src/builtins/cd_function.c
SRC	+=	src/builtins/environment/env_function.c
SRC	+=	src/builtins/environment/setenv_function.c
SRC	+=	src/builtins/environment/unsetenv_function.c
SRC	+=	src/memory_management/washing_machine.c
SRC	+=	src/environment/copy_env.c
SRC	+=	src/path_functions/use_functions.c
SRC	+=	src/path_functions/which_function.c

OBJ = $(SRC:.c=.o)

NAME = mysh

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
