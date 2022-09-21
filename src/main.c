/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatstra <mbatstra@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:30:39 by mbatstra          #+#    #+#             */
/*   Updated: 2022/09/21 12:49:18 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "minishell.h"
#include "lexer.h"

int	main()
{
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
	return (0);
}
