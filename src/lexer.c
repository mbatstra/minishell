/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:22:08 by mbatstra          #+#    #+#             */
/*   Updated: 2022/09/20 16:57:31 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "libft.h"

void	identify_token(t_token *token)
{
	if (!(ft_strncmp("ls", token->value, 2)))
		printf("matched\n");
}

t_token	*tokenize(const char *str_token)
{
	t_token	*new_token;
	char	*new_value;

	new_token = (t_token *)malloc(sizeof(t_token));
	new_value = ft_strdup(str_token);
	if (new_token == NULL || new_value == NULL)
	{
		free(new_token);
		free(new_value);
		return (NULL);
	}
	new_token->value = new_value;
	// set type
	identify_token(new_token);
	return (new_token);
}

int	lexer(t_list **tokens, char *cmd_line)
{
	t_list	*list_item;
	t_token *token;
	char	**spl_line;
	int		i;

	i = 0;
	spl_line = ft_split(cmd_line, ' ');
	if (spl_line == NULL)
		return (1);
	while (spl_line[i] != NULL)
	{
		token = tokenize(spl_line[i]);
		list_item = ft_lstnew(token);
		if (list_item == NULL)
		{
			ft_lstclear(&list_item, &free);
			return (1);
		}
		ft_lstadd_back(tokens, list_item);
		i++;
	}
	return (0);
}
