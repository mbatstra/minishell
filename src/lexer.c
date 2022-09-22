/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:22:08 by mbatstra          #+#    #+#             */
/*   Updated: 2022/09/21 20:44:05 by dvan-kri      ########   odam.nl         */
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


int	lexical_analyzer(t_list **tokens, char *cmd_line)
{
/*
  what does the function do?
  this function takes the input string (cmd_line) and splits it up into a (linked) list of tokens
 */



	t_list	*list;


	/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
	*/




	t_token *token;




/*
typedef struct s_token {
	enum e_types	type;
	char			*value;
}			t_token;
*/




	char	**spl_line;

	int		i;
	i = 0;


	spl_line = ft_split(cmd_line, ' ');


	if (spl_line == NULL)
		return (1);


	list = spl_line[i];


	while (spl_line[i] != NULL)
	{
		token = tokenize(spl_line[i]);
		list = ft_lstnew(token);/* hier verder */
/* die token wordt aan die lijst geplakt. maar moeten we niet een pointer behouden naar het eerste element in de lijst? */
		if (list == NULL)
		{
			ft_lstclear(&list, &free);
			return (1);
		}
		ft_lstadd_back(tokens, list);
		i++;
	}
	return (0);



}
