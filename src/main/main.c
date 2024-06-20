/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:29:53 by oruban            #+#    #+#             */
/*   Updated: 2024/06/19 11:36:42 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t g_child_pid = 0;

int	main(int argc, char *argv[], char *envp[]) 
{
	t_data	*data;
	char	**env;
	
	(void)argc;
	(void)argv;
	
	data = NULL;
	env = NULL;
	if (!*envp)
	{
		env = create_envp();
		init_data(&(data), envp);
	}
	else
		init_data(&(data), envp);
	handle_signal();
	minishell_loop(data);
	if (env)
		free_2darray(env);
	free_data(data);
	return (0);
}

/*prepare an environment for a new process*/
char	**create_envp(void)
{
	char	**envp;
	char	cwd[PATH_MAX];

	envp = malloc(sizeof(char *) * 4);
	if (!envp)
	{
		perror("malloc");
		exit(1);
	}
	envp[0] = ft_strdup("SHLVL=1");
	envp[1] = ft_strdup("PATH=/bin/");
	if (!envp[0] || !envp[1])
	{
		ft_putstr_fd("Memory allocation error\n", 2);
		free_2darray(envp);
		exit(1);
	}
	if (getcwd(cwd, sizeof(cwd)))
	{
		envp[2] = ft_strjoin("PWD=", cwd);
		if (!envp[2])
		{
			ft_putstr_fd("Memory allocation error\n", 2);
			free_2darray(envp);
			exit(1);
		}
	}
	else
	{
		perror("getcwd");
		free_2darray(envp);
		exit(1);
	}
	envp[3] = NULL;
	return (envp);
}
