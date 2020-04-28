/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsetenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/28 19:53:09 by tmaluh           ###   ########.fr       */
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
			ft_putstr_fd("setenv: failed to setenv '%d", STDERR_FILENO);
			ft_putstr_fd(cmd->argv[1], STDERR_FILENO);
			ft_putstr_fd("' with value '", STDERR_FILENO);
			ft_putstr_fd(value, STDERR_FILENO);
			ft_putstr_fd("'.\n", STDERR_FILENO);
			return (e_bstatus_invalid);
		}
	}
	return (e_bstatus_valid);
}
