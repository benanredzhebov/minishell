CC		= cc
FLAGS	= -Wall -Wextra -Werror -g -O3
NAME	= minishell
SRCS	= main.c	\
		  parser.c	
		  
OBJS	= $(SRCS:.c=.o)
LIBFT	= ./libft/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make -C ./libft $@

fclean:
	rm -f $(OBJS) $(NAME)
	make -C ./libft $@

re:	fclean all

$(LIBFT):
	make -C ./libft
