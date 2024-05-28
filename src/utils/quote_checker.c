/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:30:58 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/25 12:40:31 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int has_unclosed_quotes(char *str)
{
	char last_opened;
	
	last_opened = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			if (last_opened == 0)
				last_opened = *str;
			else if (last_opened == *str)
				last_opened = 0;
		}
		str++;
	}
	if (last_opened != 0)
	{
		ft_putstr_fd("Close the quote!\n", STDERR_FILENO);
		return 1;
	}
	return 0;
}

/*Check_d_quote is used to find a closing double quote
in a string starting from a given position and to determine if a
specified position lies within those double quotes. The function
updates the index *i to the position of the closing double quote
(or end of the string) and returns an indicator of whether the
position is within the quotes or if a closing quote was found.*/
int	check_d_quote(char *s, int *i, int pos)
{
	int	d_quote;
	int	j;

	j = *i + 1;
	d_quote = 1;
	while (s[j])
	{
		if (s[j] == '\"')
		{
			d_quote = 0;
			if (pos > *i && pos < j)
				return (2);
			else
				break;
		}
		else
			j++;
	}
	*i = j;
	return (d_quote);
}

int	check_s_quote(char *s, int *i, int pos)
{
	int	s_quote;
	int	j;

	j = *i + 1;
	s_quote = 1;
	while (s[j])
	{
		if (s[j] == '\"')
		{
			s_quote = 0;
			if (pos > *i && pos < j)
				return (1);
			else
				break;
		}
		else
			j++;
	}
	*i = j;
	return (s_quote);
}

/*Checks if a specific position in a string is within a quoted section*/
int	in_quotes(char *s, int pos)
{
	int	i;
	int	result;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			if (s[i] == '\"')
			{
				result = check_d_quote(s, &i, pos);
				if (result != 0)
					return (result);
			}
			else if (s[i] == '\'')
			{
				result = check_s_quote(s, &i, pos);
				if (result != 0)
					return (result);
			}
		}
		i++;
	}
	return (0);
}
