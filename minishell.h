/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:32:54 by oruban            #+#    #+#             */
/*   Updated: 2024/05/24 10:28:23 by beredzhe         ###   ########.fr       */
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
	int			s_quote;
	int			d_quote;
	int			forked;

	char		*input_minishell;
	char		**root_directory;
	
}				t_data;

typedef struct s_env
{
	char			*var_name;
	char			*var_value;
	int				visible;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

/*Loop into the minishell program*/
void	minish_loop(t_data *data);

/*freearr - free memory*/
void	free_2darray(char **array);

/*token_tree.c*/
//t_data *init_temp_data(void);

/*init_data.c*/
void	init_data(t_data **data, char **envp);

/*signal.c*/
int	handle_d(t_data *data, char *input);

/*free.c*/
void	free_data(t_data *data);

/*exit.c*/
void	exit_shell(char *message, int exit_code, t_data *data);

/*quote_checker*/
int	has_unclosed_quotes(char *str);

#endif