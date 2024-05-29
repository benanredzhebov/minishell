/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:32:54 by oruban            #+#    #+#             */
/*   Updated: 2024/05/29 17:49:04 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // EXIT_FAILURE
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
typedef struct s_env
{
	char			*key_pair;
	struct s_env	*next;
}				t_env;