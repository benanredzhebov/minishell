/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:04:10 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/21 12:40:19 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_data(t_data *data)
{
	data->s_quote = 0;
	data->d_quote = 0;
	data->forked = 0;
	if (data->root_directory && *data->root_directory)
		free_2darray(data->root_directory);
}