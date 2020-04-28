/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bunsetenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/28 19:54:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_builtin_status	bunsetenv(const struct s_command *restrict cmd)
{
	if (1 == cmd->argc)
		benv(cmd);
	else if (-1 == unsetenv(cmd->argv[1]))
	{

		ft_putstr_fd("unsetenv: failed to remove '$", STDERR_FILENO);
		ft_putstr_fd(cmd->argv[1], STDERR_FILENO);
		ft_putstr_fd("' variable\n", STDERR_FILENO);
		return (e_bstatus_invalid);
	}
	return (e_bstatus_valid);
}
