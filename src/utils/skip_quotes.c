/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:42:16 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/16 11:57:38 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Finds the position of the closing quote in a string*/
int	skip_quotes(char *str, char quote)
{
	int	i;

	if (str[0] != quote)
		return (0);
	i = 1;
	while (str[i] != '\0' && str[i] != quote)
		i++;
	if (str[i] == '\0')
		return (0);
	return (i + 1);
}
