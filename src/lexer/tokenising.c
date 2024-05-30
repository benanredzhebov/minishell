/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenising.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:18:57 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/30 20:52:24 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*creates new token based on the input string*/
t_token	*create_token(t_data *data, int i)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		exit_shell("Error: memory allocation failed\n", 1, data);
	new->word = ft_substr(data->input_line, i - data->count, data->count);
	new->type = T_WORD;
	data->count = 0;
	return (new);
	printf("new->word: %s\n", new->word);
}

/*creates new token based on the provided word and type*/
t_token	*create_arg_token(t_data *data, char *word, enum e_token_type type)
{
	t_token	*new;
	
	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		exit_shell("Error: memory allocation failed\n", 1, data);
	new->word = ft_strdup(word);
	new->type = type;
	return (new);
	printf("new->wordarg_tok: %s\n", new->word);
}
