/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:29:53 by oruban            #+#    #+#             */
/*   Updated: 2024/05/15 09:04:36 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf
#include <unistd.h> // getcwd execve
#include <readline/readline.h> // readline
#include <readline/history.h> // add_history

#include <stdlib.h> // EXIT_FAILURE

int main(int argc, char **argv, char **envp)
{
	if (argv && argc != 1)
	{
		ft_printf("Usage: minishell\n", 2);
		return (EXIT_FAILURE);
	}
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
	printf("\n");
	printf("%s\n", getcwd(NULL, 0));
	printf("\n");
	printf("%s\n", readline("prompt: "));
	printf("\n");
}
