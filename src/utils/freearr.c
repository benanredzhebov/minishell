/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freearr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/05/21 12:39:09 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2darray(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while ((*array)[i++])
		ft_memdel((void **)&array[i]);
	free(array);
}
