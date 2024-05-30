/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:35:23 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/30 09:36:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexical_analysis(t_data *data, char *input)
{
	if (!input || !input[0])
		return (1);
	tokenise(data, input);
	printf("data->count: %d\n", data->count);
// 	if (set_token_type(data))
// 		return (1);
	return (0);
}

