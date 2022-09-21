/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 15:29:05 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/09/20 15:31:00 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEXER_H
# define LEXER_H

int	lexer(t_list **tokens, char *cmd_line);
t_token	*tokenize(const char *str_token);

#endif
