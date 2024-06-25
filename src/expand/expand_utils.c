/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:11:26 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/24 12:22:49 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*process_squote(char *s, int *i, char *result)
{
	if (s[*i + 1] == '\'')
	{
		(*i)++;
		result = ft_strdup("");
	}
	else
		result = expand_single_quotes(s, i, result);
	return (result);
}

char	*process_dquote(t_data *data, char *s, int *i, char *result)
{
	if (s[*i + 1] == '\"')
	{
		(*i)++;
		result = ft_strdup("");
	}
	else
		result = expand_double_quotes(data, s, i, result);
	return (result);
}

int	has_asterisk(char *str)
{
	while (*str)
	{
		if (*str == '*')
			return (1);
		str++;
	}
	return (0);
}

char	*update_aster_temp(char *temp, char *root_directory_k)
{
	char	*old_temp;

	if (!temp)
		return (ft_strjoin("", root_directory_k));
	else
	{
		old_temp = temp;
		temp = ft_strjoin(temp, " ");
		ft_memdel(&old_temp);
		old_temp = temp;
		temp = ft_strjoin(temp, root_directory_k);
		ft_memdel(&old_temp);
	}
	return (temp);
}

/*checking matches token->word and root directory*/
void	check_matches(t_token *token, char **root_directory)
{
	char	*temp;
	int		k;

	temp = NULL;
	k = -1;
	if (!token || !root_directory)
		return ;
	while (root_directory[++k])
	{
		if (token->word && match_pattern(token->word, root_directory[k]))
			temp = update_aster_temp(temp, root_directory[k]);
	}
	if (temp)
	{
		if (token->word)
			ft_memdel(&token->word);
		token->word = ft_strdup(temp);
		ft_memdel(&temp);
	}
}
