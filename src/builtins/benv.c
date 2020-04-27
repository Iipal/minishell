/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 20:11:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_builtin_status	benv(const struct s_command *restrict cmd)
{
	size_t				i;
	struct s_command	c;

	i = ~0UL;
	if (1 == cmd->argc)
	{
		while (cmd->argc > ++i)
			ft_putendl(g_environ[i]);
	}
	else
	{
		c.argc = cmd->argc - 1;
		MSH_ASSERT(c.argv = ft_memalloc(sizeof(*c.argv) * c.argc));
		while (c.argc > ++i)
			c.argv[i] = cmd->argv[i + 1];
		command_run(&c);
		free(c.argv);
	}
	return (e_bstatus_valid);
}
