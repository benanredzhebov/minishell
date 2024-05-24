/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:55:18 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/24 10:27:29 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minish_loop(t_data *data)
{
	char	*input;
	
	while (1)
	{
		// 1.Here have to write function to reset
		/*to avoid segmentation fault. Delete later*/
		if (data == NULL)
		{
			fprintf(stderr, "Error: data is NULL\n");
			exit(1);
		}
		if (data->input_minishell == NULL)
		{
			fprintf(stderr, "Error: data->input_minishell is NULL\n");
			exit(1);
		}
		input = readline(data->input_minishell);
		if (handle_d(data, input))
			continue;
		if (ft_strlen(input) > 0)
			add_history(input);
		if (has_unclosed_quotes(input))
			continue;
		printf("Input: %s\n", input);
		free(input);
	}
}
