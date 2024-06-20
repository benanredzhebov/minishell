/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:10:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/19 14:44:52 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_loop(t_data *data)
{
	char	*input;
	
	while (1)
	{
		reset_data(data);
		input = readline(data->input_minishell);
		if (handle_d(data, input))
			continue;
		if (ft_strlen(input) > 0)
			add_history(input);
		if (has_unclosed_quotes(input))
			continue;
		data->input_line = trim_input(input);
		ft_memdel(&input);
		if ((special_chars(data->input_line))
			|| (lexical_analysis(data, data->input_line)))
			continue;
		printf("Input proccesed: %s\n", data->input_line); //working trim
		printf("Input: %s\n", input); //standart trim. I free it already
		////////////execute(data);
	}
}
