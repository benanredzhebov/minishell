/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:54 by beredzhe          #+#    #+#             */
/*   Updated: 2024/06/20 14:24:48 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*scans the input command line for specific tokens and checks
for syntax errors related to these tokens*/
int	syntax_errors(t_token *token, t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	while (token)
	{
		str = check_first_token(&data->input_line[i], &i);
		printf("The first string is %s\n", str);
		if (str == NULL)
			return (0);
		while (token->type == T_WORD || token->type == T_SPACE)
			token = token->next;
		if (check_and(token, str))
			return (1);
		if (check_red(token, str)){
			printf("Debug: The red String is: %s\n", str);
			return (1);
		}	
		if (check_pipe_or(token)){
			printf("Debug: The pipe_or String is: %s\n", str);
			return (1);
		}
		token = token->next;
	}
	return (0);
}

/*identify and handle various tokens, whic are crucial for
correctly interpteting and executing user commands*/
char	*check_first_half(char *str, int *i)
{
	if (*str == '|' && *(str + 1) == '|')
		return (*i += 2, "||");
	if (*str == '|')
		return (*i += 1, "|");
	if (*str == '<' && *(str + 1) == '>')
		return (*i += 2, "<>");
	if (*str == '<' && *(str + 1) == '<' && *(str + 2) == '<'
		&& *(str + 3) != '>')
		return (*i += 3, "<<<");
	if ((*str == '>' && *(str + 1) == '>' && *(str + 2) == '>'))
		return (*i += 3, ">>>");
	if (*str == '>' && *(str + 1) == '>')
		return (*i += 2, ">>");
	return (NULL);
}

char	*check_second_half(char *str, int *i)
{
	if (*str == '>')
		return (*i += 1, ">");
	if (*str == '<' && *(str + 1) == '<' && *(str + 2) != '>')
		return (*i += 2, "<<");
	if (*str == '<'){
		printf("Have to check this %c\n", *str);
		return (*i += 1, "<");
	}
	if (*str == '&' && *(str + 1) == '&')
		return (*i += 2, "&&");
	if (*str == '&')
		return (*i += 1, "&");
	return (NULL);
}

char	*check_first_token(char *str, int *i)
{
	char	*result;

	while (*str)
	{
		result = check_first_half(str, i);
		if (result != NULL){
			printf("The result 1 is %s\n", result);
			return (result);
		}
		result = check_second_half(str, i);
		if (result != NULL){
			printf("The result 2 is %s\n", result);
			return (result);
		}
		printf("Result is: %s\n", result);
		str++;
		(*i)++;
		printf("Result is: %s\n", result);
	}
	return (NULL);
}

/*check for syntax errors related to the & and && tokens 
"echo &>", &&&&*/
int	check_and(t_token *token, char *str)
{
	if (!ft_strcmp(str, "&"))
	{
		if (token->next->type == T_REDIR_OUTPUT
			&& token->next->next->type == T_SPACE)
			if (check_red_general(token->next->next))
				return (1);
		if (token->next->type == T_REDIR_OUTPUT)
			if (check_red_general(token->next))
				return (1);
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `&'"), 1);
	}
	if (!ft_strcmp(str, "&&"))
		if ((token->prev != NULL && token->prev->type == T_AND
				&& token->type == T_AND) || (token->next != NULL
				&& token->next->type == T_AND && token->type == T_AND)
				|| (token != NULL && token->type == T_AND))
			return (printf("minishell: syntax error near %s\n",
					"unexpected token `&&'"), 1);
	return (0);
}
