/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:29:53 by oruban            #+#    #+#             */
/*   Updated: 2024/05/23 12:03:27 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[]) 
{
	t_data	*data;
	char	**env;
	
	(void)argc;
	(void)argv;
	(void)envp; // I will initialize it later
	
	data = NULL;
	env = NULL;
	
	init_data((&data), envp);
	minish_loop(data);
	return (0);
}

// int	main()
// {
// 	char	*input;

// 	while (1)
// 	{
// 		input = readline("minishell$ ");
// 		if (!input)
// 			break;
// 		if (*input)
// 			add_history(input);
// 		printf("Input: %s\n", input);
// 		free(input);
// 	}
// 	return 0;
// }