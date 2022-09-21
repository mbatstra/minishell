/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:30:39 by mbatstra          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/20 20:29:37 by mbatstra         ###   ########.fr       */
=======
/*   Updated: 2022/09/20 16:05:47 by dvan-kri      ########   odam.nl         */
>>>>>>> c094c2470f179dc19bafc1ca2c67dfb4b020a787
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "minishell.h"
<<<<<<< HEAD
#include "libft.h"

void	db_ptlist(t_list **lst)
{
	t_list	*node;

	node = *lst;
	while (node != NULL)
	{
		printf("%s\n", node->content);
		node = node->next;
	}
}
=======
#include "lexer.h"
>>>>>>> c094c2470f179dc19bafc1ca2c67dfb4b020a787

int	main()
{
<<<<<<< HEAD
	t_list	*new_env;

	(void) argc;
	(void) argv;
	env_init(envp, &new_env);
	builtin_export(&new_env, "TEST=test");
	builtin_env(new_env);
	printf("\n-----\n");
	builtin_export(&new_env, "TEST=haha=haha");
	builtin_unset(&new_env, "SHELL");
	builtin_env(new_env);
	system("leaks -q minishell");
=======
	t_list	*token_list;
	char	*input;

	token_list = NULL;
	while (1)
	{
		input = readline("minishell-$ ");
		if (input == NULL)
			return (1);
		if (input[0] != '\0')
		{
			add_history(input);
			lexer(&token_list, input);
		}
	}

>>>>>>> c094c2470f179dc19bafc1ca2c67dfb4b020a787
	return (0);
}
