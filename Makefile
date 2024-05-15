CC = cc
NAME = minishell
FLAGS = -Wall -Wextra -Werror
SOURCES = main.c

	$(CC) $(FLAGS) -o $(NAME) $(SOURCES)
all:
	$(NAME)
clean:

fclean:

re:
