/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhelp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/25 21:32:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_builtin_status	bhelp(const struct s_command *restrict cmd)
{
	(void)cmd;
	ft_putendl("Builtins help:\n"
		"\techo    \tdisplay a line of text\n"
		"\tcd      \tchange the current directory\n"
		"\tsetenv  \tadd the variable to the environment\n"
		"\tunsetenv\tdelete the variable from the environment\n"
		"\tenv     \trun a program in modified environment\n"
		"\texit    \texit the shell\n"
		"\thelp    \tprint this info message");
	return (e_bstatus_valid);
}
