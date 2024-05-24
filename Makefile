NAME	=	minishell
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
LDLIBS	=	-lreadline -lft # This tells the linker to link the Readline library with your program
LDFLAGS	+=	-L./libft
OBJ_DIR	=	obj

# List all source files
SRCS	=	$(wildcard *.c) \
			$(wildcard builtins/*.c) \
			$(wildcard minienv/*.c) \
			$(wildcard utils/*.c) \
			$(wildcard executes/*.c) \
			$(wildcard main/*.c) \
			$(wildcard redirects/*.c) \
			$(wildcard expansions/*.c) \
			$(wildcard syntax/*.c) \
			$(wildcard tokenization/*.c)

# Generate object files names
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_A	=	libft/libft.a
HEADER	=	$(wildcard *.h)
VPATH	=	builtins minienv utils executes src redirects includes expansions \
			syntax
INCLUDE	=	-I ./ -I ./includes

all: $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "removed obj folder"

fclean: clean
	@rm -rf $(NAME)
	@echo "removed executable"

re: fclean all

$(LIBFT_A):
	make --directory=./libft

$(NAME): $(LIBFT_A) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS) $(LDFLAGS)

# Rule to compile each .c file into .o file in the obj directory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

leak: all
	valgrind --suppressions=./local.supp --leak-check=full \
	--show-leak-kinds=all --track-fds=yes --trace-children=yes ./$(NAME)

