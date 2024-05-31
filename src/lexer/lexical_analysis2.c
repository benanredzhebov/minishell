/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:38:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/31 08:53:23 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenise(t_data *data, char *str)
{
	int		i;
	t_token	**head;
	
	i = 0;
	head = &data->token_list;
	data->count = 0;
	while (str[i])
	{
		printf("At start of loop, position: %d, character: %c\n", i, str[i]);
		if (!find_token(data, str, &i, head))
			continue;
		data->count++;
		if (find_token2(i, str, "|") || find_token2(i, str, ">")
			|| find_token2(i, str, "<") || find_token2(i, str, "&"))
		{
			printf("Before adding token, position: %d, character: %c\n", i, str[i]);
			add_token(head, create_token(data, i + 1));
			printf("Before adding token, position: %d, character: %c\n", i, str[i]);
		}
		i++;
	}
	if (i > 0)
	{
		printf("Before adding final tokens, position: %d\n", i);
		add_token(head, create_token(data, i));
		add_token(head, create_arg_token(data, "newline", T_NEWLINE));
		printf("After adding final tokens, position: %d\n", i);
	}
}
