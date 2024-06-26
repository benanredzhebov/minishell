/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_for_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:10:51 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/24 21:29:45 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokenise_for_tree(t_token *t_parenth, t_data *data)
{
	t_tokenise_tree	vars;

	initialize_vars(&vars, t_parenth);
	if (handle_lexical_analysis(&vars))
		return (1);
	find_tail(&vars);
	handle_atach_left(&vars, data);
	handle_atach_right(&vars);
	return (0);
}

t_data	*init_temp_data(void)
{
	t_data	*temp_data;

	temp_data = malloc(sizeof(t_data));
	temp_data->token_list = NULL;
	temp_data->tree = NULL;
	temp_data->env_list = NULL;
	temp_data->sorted_env_list = NULL;
	temp_data->input_line = NULL;
	temp_data->input_minishell = NULL;
	temp_data->curr_dir = NULL;
	temp_data->exit_str = NULL;
	return (temp_data);
}

t_token	*copy_tokens(t_token *head)
{
	t_token	*tmp;
	t_token	*new_head;
	t_token	*new_tmp;

	tmp = head;
	new_head = NULL;
	while (tmp)
	{
		new_tmp = malloc(sizeof(t_token));
		if (!new_tmp)
		{
			free_tokens(&new_head, free);
			return (NULL);
		}
		new_tmp->type = tmp->type;
		if (tmp->word)
			new_tmp->word = ft_strdup(tmp->word);
		new_tmp->next = NULL;
		new_tmp->prev = NULL;
		add_token(&new_head, new_tmp);
		tmp = tmp->next;
	}
	return (new_head);
}
