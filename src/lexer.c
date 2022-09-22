/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:22:08 by mbatstra          #+#    #+#             */
/*   Updated: 2022/09/22 17:44:12 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "libft.h"

void	identify_token(t_token *token)
{
	if (!(ft_strncmp("ls", token->value, 2)))
		return ;
//		printf("matched\n");
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
  this function takes the input string (cmd_line) and splits it up into a (linked) list of tokens

  finite state machine
  begin bij het eerste karakter
  if '\"' --> state "
  else if '\'' --> state '
  else ' ' --> state ' '
  else state is letters

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

	int		i;
	i = 0;

	while (cmd_line[i])
	{
		if (cmd_line[i] == ' ')
		{
			printf("1\n");
		}
		else if (cmd_line[i] == '\'')
		{
			printf("2\n");
		}
		else if (cmd_line[i] == '\"')
		{
			printf("3\n");
		}
		else
		{
			printf("4\n");
		}
		i++;
	}
	return (0);
	token = tokenize("word");
	list = ft_lstnew(token);
	ft_lstadd_back(tokens, list);
//	spl_line = ft_split(cmd_line, ' ');


//	if (spl_line == NULL)
//		return (1);


	/* while (spl_line[i] != NULL) */
	/* { */



	/* 	printf("tokens: %s\n", ((t_token *)(list->content))->value); */


	/* 	if (list == NULL) */
	/* 	{ */
	/* 		ft_lstclear(tokens, &free); */
	/* 		return (1); */
	/* 	} */

	/* 	i++; */
	/* } */
	/* return (0); */



}
