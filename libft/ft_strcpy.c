/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:25:20 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/18 12:12:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcpy(char *dest, const char *src)
{
	char	*original_dest = dest;

	if (!src || !dest)
		return NULL;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return original_dest;
}
