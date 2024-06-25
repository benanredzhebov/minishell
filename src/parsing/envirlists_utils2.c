/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirlists_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:54:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/25 11:49:02 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envir	*ft_envnew(void)
{
	t_envir	*head;

	head = malloc(sizeof(t_envir));
	if (!head)
		return (NULL);
	head->var_name = NULL;
	head->var_value = NULL;
	head->visible = 0;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
