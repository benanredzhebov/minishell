/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:32:56 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/20 10:39:10 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_parenthesis(char *str, int *parenCount, int *parenth_total)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '(' && !in_quotes(str, i))
		{
			(*parenth_total)++;
			(*parenCount)++;
		}
		else if (str[i] == ')' && !in_quotes(str, i))
		{
			(*parenCount)--;
			(*parenth_total)++;
		}
		i++;
	}
	return (i);
}

int	check_parenthesis(int parenCount, int parenth_total)
{
	if (parenth_total > 0)
	{
		if (parenCount == 0)
			return (1);
		else
			return (printf("minishell: we don't have to handle unclose %s\n", \
			"parenthesis"), 2);
	}
	return (0);
}

int	find_parenthesis(char *str)
{
	int	paren_count;
	int	parenth_total;

	paren_count = 0;
	parenth_total = 0;
	count_parenthesis(str, &paren_count, &parenth_total);
	return (check_parenthesis(paren_count, parenth_total));
}