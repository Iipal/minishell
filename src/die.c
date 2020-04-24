/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:11:53 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/24 21:03:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline char	*die_strerrno(t_msh_errno errcode)
{
	static char	*strs[] = {
		[MSH_ESUCCESS] = "Success",
		[MSH_EGNL] = "An error occurred while reading stdin via GNL",
	};
	return (strs[errcode]);
}

void __attribute__((noreturn))	die(const char *restrict reason)
{
	const char	*errno_str = die_strerrno(g_msh_errno);

	ft_dprintf(STDERR_FILENO, "GAME OVER: %s: %s\n", reason, errno_str);
	exit((int)g_msh_errno);
}
