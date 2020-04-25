/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   becho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/25 21:20:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void		becho_help_message(void)
{
	ft_putendl("Usage: echo [SHORT-OPTION]... [STRING]...\n"
		"  or : echo LONG-OPTION\n"
		"Echo the STRING(s) to standard output.\n"
		"\t-n    \tdo not output the trailing newline\n"
		"\t--help\tdisplay this help and exit");
}

enum e_builtin_status	becho(const struct s_command *restrict cmd)
{
	bool	is_trail_newline = true;
	size_t	i = 0;

	if (2 == cmd->argc && !strcmp("--help", cmd->argv[1]))
	{
		becho_help_message();
		return (e_bstatus_valid);
	}
	if (2 <= cmd->argc && !strcmp("-n", cmd->argv[1]))
	{
		is_trail_newline = false;
		i = 1;
	}
	while (cmd->argc > ++i)
	{
		ft_putstr(cmd->argv[i]);
		if (i + 1 != cmd->argc)
			ft_putchar(' ');
	}
	if (is_trail_newline)
		ft_putchar('\n');
	return (e_bstatus_valid);
}
