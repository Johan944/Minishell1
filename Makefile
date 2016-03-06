##
## Makefile for  in /home/ganem-_j/rendu/PSU_2015_minishell1
##
## Made by johan ganem--brunet
## Login   <ganem-_j@epitech.net>
##
## Started on  Sat Jan 23 23:04:18 2016 johan ganem--brunet
## Last update Sun Jan 24 20:44:09 2016 johan ganem--brunet
##

SRCS		=		functions.c \
				my_cd.c \
				main.c \
				my_tablen.c \
				builtins.c \
				functions_error.c \
				my_exec.c \
				my_unsetenv.c \
				disp_env.c \
				get_next_line.c \
				minishell.c \
				my_setenv.c \
				error.c \
				my_str_do_wordtab.c \
				search.c \
				get_prompt.c \
				my_atoi.c \
				my_strncmp.c \
				my_exit.c \

NAME		=		mysh

OBJ		=		$(SRC:.c=.o)


all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
