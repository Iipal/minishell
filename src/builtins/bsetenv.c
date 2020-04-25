/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/25 21:33:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_builtin_status	bsetenv(const struct s_command *restrict cmd)
{
	char	*value;

	if (1 == cmd->argc)
		benv(cmd);
	else
	{
		value = ((3 == cmd->argc) ? cmd->argv[2] : "");
		if (-1 == setenv(cmd->argv[1], value, 1))
		{
			ft_dprintf(STDERR_FILENO,
				"setenv: failed to setenv '$%s' with value '%s'.\n",
				cmd->argv[1], value);
			return (e_bstatus_invalid);
		}
	}
	return (e_bstatus_valid);
}
