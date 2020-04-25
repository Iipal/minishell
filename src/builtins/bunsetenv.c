/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bunsetenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/25 21:33:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_builtin_status	bunsetenv(const struct s_command *restrict cmd)
{
	if (1 == cmd->argc)
		benv(cmd);
	else if (-1 == unsetenv(cmd->argv[1]))
	{
		ft_dprintf(STDERR_FILENO,
			"unsetenv: failed to remove '$%s' variable\n",
			cmd->argv[1]);
		return (e_bstatus_invalid);
	}
	return (e_bstatus_valid);
}
