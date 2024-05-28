/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:32:54 by oruban            #+#    #+#             */
/*   Updated: 2024/05/28 14:44:15 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h" // libft
# include <stdio.h> // perror
# include <readline/readline.h> // readline
# include <readline/history.h> // history
# include <stdlib.h> // getenv
# include <unistd.h> // getpwd
# include <sys/wait.h> // waitpid
# include <sys/stat.h> // stat
# include <signal.h> // sigaction
# include <fcntl.h> // open flags

typedef struct s_data
{
	struct s_token	*token_list;
	int				s_quote; /*shell is inside a single quoted string*/
	int				d_quote;
	int				forked; /*manage parent and child process behaviors*/
	int				count; /*count the number of tokens*/

	char			*input_minishell; /*initial input to the shell*/
	char			**root_directory;
	char			*input_line; /*input after being processed*/

}				t_data;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}				t_token;

typedef enum e_token_type
{
	WORD = 1,
	T_NEWLINE, /*\n*/
	T_SPACE, /*' '*/
	T_DOLLAR, /*$*/
	T_AMPER, /*&*/
	T_REDIR_INPUT, /*<*/
	T_REDIR_OUTPUT, /*>*/
	T_THREE_IN, /*<<<*/
	T_THREE_OUT, /*>>>*/
	T_IN_OUT, /*<>*/
	T_APPEND, /*>>*/
	T_PIPE, /*|*/
	T_OR, /*||*/
	T_AND, /*&&*/
	T_DELIMITER,
	T_PARENTHESES
}				t_token_type;

typedef struct s_env
{
	char			*var_name;
	char			*var_value;
	int				visible;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

/*Loop into the minishell program*/
void	minishell_loop(t_data *data);

/*freearr - free memory*/
void	free_2darray(char **array);

/*token_tree.c*/
//t_data *init_temp_data(void);

/*init_data.c*/
void	init_data(t_data **data, char **envp);

/*signal.c*/
int		handle_d(t_data *data, char *input);

/*free.c*/
void	free_data(t_data *data);

/*exit.c*/
void	exit_shell(char *message, int exit_code, t_data *data);

/*quote_checker*/
int		has_unclosed_quotes(char *str);
int		check_d_quote(char *s, int *i, int pos);
int		check_s_quote(char *s, int *i, int pos);
int		in_quotes(char *s, int pos);

/*str_checkers.c*/
char	*trim_input(char *input);
void	process_input(char *input, char *str, int *i, int *j);

/*character_checkers.c*/
int		special_chars(char *str);

#endif