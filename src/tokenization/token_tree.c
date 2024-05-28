/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:26:05 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/23 11:57:52 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data *init_temp_data(void)
{
	t_data *temp_data;

	temp_data = malloc(sizeof(t_data));
	temp_data->input_minishell = NULL;
	return (temp_data);
}