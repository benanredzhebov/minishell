/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:45:42 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/28 14:58:56 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	special_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\\' || str[i] == ';') && !in_quotes(str, i))
		{
			printf("minishell: Not required to interpret `%c'\n", str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

/*Checks if a string is empty or consists only of spaces*/
int	is_empty(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

/*Checks if a string contains the pipe charachter,
considering quotes*/
int	has_pipe(char *str)
{
	char	quote;

	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			quote = *str++;
			while (*str != quote)
				str++;
		}
		if (*str == '|')
			return (1);
		str++;
	}
	return (0);
}

/*Checks if a character is a delimeter commonly found
in command-line arguments*/
int	is_name_delimeter(char c)
{
	if (c == ' ' || c == '>' || c == '<' || c == '|' || c == '\t')
		return (1);
	return (0);
}
